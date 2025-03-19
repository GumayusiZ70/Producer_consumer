#pragma once
#include<queue>
#include<mutex>
#include<condition_variable>


class TaskQueue
{
private:
    std::queue<int> buffer;//用于存储任务
    const size_t maxsize;
    std::mutex mtx;
    std::condition_variable cv_producer;//生产者条件变量，用于通知生产者线程队列有空闲空间
    std::condition_variable cv_consumer;//消费者条件变量，用于通知消费者队列中有新任务
    bool stopFlag = false;//一个布尔标志，用于指示队列是否停止工作。



public:
    TaskQueue(size_t size);
    bool push(int item);
    bool pop(int &item);
    void stop();
};


