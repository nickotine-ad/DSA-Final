// ============================================================================
// LAB 4 - Stack (LIFO)
// Undo history: every "add to cart" is pushed; undo pops the most recent one.
// ============================================================================
#pragma once
#include <stack>
#include "common/Product.h"

class UndoStack {
public:
    void push(Product* p) { s_.push(p); }
    Product* pop();                              // nullptr if empty
    bool empty() const { return s_.empty(); }
    void clear();

private:
    std::stack<Product*> s_;
};
