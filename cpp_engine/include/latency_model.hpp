#ifndef LATENCY_MODEL_HPP
#define LATENCY_MODEL_HPP

#include <random>
#include <chrono>
using namespace std;

class LatencyModel {
    public: 
    LatencyModel(int minDelayMicros, int maxDelayMicros);
    void simulateDelay();

    double simulate();

    private:
    int minDelay;
    int maxDelay;
    mt19937 rng;
    uniform_int_distribution<int> dist;
};

#endif // LATENCY_MODEL_HPP
