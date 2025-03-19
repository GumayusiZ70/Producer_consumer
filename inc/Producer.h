#pragma once

#include"TaskQueue.h"

class Producer{
private:
    TaskQueue &taskQueue;

public:
    Producer(TaskQueue &taskQueue);
    void operator()();

};