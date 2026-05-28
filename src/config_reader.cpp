#include "../include/config_reader.h"

#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

Config load_config(const std::string& filename) {

    std::ifstream file(filename);

    json j;
    file >> j;

    Config config;

    config.mode = j["mode"];
    config.symbol = j["symbol"];
    config.csv_log_file = j["csv_log_file"];

    config.max_log_size_mb = j["max_log_size_mb"];
    config.thread_count = j["thread_count"];
    config.order_rate_per_second = j["order_rate_per_second"];

    return config;
}
