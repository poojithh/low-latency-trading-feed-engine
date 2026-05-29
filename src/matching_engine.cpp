// src/matching_engine.cpp

#include "../include/matching_engine.h"

#include <iostream>

void MatchingEngine::process_order(
    const Order& order
) {

    if (order.type ==
        OrderType::BUY) {

        std::cout
            << "[BOOK] Added BUY order"
            << std::endl;

        buy_orders.push_back(order);
    }

    else {

        std::cout
            << "[BOOK] Added SELL order"
            << std::endl;

        sell_orders.push_back(order);
    }

    if (!buy_orders.empty()
        && !sell_orders.empty()) {

        Order buy =
            buy_orders.back();

        Order sell =
            sell_orders.back();

        buy_orders.pop_back();

        sell_orders.pop_back();

        std::cout
            << "[MATCHED] BUY "
            << buy.quantity
            << " @ "
            << sell.price
            << std::endl;
    }
}