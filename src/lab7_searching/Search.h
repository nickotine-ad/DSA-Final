// ============================================================================
// LAB 7 - Searching
//   Linear search : brand filter, keyword search   O(n)
//   Binary search : price range                    O(log n) after sorting
// ============================================================================
#pragma once
#include <string>
#include <vector>
#include "lab1_dynamic_array/Catalog.h"

std::vector<Product*> searchByBrand(const Catalog& c, const std::string& brand);
std::vector<Product*> searchByKeyword(const Catalog& c, const std::string& keyword);

// Sorts the catalog by price first (binary search needs sorted data).
std::vector<Product*> searchByPriceRange(Catalog& c, double lo, double hi);
