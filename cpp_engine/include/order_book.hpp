#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP
#include "market_data.hpp"
#include <map>
#include <vector>
#include <string>
#include <functional>
using namespace std;

enum class OrderType { BUY, SELL };

struct Order {
    int id;
    OrderType type;
    double price;
    int quantity;
};

class OrderBook {
    public:
    OrderBook();

    void addOrder(const Order& order);
    void cancelOrder(int orderId);
    void matchOrders();

    vector<Order> getBuyOrders() const;
    vector<Order> getSellOrders() const;

    void update(const MarketTick& tick);

    private:
    map<double, vector<Order>, greater<double>> buyOrders; // Highest Price First
    map<double, vector<Order>> sellOrders; // Lowest Price First
    map<int, Order> orderLookup;

    void executeTrade(const Order& buy, const Order& sell);
};

#endif // ORDER_BOOK_HPP