#include "lab1_dynamic_array/Catalog.h"

Catalog::~Catalog() {
    for (int i = 0; i < n_; i++) delete items_[i];   // free every product
    delete[] items_;                                 // free the array itself
}

Product* Catalog::add(int id, const std::string& name, const std::string& category,
                      const std::string& brand, double price, int stock) {
    if (n_ == cap_) {                                // full -> double the array
        cap_ = cap_ ? cap_ * 2 : 4;
        Product** bigger = new Product*[cap_];
        for (int i = 0; i < n_; i++) bigger[i] = items_[i];
        delete[] items_;
        items_ = bigger;
    }
    items_[n_] = new Product{id, name, category, brand, price, stock};
    return items_[n_++];
}

std::vector<Product*> Catalog::all() const {
    return std::vector<Product*>(items_, items_ + n_);
}
