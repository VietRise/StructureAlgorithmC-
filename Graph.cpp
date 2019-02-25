#include "Graph.h"
//#include "Stack.h"
//#include "Queue.h"
#include <set>

using namespace std;

int nextStack(Stack* stack)
{
    return stack->peek()->data;
}
int nextQueue(Queue* queue)
{
    return queue->front()->data;
}

AdjListNode::AdjListNode(int data)
{
    this->data = data;
    this->next = nullptr;
}

Graph::~Graph()
{
    for(int i = 0; i < this->v; i++)
    {
        AdjListNode* root = this->vertex[i].head;
        AdjListNode* temp = nullptr;
        while(root)
        {
            temp = root;
            root = root->next;
            delete temp;
        }
    }
    delete vertex;
}

Graph::Graph()
{
    v = 0;
    vertex = nullptr;
}

Graph* Graph::createGraph(int v)
{
    Graph* graph = new Graph();
    graph->v = v;
    graph->vertex = new AdjList[v];
    for (int i = 0; i < v; i++)
    {
        graph->vertex[i].head = nullptr;
    }
    return graph;
}

AdjListNode* Graph::newAdjListNode(int data)
{
    AdjListNode* node = new AdjListNode(data);
    return node;
}

// Add an edge undirected graph
void Graph::addEdgeUnDirect(int src, int dest)
{
    AdjListNode* nDest = Graph::newAdjListNode(dest);
    nDest->next = this->vertex[src].head;
    this->vertex[src].head = nDest;

    AdjListNode* nSrc = Graph::newAdjListNode(src);
    nSrc->next = this->vertex[dest].head;
    this->vertex[dest].head = nSrc;
}

// Add an edge directed graph
void Graph::addEdgeDirect(int src, int dest)
{
    AdjListNode* nDest = Graph::newAdjListNode(dest);
    nDest->next = this->vertex[src].head;
    this->vertex[src].head = nDest;
}
// Depth First Search
bool Graph::dfs(int start, int target)
{
    // return graphSearch<Stack>(start, target, [](Stack* stack){return stack->peek()->data;});
    cout << "Depth First Search" << endl;
    return graphSearch<Stack>(start, target, nextStack);
}

// Breadth First Search
bool Graph::bfs(int start, int target)
{
    // return graphSearch<Queue>(start, target, [](Queue* queue){return queue->front()->data;});
    cout << "Breadth First Search" << endl;
    return graphSearch<Queue>(start, target, nextQueue);
}

// Printf graph
void Graph::printfGraph()
{
    cout << "PrintfGraph" << endl;
    for(int i = 0; i < this->v; i++)
    {
        AdjListNode* root = this->vertex[i].head;
        cout << "Adjacency list of vertex " << i << (root != nullptr ? " -> " : "");
        while(root)
        {
            cout << root->data << (root->next != nullptr ? " -> " : "");
            root = root->next;
        }
        cout << endl;
    }
}

template<typename STACK_OR_QUEUE, typename NEXT_FN>
bool Graph::graphSearch(int start, int target, NEXT_FN next)
{
    STACK_OR_QUEUE* stackOrQueue = new STACK_OR_QUEUE();
    std::set<int> visited;
    stackOrQueue->push(start);
    while(!stackOrQueue->isEmpty())
    {
        int id = next(stackOrQueue);
        std::cout << id << " ";
        visited.insert(id);
        if(id == target)
        { 
            std::cout << " found target" << endl;
            delete stackOrQueue;
            return true;
        }
        else
        {
            stackOrQueue->pop();
            AdjListNode* head =  this->vertex[id].head;
            while(head)
            {
                if(visited.find(head->data) == visited.end())
                    stackOrQueue->push(head->data);
                head = head->next;
            }
        }
    }
    std::cout << " could not find target" << endl;
    delete stackOrQueue;
    return false ;
}