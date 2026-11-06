// ============================================================================
// LAB 5 - Queue (FIFO)
// Checkout order queue: items are processed in the same order they were
// added to the cart (first in, first out).
// ============================================================================
#pragma once
#include <queue>
#include "common/Product.h"

class OrderQueue {
public:
    void enqueue(Product* p) { q_.push(p); }
    Product* dequeue();                          // nullptr if empty
    bool empty() const { return q_.empty(); }

private:
    std::queue<Product*> q_;
};
