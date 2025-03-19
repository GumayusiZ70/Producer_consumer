#include "../inc/Producer.h"
#include <thread>
#include <chrono>

Producer::Producer(TaskQueue &queue) : taskQueue(queue) {}

void Producer::operator()() {
    int item = 0;
    while (taskQueue.push(++item)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // 模拟生产
    }
}
