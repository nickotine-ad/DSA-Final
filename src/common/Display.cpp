#include "common/Display.h"
#include <iomanip>
#include <iostream>

// Column widths (characters) for the product table.
static const int W_ID = 5, W_NAME = 12, W_CAT = 10, W_BRAND = 10, W_PRICE = 11, W_STOCK = 6;

static void line() {
    std::cout << "+" << std::string(W_ID + 2, '-')
              << "+" << std::string(W_NAME + 2, '-')
              << "+" << std::string(W_CAT + 2, '-')
              << "+" << std::string(W_BRAND + 2, '-')
              << "+" << std::string(W_PRICE + 2, '-')
              << "+" << std::string(W_STOCK + 2, '-') << "+\n";
}

static void header() {
    line();
    std::cout << std::left
              << "| " << std::setw(W_ID)    << "ID"
              << " | " << std::setw(W_NAME)  << "Name"
              << " | " << std::setw(W_CAT)   << "Category"
              << " | " << std::setw(W_BRAND) << "Brand"
              << " | " << std::setw(W_PRICE) << "Price"
              << " | " << std::setw(W_STOCK) << "Stock" << " |\n";
    line();
}

// One table row.
void show(const Product* p) {
    std::ios::fmtflags saved = std::cout.flags();
    std::streamsize savedPrec = std::cout.precision();

    std::cout << std::left
              << "| " << std::setw(W_ID)    << p->id
              << " | " << std::setw(W_NAME)  << p->name
              << " | " << std::setw(W_CAT)   << p->category
              << " | " << std::setw(W_BRAND) << p->brand
              << " | " << std::right << std::fixed << std::setprecision(2)
              << std::setw(W_PRICE) << p->price
              << " | " << std::setw(W_STOCK) << p->stockQuantity << " |\n";

    std::cout.flags(saved);
    std::cout.precision(savedPrec);
}

// Full table: header, every row, closing line.
void showList(const std::vector<Product*>& list) {
    header();
    for (const Product* p : list) show(p);
    line();
}