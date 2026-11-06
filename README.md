# Brand-Affiliated E-Commerce Inventory & Search Engine

**Course:** Data Structures and Algorithm Analysis - Final Output (BS Computer Engineering)
**Language:** C++17  |  **Interface:** Interactive console

## 1. Overview

A console-based inventory system for a **Tech & Electronics** store. It manages a
multi-brand product catalog, lets a buyer filter and search by brand, build a cart,
undo actions and check out through an order queue. Every data structure and algorithm
from **Labs 1-8** is implemented by hand and used by a real feature of the program.

**Partner brands:** Apple, Samsung, Sony, Logitech

### Product model

```cpp
struct Product {
    int id;               // Unique identifier
    string name;          // Product title
    string category;      // Category (Phone, Laptop, ...)
    string brand;         // Official partner brand
    double price;         // Unit price
    int stockQuantity;    // Available inventory level
};
```

## 2. Lab integration (Labs 1-8)

Each lab lives in its own folder under `src/`.

| Lab | Topic | Folder | Used for | Complexity |
|-----|-------|--------|----------|------------|
| 1 | Dynamic array | `lab1_dynamic_array/` | Product catalog; capacity doubles when full | add: O(1) amortized |
| 2 | Doubly linked list | `lab2_doubly_linked_list/` | Shopping cart, shown forward and backward | append / remove last: O(1) |
| 3 | Circular linked list | `lab3_circular_list/` | Brand showcase carousel | traverse: O(n) |
| 4 | Stack (LIFO) | `lab4_stack/` | Undo history for "add to cart" | push / pop: O(1) |
| 5 | Queue (FIFO) | `lab5_queue/` | Checkout order processing | enqueue / dequeue: O(1) |
| 6 | Binary search tree | `lab6_bst/` | Product lookup by ID | avg O(log n), worst O(n) |
| 7 | Searching | `lab7_searching/` | Brand filter, keyword (linear); price range (binary) | O(n) / O(log n) |
| 8 | Sorting | `lab8_sorting/` | Insertion sort (price), quick sort (stock, brand) | O(n^2) / avg O(n log n) |

`src/common/` holds the shared `Product` struct, safe input helper and display functions.
`src/Menu.cpp` connects all labs into the application; `src/main.cpp` only starts it.

## 3. Menu

| # | Option | Lab(s) |
|---|--------|--------|
| 1 | Show full catalog | 1 |
| 2 | Filter by brand | 7 |
| 3 | Keyword search (name or brand) | 7 |
| 4 | Price range search | 7 + 8 |
| 5 | Add to cart (reduces stock) | 6, 2, 4 |
| 6 | Checkout (processes cart through the queue) | 5, 2 |
| 7 | Undo last add (restores stock) | 4, 2 |
| 8 | Brand showcase (circular walk) | 3 |
| 9 | Sort catalog (price / stock / brand) | 8 |
| 10 | Exit | - |

## 4. Build and run

**Linux / macOS / MSYS2:**
```
make
./build/inventory
```

**Windows PowerShell (no make):**
```
g++ -std=c++17 -Isrc (Get-ChildItem -Recurse src -Filter *.cpp).FullName -o inventory.exe
.\inventory.exe
```

## 5. Memory management and safety

- Every structure is a class that frees its own nodes in its destructor (RAII), so
  nothing needs manual cleanup in `main`.
  - `Catalog` deletes every `Product` and the array.
  - `Cart` and `ProductTree` delete every node.
  - `BrandShowcase` opens its circle before freeing, so no node is freed twice.
- The BST and the cart only *point to* products; the catalog is the single owner.
- Copying is disabled on all structures, which prevents double frees.
- The program was built with AddressSanitizer + UndefinedBehaviorSanitizer and run through
  every menu option with no errors or leaks reported.

**Edge cases handled**

- Non-numeric input is rejected and re-prompted; end of input exits cleanly.
- Unknown product ID, and adding an out-of-stock item.
- Undo or checkout with an empty cart.
- Searches with no results, and price range with no matches.
- Invalid menu choice or invalid sort option.

## 6. Project structure

```
inventory-system/
├── src/
│   ├── common/                    Product.h, Input.h, Display
│   ├── lab1_dynamic_array/        Catalog
│   ├── lab2_doubly_linked_list/   Cart
│   ├── lab3_circular_list/        BrandShowcase
│   ├── lab4_stack/                UndoStack
│   ├── lab5_queue/                OrderQueue
│   ├── lab6_bst/                  ProductTree
│   ├── lab7_searching/            Search
│   ├── lab8_sorting/              Sorting
│   ├── Menu.h / Menu.cpp
│   └── main.cpp
├── Makefile
└── README.md
```

## 7. Sample run

```
Choice: 5
Product ID: 105
Cart (forward): iPhone15
Cart (backward): iPhone15
Choice: 5
Product ID: 104
Cart (forward): iPhone15 SonyXM5
Cart (backward): SonyXM5 iPhone15
Choice: 6
Processed: iPhone15
Processed: SonyXM5
```
