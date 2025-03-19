#include "../inc/TaskQueue.h"
#include <iostream>

TaskQueue::TaskQueue(size_t size) : maxsize(size) {}

bool TaskQueue::push(int item) {
    std::unique_lock<std::mutex> lock(mtx); // ✅ 正确写法
    cv_producer.wait(lock, [this]() { return buffer.size() < maxsize || stopFlag; });

    if (stopFlag) return false;

    buffer.push(item);
    std::cout << "生产者 生产了任务 " << item << std::endl;
    cv_consumer.notify_one();
    return true;
}

bool TaskQueue::pop(int &item) {
    std::unique_lock<std::mutex> lock(mtx); // ✅ 正确写法
    cv_consumer.wait(lock, [this]() { return !buffer.empty() || stopFlag; });

    if (stopFlag && buffer.empty()) return false;

    item = buffer.front();
    buffer.pop();
    std::cout << "消费者 消费了任务 " << item << std::endl;
    cv_producer.notify_one();
    return true;
}

void TaskQueue::stop() {
    stopFlag = true;
    cv_producer.notify_all();
    cv_consumer.notify_all();
}
