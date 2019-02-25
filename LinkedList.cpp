#include "LinkedList.h"
#include <iostream>

using namespace std;

NodeList::NodeList(int data)
{
    this->data = data;
    this->next = nullptr;
}

// --------------------------
LinkedList::LinkedList()
{
    this->pHead = nullptr;
    this->pTail = nullptr;
}

void LinkedList::addNode(int value)
{
    NodeList* n = new NodeList(value);
    if (pHead == nullptr)
    {
        pHead = n;
        pTail = n;
    }
    else
    {
        pTail->next = n;
        pTail = n;
    }
}

void LinkedList::display()
{
    NodeList* cur = pHead;
    std::cout << "LinkedList:" << endl;
    while(cur != nullptr)
    {
        std::cout << cur->data << endl;
        cur = cur->next;
    }
}

void LinkedList::insertStart(int value)
{
    NodeList* n = new NodeList(value);
    n->next = pHead;
    pHead = n;
}

void LinkedList::insertPosition(int index, int value)
{
    if(index == 0)
    {
        LinkedList::insertStart(value);
        return;
    }   
    int count = 1;
    NodeList *prev, *cur;
    prev = pHead;
    cur = pHead->next;
    do
    {
        if(count == index)
        {
            NodeList* n = new NodeList(value);
            prev->next = n;
            n->next = cur;
            break;
        }
        prev = cur;
        cur = cur->next;
        count++;
    }
    while(cur != nullptr);
}

void LinkedList::insertLast(int value)
{
    NodeList* n = new NodeList(value);
    pTail->next = n;
    pTail = n;
}

void LinkedList::deleteFirst()
{
    NodeList* temp = pHead;
    pHead = pHead->next;
    if(pHead == nullptr)
        pTail = nullptr;
    delete temp;
}

bool LinkedList::deletePosition(int pos)
{
    int count = 0;
    NodeList *prev, *cur;
    prev = nullptr;
    cur = pHead;
    while(count != pos && cur != nullptr)
    {
        prev = cur;
        cur = cur->next;
        count++;
    }
    
    if (count == pos)
    {
        prev->next = cur->next;
        delete cur;
        return true;
    }
    
    return false;
}

void LinkedList::deleteLast()
{
    NodeList *prev, *cur;
    prev = nullptr;
    cur = pHead;
    while(cur != pTail)
    {
        prev = cur;
        cur = cur->next;
    }
    pTail = prev;
    pTail->next = nullptr;
    delete cur;
}

int LinkedList::length()
{
    int lengthLinkedList = 0;
    NodeList* itor = pHead;
    while(itor != nullptr)
    {
        lengthLinkedList++;
        itor = itor->next;
    }
    return lengthLinkedList;
}