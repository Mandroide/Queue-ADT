#pragma once
#define QUEUE_H
#include "ADT.h"
#include "IOInterface.h"
#include <string>
class Queue : public ADT, IOInterface
{
private:
    int rear;  // rear
    int binarySearch(const int num);
    int linearSearch(const int num);
protected:
    int front;
    bool isSorted;
public:
    Queue(const size_t size);
    Queue(const Queue &);
    // Ownss
    int getFront();
    bool isEmpty(){ return count == 0;};
    bool isFull(){ return count == capacity;};
    void clear();
    virtual void add(const int num) override; //enqueue
    virtual void remove() override;  // dequeue
    // Inherited.
    virtual void read() override;
    virtual int search(const int) override;

    virtual void sort() override;

    virtual std::string toString() override;

    virtual void write() override;
};