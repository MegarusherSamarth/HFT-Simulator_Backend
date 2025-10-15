# 📈 High-Frequency Trading Simulator (C++ Backend)

A modular, multi-threaded High-Frequency Trading (HFT) simulator built in C++ for real-time market data ingestion, signal processing, order book management, and trade execution. Designed for scalability, auditability, and future integration with Python-based ML models and GUI frontends.

---

## 🏫 Institution

**Graphic Era Hill University**  
**Academic Year:** 2025–2026  
**Team Members:**  
- Samarth Agarwal (Lead Developer)  
- Rishita Tyagi  
- Srishti Rawat  
- Saijal Rawat

---

## 🚀 Project Goals

- Simulate a real-time HFT system using C++
- Build modular components for market data, signals, order book, and trade execution
- Handle UDP-based input with JSON parsing
- Enable multi-threaded processing for realistic latency and throughput
- Lay the foundation for Python/ML integration in the next phase

---

## 🧱 Architecture Overview

```
+---------------------+       +---------------------+
| MarketDataReceiver  | <---> | OrderBook           |
+---------------------+       +---------------------+
        |                            |
        v                            v
+---------------------+       +---------------------+
| SignalReceiver      | <---> | TradeEngine         |
+---------------------+       +---------------------+
        |                            |
        v                            v
+---------------------+       +---------------------+
| LatencyModel        |       | Trade Logger        |
+---------------------+       +---------------------+
```

---

## 🧠 Modules

### `MarketDataReceiver`
- Listens on UDP port for JSON-formatted market ticks
- Parses data and invokes callback in a background thread

### `SignalReceiver`
- Similar to MarketDataReceiver but handles trade signals
- Converts JSON packets into `TradeSignal` objects
- Triggers trade execution via callback

### `OrderBook`
- Maintains buy/sell orders in price-priority maps
- Matches orders based on price and quantity

### `TradeEngine`
- Executes trades between matched orders
- Logs trade details including timestamp, price, and quantity

### `LatencyModel`
- Simulates delay using `std::this_thread::sleep_for`
- Uses randomized latency for realism

---

## 🛠️ Technologies Used

- **Language:** C++
- **Build System:** CMake
- **Compiler:** MinGW 15.2.0
- **Networking:** Winsock2 (UDP)
- **JSON Parsing:** [nlohmann/json](https://github.com/nlohmann/json)
- **Threading:** `std::thread`, `std::function`

---

## 📁 Folder Structure

```
cpp_engine/
├── include/
│   ├── market_data.hpp
│   ├── signal_receiver.hpp
│   ├── order_book.hpp
│   ├── trade_engine.hpp
│   ├── latency_model.hpp
├── src/
│   ├── main.cpp
│   ├── market_data.cpp
│   ├── signal_receiver.cpp
│   ├── order_book.cpp
│   ├── trade_engine.cpp
│   ├── latency_model.cpp
├── build/
├── CMakeLists.txt
```

---

## 🧪 How to Build

### Prerequisites
- MinGW 15.2.0
- CMake 3.25+
- Windows OS

### Build Steps

```bash
cd cpp_engine/build
cmake ..
cmake --build .
```

### Run the Simulator

```bash
./hft_simulator.exe
```

---

## 🧪 Sample JSON Packets

### MarketTick

```json
{
  "timestamp": "2025-10-16T03:45:00Z",
  "symbol": "INFY",
  "price": 1560.25,
  "volume": 100
}
```

### TradeSignal

```json
{
  "signal": "BUY",
  "price": 1560.25,
  "volume": 100
}
```

---

## 🧠 Challenges Overcome

- Linker errors due to missing implementations
- Threading setup with detached listeners
- UDP socket configuration and binding
- JSON parse crashes from malformed input
- Toolchain setup with MinGW and CMake
- Designing modular interfaces across classes
- Buffer reuse and memory safety
- Debugging runtime crashes with malformed packets

---

## 📈 Future Work

- Python UDP senders for MarketTick and TradeSignal
- ML model integration for signal generation
- GUI or CSV-based trade visualization
- Shutdown hooks and thread lifecycle management
- Performance benchmarking and optimization

---

## 📜 License

This project is for academic and research purposes under the supervision of Graphic Era Hill University. For external use or commercial deployment, please contact the team.
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

## 🙌 Acknowledgments

Special thanks to:
- Graphic Era Hill University faculty
- Open-source contributors to CMake, MinGW, and nlohmann/json
- The developer community for documentation and support

---

## 📬 Contact

For questions, collaboration, or feedback:

**Lead Developer:** Samarth Agarwal  
**GitHub:** github.com/MegarusherSamarth  

