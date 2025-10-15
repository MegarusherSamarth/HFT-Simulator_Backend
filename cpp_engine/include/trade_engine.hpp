#ifndef TRADE_ENGINE_HPP
#define TRADE_ENGINE_HPP
#include "signal_receiver.hpp"
#include "order_book.hpp"
#include <vector>
#include <string>
using namespace std;

struct Trade {
    int buyOrderId;
    int sellOrderID;
    double price;
    int quantity;
    string timestamp;
};

class TradeEngine {
    public:
    TradeEngine();
    
    void processTrade(const Order& buy, const Order& sell);
    const vector<Trade>& getTradeHistory() const;

    void execute(const TradeSignal& signal, const OrderBook& book);
    
    private:
    vector<Trade> tradeHistory;
    string getCurrentTimestamp() const;
};

#endif // TRADE_ENGINE_HPP