#include "../inc/Consumer.h"
#include <thread>
#include <chrono>

Consumer::Consumer(TaskQueue &queue) : taskQueue(queue) {}

void Consumer::operator()() {
    int item;
    while (taskQueue.pop(item)) {
        std::this_thread::sleep_for(std::chrono::milliseconds(150)); // 模拟消费
    }
}
