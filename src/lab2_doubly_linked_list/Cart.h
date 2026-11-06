// ============================================================================
// LAB 2 - Doubly Linked List
// The shopping cart. Each node links to both its previous and next node, so
// the cart can be traversed forward (oldest -> newest) and backward.
// ============================================================================
#pragma once
#include <iosfwd>
#include <vector>
#include "common/Product.h"

class Cart {
public:
    Cart() = default;
    ~Cart();
    Cart(const Cart&) = delete;
    Cart& operator=(const Cart&) = delete;

    void append(Product* p);                     // insert at tail
    bool removeLast();                           // delete tail; false if empty
    void clear();                                // delete every node
    bool empty() const { return tail_ == nullptr; }

    std::vector<Product*> items() const;         // head -> tail
    void printForward(std::ostream& os) const;
    void printBackward(std::ostream& os) const;

private:
    struct Node { Product* p; Node *prev, *next; };
    Node *head_ = nullptr, *tail_ = nullptr;
};
