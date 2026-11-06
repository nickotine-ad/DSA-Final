#include "lab6_bst/ProductTree.h"

ProductTree::~ProductTree() { destroy(root_); }

void ProductTree::insert(Product* p) { root_ = insert(root_, p); }
Product* ProductTree::find(int id) const { return find(root_, id); }

ProductTree::Node* ProductTree::insert(Node* t, Product* p) {
    if (!t) return new Node{p, nullptr, nullptr};
    if (p->id < t->p->id) t->l = insert(t->l, p);
    else                  t->r = insert(t->r, p);
    return t;
}

Product* ProductTree::find(const Node* t, int id) {
    if (!t) return nullptr;
    if (id == t->p->id) return t->p;
    return find(id < t->p->id ? t->l : t->r, id);
}

void ProductTree::destroy(Node* t) {
    if (!t) return;
    destroy(t->l);
    destroy(t->r);
    delete t;
}
