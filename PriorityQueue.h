#pragma once
#define PRIORITYQUEUE_H
#include "Queue.h"
#include <vector>
/*
    Assuming that data with high value has low priority
*/
class PriorityQueue : public Queue
{

public:
    PriorityQueue(const size_t n) : Queue(n){
    }
    void add(const int num) override;
    int pop();
private:
    using Queue::remove;
};