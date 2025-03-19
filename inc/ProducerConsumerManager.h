#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"
#include <vector>
#include <thread>

class ProducerConsumerManager {
private:
    TaskQueue taskQueue;//任务队列
    std::vector<std::thread> producers;//生产者线程
    std::vector<std::thread> consumers;//消费者线程

public:
    ProducerConsumerManager(size_t bufferSize, int producerCount, int consumerCount);
    void runAndStopAfter(std::chrono::seconds duration);
};