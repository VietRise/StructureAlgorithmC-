/*******************************************************************************
 ******************** VIET RISE'S ALGORITHM IMPLEMENTAIONS *********************
 *
 *  /\  |  _   _  ._ o _|_ |_  ._ _   _ 
 * /--\ | (_| (_) |  |  |_ | | | | | _> 
 *         _|                      
 *
 *
 ******************************************************************************/

#ifndef ALGO_SHUFFLE_H__
#define ALGO_SHUFFLE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include <map>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "Graph.h"
#include "SortSearchAlgorithm.h"

using namespace std;

namespace alg {
	/**
	 * shuffle the 'list' of length 'len'
	 */
	template<typename T>
		static void shuffle(T * list, int len) {
			srand(time(NULL));
			int i = len, j;
			T temp;

			if ( i == 0 ) return;
			while ( --i ) {
				j = rand() % (i+1);
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
}

namespace codeinterview {
	/*
	1.5 Replace all space in string with %20
	*/
	static void replaceFun(char* str, int length)
	{
		int countSpace = 0, newLength = 0;
		for (int i = 0; i < length; i++)
		{
			if(str[i] == ' ')
			{
				countSpace++;
			}
		}
		newLength = length + countSpace * 2;
		str[newLength] = '\0';
		int indexNewLength = newLength - 1;
		for(int i = length - 1; i >= 0; i--)
		{
			if(str[i] == ' ')
			{
				str[indexNewLength] = '0';
				str[indexNewLength - 1] = '2';
				str[indexNewLength - 2] = '%';
				indexNewLength -= 3;
			}
			else
			{
				str[indexNewLength] = str[i];
				indexNewLength--;
			}
		}
	}

	/*
	1.6 Rotate matrix NxN 90
	*/
	static void rotateMatrix(int** matrix, int n)
	{
		for (int layer = 0; layer < n/2; layer++)
		{
			int first = layer;
			int last = n - 1 - layer;
			for(int i = first; i < last; i++)
			{
				int offset = i - first;
				int top = matrix[first][i];
				// Left -> Top
				matrix[first][i] = matrix[last - offset][first];
				// Bottom -> Left
				matrix[last - offset][first] = matrix[last][last - offset];
				// Right -> Bottom
				matrix[last][last - offset] = matrix[i][last];
				// Top -> Right
				matrix[i][last] = top;
			}
		}
	}
	
	/*
	1.7 In the matrix MxN, set entire row & colum to 0 if an element at this [row, column] equal 0
	*/
	static void setZeros(int** matrix, int m, int n)
	{
		int row[m], colum[n];
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(matrix[i][j] == 0)
				{
					row[i] = 1;
					colum[j] = 1;
				}
			}
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(row[i] == 1 || colum[j] == 1)
				{
					matrix[i][j] = 0;
				}
			}
		}
	}

	/*
	1.8 
	*/

	static bool isStringRotation(std::string s1, std::string s2)
	{
		int len = s1.length();
		if(len == s2.length() && len > 0)
		{
			s1.append(s1);
			// return isSubString(s1, s2);
			return true;
		}
		return false;
	}

	static bool isStringRotation1(std::string s1, std::string s2)
	{
		if (s1.length() != s2.length() || s1.length() == 0)
			return false;
		int length = s1.length();
		bool hit[length];
		for(int i = 0; i < length; i++)
		{
			if(s2[i] == s1[0])
				hit[i] = true;
		}

		for(int i = 0; i < length; i++)
		{
			if(hit[i])
			{
				bool rotation = true;
				for(int j = 0; j < length; j++)
				{
					if(s1[j] != s2[(j + i)%length])
					{
						rotation = false;
						break;
					}
				}
				if (rotation)
					return true;
			}
		}
		return false;
	}

	/*
	2.1 
	*/

	static void removeDupLinkedList(LinkedList* list)
	{
		std::map<int, bool> mapData;
		NodeList *prev, *cur;
		prev = nullptr;
		cur = list->pHead;
		while(cur != nullptr)
		{
			if(mapData.find(cur->data) != mapData.end())
			{
				NodeList* temp = cur;
				prev->next = cur->next;
				cur = cur->next;
				delete temp;
			}
			else
			{
				mapData[cur->data] = true;
				prev = cur;
				cur = cur->next;
			}
		}
	}

	static void removeDupLinkedListNoBuffer(LinkedList* list)
	{
		NodeList *prev, *cur, *itor;
		prev = list->pHead;
		cur = list->pHead->next;
		while(cur != nullptr)
		{
			itor = list->pHead;
			while(itor != cur)
			{
				if(cur->data == itor->data)
				{
					NodeList* temp = cur;
					prev->next = cur->next;
					cur = cur->next;
					delete temp;
					break;
				}
				itor = itor->next;
			}
			if(itor == cur)
			{
				prev = cur;
				cur = cur->next;
			}
		}
	}

	/*
	2.2
	*/

	static LinkedList* nthToLastLinkedList(LinkedList* list, int n)
	{
		NodeList *p1, *p2;
		p1 = list->pHead;
		p2 = list->pHead;
		int count = 0;
		while(p2 != nullptr)
		{
			count++;
			if (count == n)
				break;
			p2 = p2->next;
		}

		if(count == n)
		{
			while(p2->next)
			{
				p1 = p1->next;
				p2 = p2->next;
			}
		}
		LinkedList* result = new LinkedList();
		result->pHead = p1;
		result->pTail = p2;
		return result;
	}

	/*
	2.3
	*/
	static void deletedMiddleNodeOfLinkedList(LinkedList* list)
	{
		int length = list->length();
		int middlePos = length/2;
		list->deletePosition(middlePos);
	}

	/*
	2.4
	*/
	static NodeList* findingBeginCircularLinkedList(LinkedList* list)
	{
		NodeList *cur, *itor;
		cur = list->pHead->next;
		while(cur)
		{
			itor = list->pHead;
			while(itor != cur)
			{
				if(cur->next == itor)
				{
					return itor;
				}
				itor = itor->next;
			}
			cur = cur->next;
		}
		return nullptr;
	}

	/*
	3.6 Sort stack in ascending order
	*/
	static Stack* sortAscendingOrderStack(Stack* s)
	{
		Stack* r = new Stack();
		while(!s->isEmpty())
		{
			StackNode* temp = s->pop();
			while(!r->isEmpty() && temp->data < r->peek()->data)
			{
				s->push(r->pop()->data);
			}
			r->push(temp->data);
		}
		return r;
	}

}

