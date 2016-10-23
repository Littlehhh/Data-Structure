#include<iostream>
#include"myLinkList.h"
#include"myQueueDerived.h"
#include"myStackDerived.h"
#include"myDoubleLinkList.h"
using namespace std;

void main()
{
	int a[] = {5,2,3,5,6,8},data,len;
//	DbLinkList<int> * Index;
/*
	LinkList<int>l1;

	l1.InsertAtHead(2);
	l1.InsertAtHead(2);
	l1.InsertAtIndex(1,5);
	l1.InsertAtTail(2);
	l1.display();*/
	
	LinkList<int>l2(a,(sizeof(a)/sizeof(a[0])));
	DbLinkList<int>d1(a,(sizeof(a)/sizeof(a[0])));
	d1.InsertAtTail(222);
	d1.display();
/*
	d1.deleteAtIndex(10);
	len = d1.getLength();
	cout<<len<<endl;*/
		
//	l2.display();
//	l2.Inversion();
/*
	len = l2.getLength();

	Index = l2.searchData(5);
	data = l2.searchIndex(3);
	cout<<data<<endl;
	Index->display();*/
//	l2.display();

/*
	//cout<<"Length  "<<l2.head->data<<endl;
	Queue<int> q1(a,(sizeof(a)/sizeof(a[0])));
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
	s1.display();*/
}



