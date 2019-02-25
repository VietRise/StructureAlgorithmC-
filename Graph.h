#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Stack.h"
#include "Queue.h"

struct AdjListNode
{
    int data;
    AdjListNode* next;

    AdjListNode(int data);
};

struct AdjList
{
    AdjListNode* head;
};

int nextStack(Stack* stack);
int nextQueue(Queue* queue);

class Graph
{
    public:
        int v;
        AdjList* vertex;
    public:
        ~Graph();
        Graph();
        static Graph* createGraph(int v);
        static AdjListNode* newAdjListNode(int data);
        void addEdgeUnDirect(int src, int dest);
        void addEdgeDirect(int src, int dest);
        bool dfs(int start, int target);
        bool bfs(int start, int target);
        void printfGraph();

    private:
        template<typename STACK_OR_QUEUE, typename NEXT_FN>
        bool graphSearch(int start, int target, NEXT_FN next);
};

#endif