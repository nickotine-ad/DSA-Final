#include "Menu.h"
#include <iostream>
#include <string>
#include "common/Display.h"
#include "common/Input.h"
#include "lab3_circular_list/BrandShowcase.h"
#include "lab7_searching/Search.h"
#include "lab8_sorting/Sorting.h"
using namespace std;

Menu::Menu() { addSampleProducts(); }

void Menu::addSampleProducts() {
    struct Row { int id; const char *name, *cat, *brand; double price; int stock; };
    const Row rows[] = {
        {105, "iPhone15",   "Phone",   "Apple",    55000, 10},
        {102, "MacBookAir", "Laptop",  "Apple",    62000,  5},
        {110, "GalaxyS24",  "Phone",   "Samsung",  48000,  8},
        {101, "GalaxyTab",  "Tablet",  "Samsung",  38000,  6},
        {104, "SonyXM5",    "Audio",   "Sony",     19000, 15},
        {103, "PS5",        "Console", "Sony",     30000,  3},
        {106, "MXMaster",   "Mouse",   "Logitech",  5500, 25},
        {111, "C920Webcam", "Webcam",  "Logitech",  3500, 30},
    };
    for (const Row& r : rows) {
        Product* p = catalog_.add(r.id, r.name, r.cat, r.brand, r.price, r.stock);  // Lab 1
        index_.insert(p);                                                           // Lab 6
    }
}

void Menu::printMenu() {
    cout << "\n"
            "+------------------------------------+\n"
            "|     TECH STORE INVENTORY SYSTEM    |\n"
            "+------------------------------------+\n"
            "|  1. View catalog                   |\n"
            "|  2. Filter by brand                |\n"
            "|  3. Keyword search                 |\n"
            "|  4. Price range search             |\n"
            "|  5. Add to cart                    |\n"
            "|  6. Checkout                       |\n"
            "|  7. Undo last add                  |\n"
            "|  8. Brand showcase                 |\n"
            "|  9. Sort catalog                   |\n"
            "| 10. Exit                           |\n"
            "+------------------------------------+\n";
}

static void showResults(const vector<Product*>& r, const char* emptyMsg) {
    if (r.empty()) cout << emptyMsg;
    else showList(r);
}

void Menu::run() {
    int choice;
    do {
        printMenu();
        choice = ask<int>("Choice: ");
        switch (choice) {
        case 1:  showCatalog();      break;
        case 2:  filterByBrand();    break;
        case 3:  keywordSearch();    break;
        case 4:  priceRangeSearch(); break;
        case 5:  addToCart();        break;
        case 6:  checkout();         break;
        case 7:  undoLast();         break;
        case 8:  brandShowcase();    break;
        case 9:  sortCatalog();      break;
        case 10: break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 10);
}

void Menu::showCatalog() const { showList(catalog_.all()); }

void Menu::filterByBrand() const {                                    // Lab 7 (linear)
    string b = ask<string>("Brand: ");
    showResults(searchByBrand(catalog_, b), "No products for that brand.\n");
}

void Menu::keywordSearch() const {                                    // Lab 7 (linear)
    string k = ask<string>("Keyword: ");
    showResults(searchByKeyword(catalog_, k), "No match.\n");
}

void Menu::priceRangeSearch() {                                       // Lab 7 (binary)
    double lo = ask<double>("Min price: ");
    double hi = ask<double>("Max price: ");
    showResults(searchByPriceRange(catalog_, lo, hi), "None in range.\n");
}

void Menu::addToCart() {
    Product* p = index_.find(ask<int>("Product ID: "));               // Lab 6
    if (!p)                    { cout << "Not found.\n";    return; }
    if (p->stockQuantity <= 0) { cout << "Out of stock.\n"; return; }

    p->stockQuantity--;
    undo_.push(p);                                                    // Lab 4
    cart_.append(p);                                                  // Lab 2

    cout << "Cart (forward): ";   cart_.printForward(cout);
    cout << "\nCart (backward): "; cart_.printBackward(cout);
    cout << "\n";
}

void Menu::checkout() {
    for (Product* p : cart_.items()) orders_.enqueue(p);              // Lab 5
    cart_.clear();
    undo_.clear();

    if (orders_.empty()) { cout << "Nothing to process.\n"; return; }
    while (!orders_.empty()) {
        Product* p = orders_.dequeue();
        cout << "Processed: " << p->name << "\n";
    }
}

void Menu::undoLast() {
    Product* p = undo_.pop();                                         // Lab 4
    if (!p) { cout << "Nothing to undo.\n"; return; }
    p->stockQuantity++;                                               // give the stock back
    cart_.removeLast();                                               // Lab 2
    cout << "Undone.\n";
}

void Menu::brandShowcase() const {                                    // Lab 3
    BrandShowcase({"Apple", "Samsung", "Sony", "Logitech"}).print(8);
}

void Menu::sortCatalog() {                                            // Lab 8
    int s = ask<int>("1.Price(insertion) 2.Stock(quick) 3.Brand(quick): ");
    if      (s == 1) insertionSort(catalog_, byPrice);
    else if (s == 2) quickSort(catalog_, byStock);
    else if (s == 3) quickSort(catalog_, byBrand);
    showList(catalog_.all());
}
