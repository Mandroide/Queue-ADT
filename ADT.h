#pragma once
#define ADT_H
#include "IOInterface.h"
#include <vector>
#include <string>
class ADT
{
protected:
    int* data;
    size_t capacity; // capacity
    size_t count;
public:
    virtual ~ADT(){delete data;};
    virtual void add(const int) = 0;
    virtual void remove() = 0;
    /*virtual void add(const int) = 0;
    virtual void remove(int &);
    virtual void remove();*/
    virtual std::string toString() = 0;
    virtual int search(const int) = 0;
    virtual void sort() = 0;

    size_t getCapacity() const{ return capacity;}
    size_t getCount() const{ return count;}
/*    void setData(int data)
    {
        data = data;
    }
    int* getData() const
    {
        return data;
    }
    void setSize(const int counter)
    {
        size = counter;
    }
*/
};