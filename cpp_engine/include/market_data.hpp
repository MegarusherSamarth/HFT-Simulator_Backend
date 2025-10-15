#ifndef MARKET_DATA_HPP
#define MARKET_DATA_HPP
#include <functional>
#include <string>
using namespace std;

struct MarketTick {
    string timestamp;
    string symbol;
    double price;
    double volume;
};

class MarketDataReceiver {
    public:
    MarketDataReceiver(int port);
    MarketTick receiveTick();

    void listen(function<void(const MarketTick&)> callback);

    private:
    int sockfd;
    char buffer[1024];
};

#endif // MARKET_DATA_HPP