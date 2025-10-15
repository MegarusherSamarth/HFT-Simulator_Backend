#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <cstring>
#include "signal_receiver.hpp"
// #include <argparse/inet.h>
#include <unistd.h>
#include <nlohmann/json.hpp>
#include <functional>
using namespace std;
using json = nlohmann::json;

SignalReceiver::SignalReceiver(int port)
{
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in servaddr{};
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
}

TradeSignal SignalReceiver::receiveSignal()
{
    sockaddr_in cliaddr{};
    socklen_t len = sizeof(cliaddr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);

    json msg = json::parse(buffer);
    TradeSignal ts;
    ts.signal = msg["signal"];
    ts.price = msg["price"];
    ts.volume = msg["volume"];
    return ts;
}

void SignalReceiver::listen(std::function<void(const TradeSignal&)> callback) {
    std::thread([this, callback]() {
        while (true) {
            TradeSignal signal = receiveSignal();
            callback(signal);
        }
    }).detach();
}