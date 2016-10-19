#include<iostream>
#include"myLinkList.h"
#include"myQueueDerived.h"
#include"myStackDerived.h"
using namespace std;

void main()
{
	int a[] = {5,2,3,6,8};
	LinkList<int>l1;

	l1.InsertAtHead(2);
	l1.InsertAtHead(2);
	l1.InsertAtIndex(1,5);
	l1.InsertAtTail(2);
	l1.display();

	LinkList<int>l2(a,(sizeof(a)/sizeof(a[0])));
	l2.display();
	//cout<<"Length  "<<l2.head->data<<endl;
	Queue<int> q1;
	q1.EnQueue(5);
	q1.EnQueue(5);
	q1.EnQueue(5);
	q1.EnQueue(5);
	q1.DeQueue();
	q1.EnQueue(5);
	q1.EnQueue(5);
	q1.display();
	Stack<int> s1(a,(sizeof(a)/sizeof(a[0])));
	s1.push(00);
	s1.push(11);
	s1.push(22);
	s1.push(33);
	s1.push(44);
	s1.pop();
	s1.display();
}



