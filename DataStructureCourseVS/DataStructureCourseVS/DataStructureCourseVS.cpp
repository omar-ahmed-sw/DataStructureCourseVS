// DataStructureCourseVS.cpp : Defines the entry point for the console application.
//

// DataStructureCourseVS.cpp : Defines the entry point for the console application.
//


//============================================================================
// Name        : DataStructureCourseVS.cpp
// Author      : Omar Ahmed
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include "StackHandler.h"
#include "QueueHandler.h"
#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "SearchingAlgorithms.h"
#include "SortingAlgorithms.h"

using namespace std;

int main() {

	clsNode NodeInstance;
	clsStackHandler StackInstance;
	clsQueueHandler QueueInstance;
	clsSinglyLinkedList SinglyLinkedListInstance;
	clsDoublyLinkedList DoublyLinkedListInstance;
	clsSearchingAlgorithms SearchingAlgorithmsInstance;
	clsSortingAlgorithms SortingAlgorithmsInstance;
	

	std::vector <int32> Array = { 9,-3,1,0,5,-10,6,1,0,4,63,4,-2,-7,10,11,0,17,-6 };
	
	clsNode* node1 = new clsNode(1, 10);
	clsNode* node2 = new clsNode(2, 20);
	clsNode* node3 = new clsNode(3, 30);
	clsNode* node4 = new clsNode(4, 40);
	clsNode* node5 = new clsNode(5, 777);
	clsNode* node6 = new clsNode(6, 888);
	clsNode* node7 = new clsNode(6, 111);
	clsNode* node8 = new clsNode(6, 999);
	clsNode* node9 = new clsNode(3, 70);


	DoublyLinkedListInstance.DisplayLinkedList();

	DoublyLinkedListInstance.AppendNode(node1);
	DoublyLinkedListInstance.AppendNode(node2);
	DoublyLinkedListInstance.AppendNode(node3);
	DoublyLinkedListInstance.AppendNode(node4);


	DoublyLinkedListInstance.PrependNode(node5);
	DoublyLinkedListInstance.PrependNode(node6);

	

	DoublyLinkedListInstance.PrependNode(node7);
	DoublyLinkedListInstance.AppendNode(node8);

	DoublyLinkedListInstance.DisplayLinkedList();

	DoublyLinkedListInstance.DeleteNode(2);
	DoublyLinkedListInstance.ChangeNode(8, 100);
	DoublyLinkedListInstance.InsertNode(4, node9);
	DoublyLinkedListInstance.DisplayLinkedList();
	DoublyLinkedListInstance.DisplayNode(2);
	
	//int32 searchresult = SearchingAlgorithmsInstance.BinarySearch(Array, 3);

	SortingAlgorithmsInstance.InsertionSort(Array);


	//std::cout << "\n\n" << "Searchresult = " << searchresult;
	
	
	
	/*
	//Singly linked list testing section
	clsNode* node1 = new clsNode(1, 10);
	clsNode* node2 = new clsNode(2, 20);
	clsNode* node3 = new clsNode(3, 30);
	clsNode* node4 = new clsNode(4, 40);
	clsNode* node5 = new clsNode(2, 50);
	clsNode* node6 = new clsNode(6, 60);


	SinglyLinkedListInstance.AppendNode(node1);
	SinglyLinkedListInstance.AppendNode(node2);
	SinglyLinkedListInstance.AppendNode(node3);
	SinglyLinkedListInstance.AppendNode(node4);
	SinglyLinkedListInstance.AppendNode(node5);
	SinglyLinkedListInstance.DeleteNode(2);
	SinglyLinkedListInstance.AppendNode(node5);
	//SinglyLinkedListInstance.DeleteNode(1);
	//SinglyLinkedListInstance.DeleteNode(3);
	//SinglyLinkedListInstance.DeleteNode(2);
	//SinglyLinkedListInstance.DeleteNode(4);

	SinglyLinkedListInstance.ChangeNode(1, 100);
	//SinglyLinkedListInstance.DisplayNode(3);
	SinglyLinkedListInstance.InsertNode(3, node6);
	SinglyLinkedListInstance.DisplayLinkedList();
	
	*/
	/*
	//Queue testing section
	QueueInstance.Enqueue(900);
	QueueInstance.Enqueue(800);
	QueueInstance.Enqueue(700);
	QueueInstance.Enqueue(600);
	QueueInstance.Enqueue(500);
	QueueInstance.Enqueue(400);
	QueueInstance.Enqueue(300);
	QueueInstance.Enqueue(200);
	QueueInstance.Enqueue(100);
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "size = " << QueueInstance.GetSize() << "\n";
	std::cout << "element 3 = " << QueueInstance.Peek(2) << "\n";
	QueueInstance.Change(10, 777);
	std::cout << "element 9 = " << QueueInstance.Peek(10) << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	std::cout << "Dequeue = " << QueueInstance.Dequeue() << "\n";
	QueueInstance.Display();
	*/

	/*
	//Stack testing
	StackInstance.Push(100);
	StackInstance.Push(200);
	StackInstance.Push(300);
	StackInstance.Push(400);
	StackInstance.Push(500);
	StackInstance.Push(600);
	std::cout << "size = " << StackInstance.GetSize() << "\n";
	std::cout << "element 3 = " << StackInstance.Peek(50) << "\n";
	StackInstance.Change(0, 800);
	std::cout << "Top=" << StackInstance.Top;
	StackInstance.Display();
	std::cout << "pop = " << StackInstance.Pop() << "\n";
	std::cout << "pop = " << StackInstance.Pop() << "\n";
	std::cout << "pop = " << StackInstance.Pop() << "\n";
	std::cout << "pop = " << StackInstance.Pop() << "\n";
	std::cout << "pop = " << StackInstance.Pop() << "\n";
	std::cout << "pop = " << StackInstance.Pop() << "\n";
	std::cout << "pop = " << StackInstance.Pop() << "\n";
	std::cout << "pop = " << StackInstance.Pop() << "\n";

	//StackInstance.Display();
	*/

	while (true)
	{

	}
	return 0;
}


