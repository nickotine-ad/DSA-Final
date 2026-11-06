#include "lab5_queue/OrderQueue.h"

Product* OrderQueue::dequeue() {
    if (q_.empty()) return nullptr;
    Product* p = q_.front();
    q_.pop();
    return p;
}
