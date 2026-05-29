#include "../include/lockfree_queue.h"

LockFreeQueue::LockFreeQueue()
    : head(0),
      tail(0) {}

bool LockFreeQueue::push(
    const Trade& trade
) {

    int current_tail =
        tail.load(std::memory_order_relaxed);

    int next_tail =
        (current_tail + 1) % SIZE;

    if (next_tail ==
        head.load(std::memory_order_acquire)) {

        return false;
    }

    buffer[current_tail] = trade;

    tail.store(
        next_tail,
        std::memory_order_release
    );

    return true;
}

bool LockFreeQueue::pop(
    Trade& trade
) {

    int current_head =
        head.load(std::memory_order_relaxed);

    if (current_head ==
        tail.load(std::memory_order_acquire)) {

        return false;
    }

    trade = buffer[current_head];

    head.store(
        (current_head + 1) % SIZE,
        std::memory_order_release
    );

    return true;
}
