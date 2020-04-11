#pragma once
#define QUEUE_H
#include "ADT.h"
#include "IOInterface.h"
#include <string>
class Queue : public ADT, IOInterface
{
private:
    int *queueArray;
    int size;
    int front; // front
    int rear;  // rear
public:
    Queue(const int size);
    Queue(const Queue &);
    ~Queue();
    // Own
    int getFront() const;
    void setFront(int frontIndex);
    int getRear() const;
    void setRear(int rearIndex);
    int getFirst() const;
    bool isEmpty();
    bool isFull();
    void clear();
    // Inherited.
    virtual void add(const int) override; //enqueue
    virtual void remove(int &) override;  // dequeue
    virtual void read() override;
    virtual int search(const int) override;

    virtual void sort() override;

    virtual std::string toString() override;

    virtual void write() override;
};