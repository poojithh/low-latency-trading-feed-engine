// src/config_reader.cpp

#include "../include/config_reader.h"

#include <fstream>
#include <iostream>

Config load_config(
    const std::string& filename
) {

    Config config;

    config.mode = "simulation";

    config.symbol = "BTCUSDT";

    config.thread_count = 2;

    return config;
}