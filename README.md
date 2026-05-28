# Low Latency Trading Feed Engine

A high-performance C++ trading engine that simulates low-latency market data processing using multithreading, lock-free queues, order matching, CSV trade logging, and Python-based visualization.

---

# Features

* Multithreaded producer-consumer architecture
* Lock-free ring buffer queue using atomic operations
* Simulated market trade generation
* Buy/Sell order matching engine
* CSV trade logging
* Python trade visualization
* Microsecond-level latency benchmarking
* JSON configuration support

---

# Tech Stack

## C++

* C++17
* Multithreading
* Atomic operations
* Lock-free data structures
* CMake build system

## Python

* pandas
* matplotlib

---

# Project Structure

```bash
low-latency-trading-feed-engine/
│
├── build/
├── config/
│   └── config.json
│
├── include/
│   ├── config_reader.h
│   ├── lockfree_queue.h
│   ├── logger.h
│   ├── matching_engine.h
│   ├── order.h
│   └── trade.h
│
├── logs/
│   ├── trades.csv
│   └── trade_plot.png
│
├── scripts/
│   └── visualize.py
│
├── src/
│   ├── config_reader.cpp
│   ├── lockfree_queue.cpp
│   ├── logger.cpp
│   ├── main.cpp
│   └── matching_engine.cpp
│
├── CMakeLists.txt
└── README.md
```

---

# Build Instructions

## Clone Repository

```bash
git clone <your-repo-url>
cd low-latency-trading-feed-engine
```

---

## Build Project

```bash
mkdir build
cd build

cmake ..
cmake --build .
```

---

## Run Trading Engine

```bash
./trading_engine
```

---

# Example Output

```bash
[PRODUCER] Generated Trade 1
[BOOK] Added SELL order
[CONSUMER] Logged Trade 1 | Latency: 5 us

==================================
PERFORMANCE METRICS
==================================
Trades Processed: 100
Average Latency: 8 microseconds
```

---

# Python Visualization

Run visualization script:

```bash
cd scripts
python visualize.py
```

This generates:

```bash
logs/trade_plot.png
```

---

# Performance Features

* Lock-free queue implementation
* Concurrent producer-consumer pipeline
* Atomic latency tracking
* Microsecond-level benchmarking
* Multithreaded order processing

---

# Future Improvements

* Real Binance WebSocket integration
* Live market feed processing
* FIX protocol support
* Advanced order-book matching
* Persistent database storage
* Real-time dashboard

---
