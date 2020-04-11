// #include "stdafx.h" // Permite compilar en Visual Studio
#include "Queue.h"
#include <stdexcept>
#include <fstream>
#include <string>
using std::fstream;
using std::string;
Queue::Queue(const int n) : IOInterface("numbers.txt")
{
    size = n;
    queueArray = new int[size];
    front = -1;
    rear = -1;
    setNumItems(0);
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
    setNumItems(obj.getNumItems());
    size = obj.size;
    queueArray = new int[size];
    for (int i = 0; i < size; ++i)
    {
        queueArray[i] = obj.queueArray[i];
    }
}
Queue::~Queue()
{
    delete[] queueArray;
}
int Queue::getFront() const
{
    return front;
}
void Queue::setFront(int frontIndex)

{
    front = frontIndex;
}

int Queue::getRear() const
{
    return rear;
}
void Queue::setRear(int rearIndex)
{
    rear = rearIndex;
}
int Queue::getFirst() const
{
    return queueArray[front];
}
bool Queue::isEmpty()
{
    return (getNumItems() <= 0);
}
bool Queue::isFull()
{
    return (getNumItems() >= size);
}
void Queue::add(int num)
{
    if (!isFull())
    {
        // Calcula la nueva posicion de la cola.
        rear = (rear + 1) % size;
        queueArray[rear] = num;
        setNumItems(getNumItems() + 1);
        if (!isEmpty())
        {
            write();
        }
    }
}
void Queue::remove(int &num)
{
    if (!isEmpty())
    {
        front = (front + 1) % size; // Calcula con cual es congruente en Z sub
        size;
        num = queueArray[front];
        setNumItems(getNumItems() - 1);
        write();
    }
}
void Queue::clear()
{
    front = size - 1;
    rear = size - 1;
    setNumItems(0);
    write();
}
// Binary search.
int Queue::search(const int num)
{
    sort();
    int first = front,
        last = rear,
        middle,
        position = -1;
    bool isFound = false;
    while (!isFound && first <= last)
    {
        middle = (first + last) / 2;
        if (queueArray[middle] == num)
        {
            isFound = true;
            position = middle;
        }
        else if (queueArray[middle] > num)
            last = middle - 1;
        else
            first = middle + 1;
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
        minValue = queueArray[startScan];
        for (int index = startScan + 1; index < size; index++)
        {
            if (queueArray[index] < minValue)
            {
                minValue = queueArray[index];
                minIndex = index;
            }
        }
        queueArray[minIndex] = queueArray[startScan];
        queueArray[startScan] = minValue;
    }
}
// Show all elements in my queue.
std::string Queue::toString()
{
    std::string mensaje = "Los elementos en la cola son: ";
    if (front != -1)
    {
        for (int i = front; i <= rear; ++i)
        {
            mensaje.append(queueArray[i] + " ");
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
        if (front == -1)
        {
            file << "";
        }
        else
        {
            for (int i = front; i <= rear; ++i)
            {
                file << queueArray[i] << "\r\n";
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