/*
* File: PriorityQueue.cpp
* Author: aybar
*
* Created on September 26, 2017, 5:52 PM
*/
// #include "stdafx.h" // Permite compilar en Visual Studio
#include "PriorityQueue.h"
PriorityQueue::PriorityQueue(const int size) : Queue(size)
{
    priorities = new int[size];
    numbers = new int[size];
}
PriorityQueue::~PriorityQueue()
{
    delete[] priorities;
    delete[] numbers;
}
void PriorityQueue::add(const int num, const int priority)
{
}