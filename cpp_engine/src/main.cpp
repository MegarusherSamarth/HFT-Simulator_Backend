#define _NO_CRT_STDIO_INLINE 1
#define NOMINMAX
#define byte win_byte_override  // Rename Windows byte to avoid conflict
#include <iostream>
#include <chrono>
#include <windows.h>
#undef byte
#include "order_book.hpp"
#include "trade_engine.hpp"
#include "latency_model.hpp"
#include "market_data.hpp"
#include "signal_receiver.hpp"
#include <thread>
using namespace std;

int main(){
    cout << "Starting HFT Simulator..." << endl;

    // Initializing Core Components
    OrderBook orderBook;
    TradeEngine tradeEngine;
    LatencyModel latencyModel(100, 500);     // 100-500 microseconds delay
    MarketDataReceiver marketReceiver(9000); // UDP port for market data
    SignalReceiver signalReceiver(9001);     // UDP port for trade signals

    // Start UDP listeners in separate threads
    std::thread marketThread([&](){ 
        marketReceiver.listen([&](const MarketTick &tick){ 
            orderBook.update(tick); 
        }); 
    }); // Semicolon required after lambda and thread declaration

    std::thread signalThread([&](){ 
        signalReceiver.listen([&](const TradeSignal &signal){
            double latency = latencyModel.simulate();
            std::this_thread::sleep_for(chrono::microseconds(static_cast<int>(latency)));
            tradeEngine.execute(signal, orderBook); 
        }); 
    }); // Semicolon required after lambda and thread declaration

    // Main loop (optional monitoring)
    for (int i = 0; i < 100; ++i){
        cout << "Tick " << i << " processed." << endl;
        std::this_thread::sleep_for(chrono::milliseconds(100));
    }

    // Join threads before exiting
    marketThread.join();
    signalThread.join();

    cout << "Simulation complete. Trade log saved." << endl;
    return 0;
}