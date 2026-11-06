#include "lab4_stack/UndoStack.h"

Product* UndoStack::pop() {
    if (s_.empty()) return nullptr;
    Product* p = s_.top();
    s_.pop();
    return p;
}

void UndoStack::clear() { while (!s_.empty()) s_.pop(); }
