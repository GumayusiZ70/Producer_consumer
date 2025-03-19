#include "../inc/ProducerConsumerManager.h"

ProducerConsumerManager::ProducerConsumerManager(size_t bufferSize, int producerCount, int consumerCount)
    : taskQueue(bufferSize) {
    for (int i = 0; i < producerCount; ++i) {
        producers.emplace_back(Producer(taskQueue));
    }
    for (int i = 0; i < consumerCount; ++i) {
        consumers.emplace_back(Consumer(taskQueue));
    }
}

void ProducerConsumerManager::runAndStopAfter(std::chrono::seconds duration) {
    std::this_thread::sleep_for(duration);
    taskQueue.stop();

    for (auto &p : producers) p.join();
    for (auto &c : consumers) c.join();
}
