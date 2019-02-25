#include "Queue.h"

using namespace std;

QueueNode::QueueNode(int data)
{
    this->data = data;
}

unsigned int Queue::MAX_SIZE = 100;
Queue::Queue()
{
    buffer = new QueueNode*[MAX_SIZE];
    first = 0;
    last = MAX_SIZE - 1;
    size = 0;
}

bool Queue::isFull()
{
    if(size == MAX_SIZE)
        return true;
    return false;
}

bool Queue::push(int data)
{
    if (isFull())
        return false;
    last = (last+1)%MAX_SIZE;
    buffer[last] = new QueueNode(data);
    size++;
    return true;
}

QueueNode* Queue::pop()
{
    if(isEmpty())
        return nullptr;
    QueueNode* node = buffer[first++];
    size--;
    return node;
}

QueueNode* Queue::front()
{
    if(isEmpty())
        return nullptr;
    return buffer[first];
}

bool Queue::isEmpty()
{
    if(size == 0)
        return true;
    return false;
}

void Queue::display()
{
    for(int i = 0; i < size; i++)
    {
        int index = (first + i)%size;
        cout << buffer[index]->data << endl;
    }
}