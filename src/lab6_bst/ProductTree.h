// ============================================================================
// LAB 6 - Binary Search Tree
// Index of products keyed by id, for fast lookup when adding to the cart.
// The tree only stores pointers; the Catalog (Lab 1) owns the Products.
// ============================================================================
#pragma once
#include "common/Product.h"

class ProductTree {
public:
    ProductTree() = default;
    ~ProductTree();
    ProductTree(const ProductTree&) = delete;
    ProductTree& operator=(const ProductTree&) = delete;

    void insert(Product* p);
    Product* find(int id) const;                 // nullptr if not found

private:
    struct Node { Product* p; Node *l, *r; };
    Node* root_ = nullptr;

    static Node* insert(Node* t, Product* p);
    static Product* find(const Node* t, int id);
    static void destroy(Node* t);                // post-order delete
};
