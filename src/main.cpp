// src/main.cpp

#include <iostream>
#include <thread>
#include <random>
#include <chrono>
#include <atomic>

#include "../include/config_reader.h"
#include "../include/logger.h"
#include "../include/lockfree_queue.h"
#include "../include/matching_engine.h"
#include "../include/order.h"

LockFreeQueue trade_queue;

MatchingEngine matching_engine;

bool producer_done = false;

std::atomic<long long> total_latency_microseconds(0);

std::atomic<int> processed_trades(0);

void producer() {

    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_real_distribution<>
        price_dist(43000, 44000);

    std::uniform_real_distribution<>
        qty_dist(0.01, 1.0);

    for (int i = 1; i <= 100; i++) {

        Trade trade;

        trade.order_id = i;

        trade.price =
            price_dist(gen);

        trade.quantity =
            qty_dist(gen);

        trade_queue.push(trade);

        Order order;

        order.order_id = i;

        order.price = trade.price;

        order.quantity = trade.quantity;

        if (i % 2 == 0) {

            order.type =
                OrderType::BUY;
        }

        else {

            order.type =
                OrderType::SELL;
        }

        matching_engine.process_order(order);

        std::cout
            << "[PRODUCER] Generated Trade "
            << i
            << std::endl;

        std::this_thread::sleep_for(
            std::chrono::milliseconds(20)
        );
    }

    producer_done = true;
}

void consumer() {

    while (!producer_done) {

        Trade trade;

        if (trade_queue.pop(trade)) {

            auto start =
                std::chrono::high_resolution_clock::now();

            log_trade(
                trade.order_id,
                trade.price,
                trade.quantity
            );

            auto end =
                std::chrono::high_resolution_clock::now();

            auto latency =
                std::chrono::duration_cast<
                    std::chrono::microseconds
                >(end - start).count();

            total_latency_microseconds += latency;

            processed_trades++;

            std::cout
                << "[CONSUMER] Logged Trade "
                << trade.order_id
                << " | Latency: "
                << latency
                << " us"
                << std::endl;
        }

        std::this_thread::sleep_for(
            std::chrono::milliseconds(5)
        );
    }

    while (true) {

        Trade trade;

        if (!trade_queue.pop(trade)) {

            break;
        }

        log_trade(
            trade.order_id,
            trade.price,
            trade.quantity
        );

        std::cout
            << "[CONSUMER] Logged Remaining Trade "
            << trade.order_id
            << std::endl;
    }
}

int main() {

    Config config =
        load_config("../config/config.json");

    initialize_logger(
        "../logs/trades.csv"
    );

    std::cout
        << "=================================="
        << std::endl;

    std::cout
        << " LOW LATENCY TRADING ENGINE"
        << std::endl;

    std::cout
        << "=================================="
        << std::endl;

    std::cout
        << "Starting producer-consumer engine..."
        << std::endl;

    std::thread producer_thread(
        producer
    );

    std::thread consumer_thread(
        consumer
    );

    producer_thread.join();

    consumer_thread.join();

    std::cout
        << "All trades processed."
        << std::endl;

    double average_latency = 0;

    if (processed_trades > 0) {

        average_latency =
            static_cast<double>(
                total_latency_microseconds
            ) / processed_trades;
    }

    std::cout
        << "=================================="
        << std::endl;

    std::cout
        << "PERFORMANCE METRICS"
        << std::endl;

    std::cout
        << "=================================="
        << std::endl;

    std::cout
        << "Trades Processed: "
        << processed_trades
        << std::endl;

    std::cout
        << "Average Latency: "
        << average_latency
        << " microseconds"
        << std::endl;

    return 0;
}
