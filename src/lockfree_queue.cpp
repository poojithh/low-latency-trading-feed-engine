// src/lockfree_queue.cpp

#include "../include/lockfree_queue.h"

void LockFreeQueue::push(
    const Trade& trade
) {

    std::lock_guard<std::mutex>
        lock(mutex_);

    queue_.push(trade);
}

bool LockFreeQueue::pop(
    Trade& trade
) {

    std::lock_guard<std::mutex>
        lock(mutex_);

    if (queue_.empty()) {

        return false;
    }

    trade = queue_.front();

    queue_.pop();

    return true;
}