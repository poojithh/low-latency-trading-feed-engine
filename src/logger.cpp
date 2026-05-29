#include "../include/logger.h"

#include <fstream>
#include <chrono>

std::ofstream log_file;

void initialize_logger(
    const std::string& filename
) {

    log_file.open(filename);

    log_file
        << "timestamp,order_id,price,quantity\n";
}

void log_trade(
    int order_id,
    double price,
    double quantity
) {

    auto now =
        std::chrono::system_clock::now();

    auto timestamp =
        std::chrono::duration_cast<
            std::chrono::milliseconds
        >(
            now.time_since_epoch()
        ).count();

    log_file
        << timestamp << ","
        << order_id << ","
        << price << ","
        << quantity << "\n";
}
