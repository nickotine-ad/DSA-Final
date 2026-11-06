// ============================================================================
// LAB 3 - Circular Linked List
// Brand showcase carousel: the last brand points back to the first, so the
// list can be walked around and around without ever hitting nullptr.
// ============================================================================
#pragma once
#include <string>
#include <vector>

class BrandShowcase {
public:
    explicit BrandShowcase(const std::vector<std::string>& brands);
    ~BrandShowcase();
    BrandShowcase(const BrandShowcase&) = delete;
    BrandShowcase& operator=(const BrandShowcase&) = delete;

    void print(int steps) const;                 // walk `steps` nodes around the circle

private:
    struct Node { std::string brand; Node* next; };
    Node* head_ = nullptr;
};
