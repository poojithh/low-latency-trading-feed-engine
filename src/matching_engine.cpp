#include "../include/matching_engine.h"

#include <iostream>

void MatchingEngine::process_order(
    const Order& order
) {

    if (order.type ==
        OrderType::BUY) {

        for (auto it = sell_orders.begin();
             it != sell_orders.end();
             ++it) {

            if (order.price >= it->price) {

                std::cout
                    << "[MATCHED] BUY "
                    << order.quantity
                    << " @ "
                    << it->price
                    << std::endl;

                sell_orders.erase(it);

                return;
            }
        }

        buy_orders.push_back(order);

        std::cout
            << "[BOOK] Added BUY order"
            << std::endl;
    }

    else {

        for (auto it = buy_orders.begin();
             it != buy_orders.end();
             ++it) {

            if (order.price <= it->price) {

                std::cout
                    << "[MATCHED] SELL "
                    << order.quantity
                    << " @ "
                    << it->price
                    << std::endl;

                buy_orders.erase(it);

                return;
            }
        }

        sell_orders.push_back(order);

        std::cout
            << "[BOOK] Added SELL order"
            << std::endl;
    }
}
