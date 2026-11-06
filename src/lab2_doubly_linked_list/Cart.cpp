#include "lab2_doubly_linked_list/Cart.h"
#include <iostream>

Cart::~Cart() { clear(); }

void Cart::append(Product* p) {
    Node* nd = new Node{p, tail_, nullptr};
    if (tail_) tail_->next = nd; else head_ = nd;
    tail_ = nd;
}

bool Cart::removeLast() {
    if (!tail_) return false;
    Node* c = tail_;
    tail_ = c->prev;
    if (tail_) tail_->next = nullptr; else head_ = nullptr;
    delete c;
    return true;
}

void Cart::clear() { while (removeLast()) {} }

std::vector<Product*> Cart::items() const {
    std::vector<Product*> out;
    for (Node* x = head_; x; x = x->next) out.push_back(x->p);
    return out;
}

void Cart::printForward(std::ostream& os) const {
    for (Node* x = head_; x; x = x->next) os << x->p->name << " ";
}

void Cart::printBackward(std::ostream& os) const {
    for (Node* x = tail_; x; x = x->prev) os << x->p->name << " ";
}
