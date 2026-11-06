#pragma once
#include <vector>
#include "common/Product.h"

// Console printing helpers shared by every menu option.
void show(const Product* p);
void showList(const std::vector<Product*>& list);
