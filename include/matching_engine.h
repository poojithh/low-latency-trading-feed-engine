// include/matching_engine.h

#pragma once

#include <vector>

#include "order.h"

class MatchingEngine {

private:

    std::vector<Order> buy_orders;

    std::vector<Order> sell_orders;

public:

    void process_order(
        const Order& order
    );
};