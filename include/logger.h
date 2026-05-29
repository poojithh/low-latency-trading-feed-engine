// include/logger.h

#pragma once

#include <string>

void initialize_logger(
    const std::string& filename
);

void log_trade(
    int order_id,
    double price,
    double quantity
);