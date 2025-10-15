#include <thread>
#include <random>
#include <chrono>
#include "latency_model.hpp"
using namespace std;

LatencyModel::LatencyModel(int minDelayMicros, int maxDelayMicros) : minDelay(minDelayMicros), maxDelay(maxDelayMicros), rng(random_device{}()), dist(minDelayMicros, maxDelayMicros) {}

double LatencyModel::simulate() {
    int delay = dist(rng);
    std::this_thread::sleep_for(chrono::microseconds(delay));
    return static_cast<double>(delay); // return simulated latency
}
