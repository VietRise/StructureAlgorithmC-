#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class QueueNode
{
    public:
        int data;
    public:
        QueueNode(int data);
};

class Queue 
{
    public:
        static unsigned int MAX_SIZE;
        QueueNode** buffer;
        int first, last, size;
    public:
        Queue();
        bool isFull();
        bool push(int data);
        QueueNode* pop();
        QueueNode* front();
        bool isEmpty();
        void display();
};
#endif