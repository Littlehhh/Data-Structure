#include<iostream>
#include"myQueue.h"
#include"myStack.h"
#include"myLinkedList.H"

using namespace std;

void main()
{
	Queue<int>q1(3);
	q1.deQueue();
	q1.enQueue(2);
	q1.enQueue(2);
	q1.enQueue(2);
	q1.enQueue(2);
	q1.deQueue(); 
	q1.display();
	Stack<int>s1(3);
	s1.pop();
	s1.push(2);
	s1.push(2);
	s1.push(2);
	s1.push(2);
	s1.push(2);
	s1.pop();
	s1.display();
	int b[3]={1,2,3};
	LinkList <int>l1(b);
	l1.Insert(0,5);
	l1.PrintList();
	l1.Insert(0,3);
	l1.PrintList();
	int a = l1.Length();
	cout<<a;
}



