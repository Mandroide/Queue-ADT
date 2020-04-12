/*
* File: PriorityQueue.cpp
* Author: aybar
*
* Created on September 26, 2017, 5:52 PM
*/
// #include "stdafx.h" // Permite compilar en Visual Studio
#include "PriorityQueue.h"
void PriorityQueue::add(const int num)
{
    if (!isFull())
    {
        if (isEmpty())
        {
            data[count++] = num;
        } else
        {
            size_t i = 0;
            // start from the right end of the queue
            for (i = count - 1; i >= 0; --i)
            {
                // if data is larger, shift existing item to right end 
                if (num > data[i])
                {
                    data[i + 1] = data[i];
                }
                else
                {
                    break;
                }
            }
            data[i+1] = num;
            count++;
        }
    }
    
}

int PriorityQueue::pop(){
   return data[--count];
}