int main()
{
	// LinkedList
	/*
	LinkedList* list = new LinkedList();
	list->addNode(1);
	list->addNode(2);
	list->addNode(3);
	list->addNode(4);
	list->addNode(5);
	list->addNode(6);
	list->addNode(7);
	list->addNode(8);
	list->addNode(9);
	
	list->display();
	codeinterview::deletedMiddleNodeOfLinkedList(list);
	list->display();
	*/

	// Stack & Queue
	/*
	Stack* stack = new Stack();
	stack->push(2);
	stack->push(4);
	stack->push(1);
	stack->push(3);
	stack->push(5);
	stack->display();

	Stack* result = codeinterview::sortAscendingOrderStack(stack);
	result->display();
	*/

	// Tree & Graph
	/*
	BinaryTree* binaryTree = new BinaryTree();
	binaryTree->insert(25);
	binaryTree->insert(15);
	binaryTree->insert(50);
	binaryTree->insert(10);
	binaryTree->insert(22);
	binaryTree->insert(4);
	binaryTree->insert(12);
	binaryTree->insert(18);
	binaryTree->insert(24);
	binaryTree->insert(35);
	binaryTree->insert(70);
	binaryTree->insert(31);
	binaryTree->insert(44);
	binaryTree->insert(66);
	binaryTree->insert(90);
	
	binaryTree->inOderPrintf();
	binaryTree->preOderPrintf();
	binaryTree->postOderPrintf();
	binaryTree->levelOderPrintf();
	bool isBalance = binaryTree->isBalance();
	cout << (isBalance ? "Balanced Tree" : "Unbalanced Tree") << endl;

	Graph* graphUndirected = Graph::createGraph(5);
	graphUndirected->addEdgeUnDirect(0, 1);
	graphUndirected->addEdgeUnDirect(0, 4);
	graphUndirected->addEdgeUnDirect(1, 2);
	graphUndirected->addEdgeUnDirect(1, 3);
	graphUndirected->addEdgeUnDirect(1, 4);
	graphUndirected->addEdgeUnDirect(2, 3);
	graphUndirected->addEdgeUnDirect(3, 4);
	graphUndirected->printfGraph();

	Graph* graphDirected = Graph::createGraph(5);
	graphDirected->addEdgeDirect(0, 1);
	graphDirected->addEdgeDirect(0, 4);
	graphDirected->addEdgeDirect(1, 2);
	graphDirected->addEdgeDirect(1, 3);
	graphDirected->addEdgeDirect(1, 4);
	graphDirected->addEdgeDirect(2, 3);
	graphDirected->addEdgeDirect(3, 4);
	graphDirected->printfGraph();
	graphDirected->dfs(1, 4);
	graphDirected->bfs(1, 4);
	graphDirected->dfs(2, 0);
	graphDirected->bfs(2, 0);

	int max = 0b1111;
	cout << "max = " << max << endl;
	*/

	// Sort & Search
	int array[10] = {20, 3, 50, 45, 22, 78, 26, 8, 79, 10};
	// SortSearchAlgorithm::bubbleSort(array, 10);
	// SortSearchAlgorithm::selectionSort(array, 10);
	// SortSearchAlgorithm::mergeSort(array, 0, 9);
	SortSearchAlgorithm::quickSort(array, 0, 9);
	for(int i = 0; i < 10; i++)
		cout << array[i] << " ";
	cout << endl;

	return 0;
}

#endif 