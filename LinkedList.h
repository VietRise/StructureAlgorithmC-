#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <stdio.h>
#include <stdlib.h>

class NodeList
{
    public:
        int data;
        NodeList* next;

    public:
        NodeList(int data);
};

class LinkedList
{
    public:
        NodeList *pHead, *pTail;

    public:
        LinkedList();
        void addNode(int value);
        void display();
        void insertStart(int value);
        void insertPosition(int index, int value);
        void insertLast(int value);
        void deleteFirst();
        bool deletePosition(int pos);
        void deleteLast();
        int length();
};

#endif