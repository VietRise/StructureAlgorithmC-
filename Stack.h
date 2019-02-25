#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

class StackNode
{
    public:
        int data;
    public:
        StackNode(int data);
};

class Stack 
{
    public:
        static unsigned int MAX_SIZE;
        StackNode** buffer;
        int roof;
    public:
        Stack();
        bool push(int data);
        StackNode* pop();
        StackNode* peek();
        bool isEmpty();
        void display();
};
#endif