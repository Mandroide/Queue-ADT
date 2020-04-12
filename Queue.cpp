// #include "stdafx.h" // Permite compilar en Visual Studio
#include "Queue.h"
#include <stdexcept>
#include <fstream>
#include <string>
using std::fstream;
using std::string;
Queue::Queue(const size_t n) : IOInterface("numbers.txt")
{
    count = front = 0;
    rear = -1;
    capacity = n;
    data = new int[n];
    try
    {
        read();
    }
    catch (const string &)
    {
    }
}
Queue::Queue(const Queue &obj)
{
    front = obj.front;
    rear = obj.rear;
    capacity = obj.capacity;
    count = obj.count;
    data = new int[capacity];
    isSorted = obj.isSorted;
    for (size_t i = 0; i < count; ++i)
    {
        data[i] = obj.data[i];
    }
}

int Queue::getFront()
{
    return data[front];
};

void Queue::add(const int num)
{
    if (isFull())
    {
        return;
    }
    else
    {
        rear = (rear + 1) % capacity;
        data[rear] = num;
        count++;
        write();
        isSorted = false;
    }
}
void Queue::remove()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        front = (front + 1) % capacity;
        count--;
        write();
    }
}
void Queue::clear()
{
    front = 0;
    rear = -1;
    write();
}
int Queue::search(const int num)
{
    int position = rear;
    if (position > -1)
    {
        position = (isSorted) ? binarySearch(num) : linearSearch(num);
    }
    return position;
}

int Queue::binarySearch(const int num)
{
    int first = front,
        last = rear,
        middle,
        position = -1;
    bool isFound = false;
    while (!isFound && first <= last)
    {
        middle = (first + last) / 2;
        if (data[middle] == num)
        {
            isFound = true;
            position = middle;
        }
        else if (data[middle] > num)
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}

int Queue::linearSearch(const int num)
{
    int position = -1;
    for (size_t i = front; i <= rear; i++)
    {
        if (data[i] == num)
        {
            position = i;
            break;
        }
    }

    return position;
}

// Sort by selection sorting.
void Queue::sort()
{
    int startScan, minIndex, minValue;
    for (startScan = front; startScan < (rear - 1); startScan++)
    {
        minIndex = startScan;
        minValue = data[startScan];
        for (int index = startScan + 1; index < count; index++)
        {
            if (data[index] < minValue)
            {
                minValue = data[index];
                minIndex = index;
            }
        }
        data[minIndex] = data[startScan];
        data[startScan] = minValue;
    }
    isSorted = true;
}
// Show all elements in my queue.
std::string Queue::toString()
{
    std::string mensaje = "";
    if (count > 0)
    {
        mensaje = "Los elementos en la cola son: ";
        for (int i = front; i <= rear; ++i)
        {
            mensaje.append(data[i] + " ");
        }
    }
    else
    {
        mensaje = "No hay elementos en la cola";
    }
    mensaje.append("\n");
    return mensaje;
}
void Queue::write()
{
    fstream file;
    file.open(getFilename(), std::ios::out);
    if (!file.fail())
    {
        if (count == 0)
        {
            file << "";
        }
        else
        {
            for (int i = front; i <= rear; ++i)
            {
                file << data[i] << "\r\n";
            }
        }
    }
    else
    {
        string mensaje = "El archivo no se abrio correctamente write";
        throw mensaje;
    }
    file.close();
}
void Queue::read()
{
    fstream file;
    file.open(getFilename(), std::ios::in);
    int num;
    if (!file.fail())
    {
        clear();
        while (file >> num)
        {
            add(num);
        }
    }
    else
    {
        string mensaje = "El archivo no se abrio correctamente";
        throw mensaje;
    }
    file.close();
}