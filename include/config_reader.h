#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <string>

struct Config {

    std::string mode;

    std::string symbol;

    int thread_count;
};

Config load_config(
    const std::string& filename
);

#endif