#pragma once
#define ADT_H
#include "IOInterface.h"
#include <vector>
#include <string>
class ADT
{
private:
    int datum;
    //std::vector<int> persist;
    int numItems; // counter
public:
    virtual void add(const int) = 0;
    virtual void remove(int &) = 0;
    virtual std::string toString() = 0;
    virtual int search(const int) = 0;
    virtual void sort() = 0;
    void setDatum(int data)
    {
        datum = data;
    }
    int getDatum() const
    {
        return datum;
    }
    void setNumItems(const int counter)
    {
        numItems = counter;
    }
    int getNumItems() const
    {
        return numItems;
    }
};