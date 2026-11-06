#include "lab8_sorting/Sorting.h"
#include <utility>

bool byPrice(const Product* a, const Product* b) { return a->price < b->price; }
bool byStock(const Product* a, const Product* b) { return a->stockQuantity < b->stockQuantity; }
bool byBrand(const Product* a, const Product* b) { return a->brand < b->brand; }

void insertionSort(Catalog& c, Less lt) {
    Product** a = c.data();
    for (int i = 1; i < c.size(); i++) {
        Product* key = a[i];
        int j = i - 1;
        while (j >= 0 && lt(key, a[j])) { a[j + 1] = a[j]; j--; }
        a[j + 1] = key;
    }
}

static void quickSortRange(Product** a, int lo, int hi, Less lt) {
    if (lo >= hi) return;
    Product* pivot = a[hi];
    int i = lo;
    for (int j = lo; j < hi; j++)
        if (lt(a[j], pivot)) std::swap(a[i++], a[j]);
    std::swap(a[i], a[hi]);
    quickSortRange(a, lo, i - 1, lt);
    quickSortRange(a, i + 1, hi, lt);
}

void quickSort(Catalog& c, Less lt) { quickSortRange(c.data(), 0, c.size() - 1, lt); }
