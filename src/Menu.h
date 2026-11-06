// ============================================================================
// Menu - console UI that ties Labs 1-8 together into one application.
// ============================================================================
#pragma once
#include "lab1_dynamic_array/Catalog.h"
#include "lab2_doubly_linked_list/Cart.h"
#include "lab4_stack/UndoStack.h"
#include "lab5_queue/OrderQueue.h"
#include "lab6_bst/ProductTree.h"

class Menu {
public:
    Menu();
    void run();

private:
    Catalog    catalog_;     // Lab 1
    Cart       cart_;        // Lab 2
    UndoStack  undo_;        // Lab 4
    OrderQueue orders_;      // Lab 5
    ProductTree index_;      // Lab 6

    void addSampleProducts();
    static void printMenu();

    void showCatalog() const;
    void filterByBrand() const;
    void keywordSearch() const;
    void priceRangeSearch();
    void addToCart();
    void checkout();
    void undoLast();
    void brandShowcase() const;
    void sortCatalog();
};
