cmake_minimum_required(VERSION 3.10)

project(LowLatencyTradingEngine)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    trading_engine

    src/main.cpp
    src/logger.cpp
    src/matching_engine.cpp
    src/websocket_client.cpp
    src/lockfree_queue.cpp
    src/config_reader.cpp
)
