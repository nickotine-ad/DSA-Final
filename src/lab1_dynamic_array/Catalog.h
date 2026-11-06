// ============================================================================
// LAB 1 - Dynamic Array
// The product catalog: a growable array of Product pointers. When the array
// is full its capacity doubles. The catalog OWNS every Product it creates.
// ============================================================================
#pragma once
#include <string>
#include <vector>
#include "common/Product.h"

class Catalog {
public:
    Catalog() = default;
    ~Catalog();
    Catalog(const Catalog&) = delete;
    Catalog& operator=(const Catalog&) = delete;

    // Creates a Product, stores it, and returns a pointer to it.
    Product* add(int id, const std::string& name, const std::string& category,
                 const std::string& brand, double price, int stock);

    int size() const { return n_; }
    Product* at(int i) const { return items_[i]; }
    Product** data() { return items_; }          // raw access for Lab 8 sorting
    std::vector<Product*> all() const;

private:
    Product** items_ = nullptr;
    int n_ = 0, cap_ = 0;
};
