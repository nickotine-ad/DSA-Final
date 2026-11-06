#include "lab3_circular_list/BrandShowcase.h"
#include <iostream>

BrandShowcase::BrandShowcase(const std::vector<std::string>& brands) {
    Node* tail = nullptr;
    for (const std::string& b : brands) {
        Node* nb = new Node{b, nullptr};
        if (tail) tail->next = nb; else head_ = nb;
        tail = nb;
    }
    if (tail) tail->next = head_;                // close the circle
}

BrandShowcase::~BrandShowcase() {
    if (!head_) return;
    Node* tail = head_;                          // find the last node...
    while (tail->next != head_) tail = tail->next;
    tail->next = nullptr;                        // ...open the circle, then free
    while (head_) { Node* d = head_; head_ = head_->next; delete d; }
}

void BrandShowcase::print(int steps) const {
    Node* cur = head_;
    for (int i = 0; i < steps && cur; i++) {
        std::cout << cur->brand << " -> ";
        cur = cur->next;
    }
    std::cout << "...\n";
}
