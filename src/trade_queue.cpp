#include "../include/trade_queue.h"

void TradeQueue::push(
    Trade trade
) {

    std::lock_guard<std::mutex>
        lock(mutex_);

    queue_.push(trade);
}

bool TradeQueue::pop(
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

bool TradeQueue::empty() {

    std::lock_guard<std::mutex>
        lock(mutex_);

    return queue_.empty();
}
