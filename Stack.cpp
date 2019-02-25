#include "Stack.h"

using namespace std;

StackNode::StackNode(int data)
{
    this->data = data;
}

unsigned int Stack::MAX_SIZE = 100;
Stack::Stack()
{
    buffer = new StackNode*[MAX_SIZE];
    roof = -1;
}

bool Stack::push(int data)
{
    roof++;
    if(roof >= MAX_SIZE)
    {
        cout << "Stack is Overflow" << endl;
        return false;
    }
    else
    {
        buffer[roof] = new StackNode(data);
        return true;
    }
    
}

StackNode* Stack::pop()
{
    if(isEmpty())
    {
        return nullptr;
    }
    return buffer[roof--];
}

StackNode* Stack::peek()
{
    if(isEmpty())
        return nullptr;
    return buffer[roof];
}

bool Stack::isEmpty()
{
    if(roof < 0)
        return true;
    return false;
}

void Stack::display()
{
    for(int i = 0; i <= roof; i++)
    {
        cout << buffer[i]->data << endl;
    }
}