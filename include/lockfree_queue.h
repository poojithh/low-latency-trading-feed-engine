// include/lockfree_queue.h

#pragma once

#include <queue>
#include <mutex>

#include "order.h"

class LockFreeQueue {

private:

    std::queue<Trade> queue_;

    std::mutex mutex_;

public:

    void push(const Trade& trade);

    bool pop(Trade& trade);
};