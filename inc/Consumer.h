#pragma once
#include"TaskQueue.h"

class Consumer
{
private:
    TaskQueue &taskQueue;
public:
    Consumer(TaskQueue &taskQueue);
    void operator()();

};