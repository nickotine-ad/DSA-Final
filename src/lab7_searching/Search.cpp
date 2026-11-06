#include "lab7_searching/Search.h"
#include "lab8_sorting/Sorting.h"

std::vector<Product*> searchByBrand(const Catalog& c, const std::string& brand) {
    std::vector<Product*> out;
    for (int i = 0; i < c.size(); i++)
        if (c.at(i)->brand == brand) out.push_back(c.at(i));
    return out;
}

std::vector<Product*> searchByKeyword(const Catalog& c, const std::string& k) {
    std::vector<Product*> out;
    for (int i = 0; i < c.size(); i++) {
        Product* p = c.at(i);
        if (p->name.find(k) != std::string::npos || p->brand.find(k) != std::string::npos)
            out.push_back(p);
    }
    return out;
}

std::vector<Product*> searchByPriceRange(Catalog& c, double lo, double hi) {
    insertionSort(c, byPrice);

    int l = 0, h = c.size();                     // binary search: first price >= lo
    while (l < h) {
        int m = (l + h) / 2;
        if (c.at(m)->price < lo) l = m + 1; else h = m;
    }

    std::vector<Product*> out;                   // collect until price > hi
    for (; l < c.size() && c.at(l)->price <= hi; l++) out.push_back(c.at(l));
    return out;
}
