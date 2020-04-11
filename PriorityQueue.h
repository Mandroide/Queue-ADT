#pragma once
#define PRIORITYQUEUE_H
#include "Queue.h"
#include <vector>
class PriorityQueue : public Queue
{

public:
    PriorityQueue(const int size);
    ~PriorityQueue();
    void add(const int, const int);

private:
    void add(const int num) {}
    int *priorities;
    int *numbers;
};