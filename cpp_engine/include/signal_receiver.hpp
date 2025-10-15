#ifndef SIGNAL_RECEIVER_HPP
#define SIGNAL_RECEIVER_HPP
#include <functional>
#include <string>
using namespace std;

struct TradeSignal {
    string signal;
    double price;
    int volume;
};

class SignalReceiver {
    public:
    SignalReceiver(int port);
    TradeSignal receiveSignal();

    void listen(function<void(const TradeSignal&)> callback);

    private:
    int sockfd;
    char buffer[1024];
};

#endif // SIGNAL_RECEIVER_HPP