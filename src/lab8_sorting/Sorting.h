// ============================================================================
// LAB 8 - Sorting
//   Insertion sort : O(n^2), simple, good for small / nearly sorted data
//   Quick sort     : O(n log n) average
// Both take a comparator so one algorithm can sort by price, stock or brand.
// ============================================================================
#pragma once
#include "lab1_dynamic_array/Catalog.h"

typedef bool (*Less)(const Product*, const Product*);

bool byPrice(const Product* a, const Product* b);
bool byStock(const Product* a, const Product* b);
bool byBrand(const Product* a, const Product* b);

void insertionSort(Catalog& c, Less lt);
void quickSort(Catalog& c, Less lt);
