#ifndef ORDER_H
#define ORDER_H

enum class OrderType {

    BUY,
    SELL
};

struct Order {

    int order_id;

    double price;

    double quantity;

    OrderType type;
};

struct Trade {

    int order_id;

    double price;

    double quantity;
};

#endif