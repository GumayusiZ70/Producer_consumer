#include "ProducerConsumerManager.h"
#include <iostream>

int main() {
    ProducerConsumerManager manager(5, 2, 2); // 缓冲区大小=5，2个生产者，2个消费者
    manager.runAndStopAfter(std::chrono::seconds(5)); // 运行5秒后停止
    return 0;
}
