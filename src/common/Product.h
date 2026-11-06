#pragma once
#include <string>

// Product record managed by the whole system.
struct Product {
    int id;                 // Unique identifier
    std::string name;       // Product title
    std::string category;   // Category (Phone, Laptop, ...)
    std::string brand;      // Official partner brand (Apple, Samsung, ...)
    double price;           // Unit price (PHP)
    int stockQuantity;      // Available inventory level
};
