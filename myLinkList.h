#ifndef _myLinkList_H
#define _myLinkList_H
#include<iostream>
using namespace std;
/*class LinkList;
template <class T>
class Node{
	friend class LinkList;
	private:
		T data;
		Node<T> * Next;
};*/
template <class T>
struct Node{
	T data;
	Node<T> * next;
};
template <class T>
class LinkList{
	//private:
	protected:
		Node<T> * head,* tail; //头节点数据域用来保存链表长度
		int size; 
	public:
		//构造函数 
		LinkList(); //有一个头节点的空链表 
		LinkList(T a[],int n); //生成存入数组a中元素的链表 
		//析构函数 
		~LinkList();
		//向链表中插入元素
		void InsertAtHead(T data);
		void InsertAtIndex(int Index,T data);
		void InsertAtTail(T data);  
		 //删除Index位置的元素
		void Delete(int Index); 
		//void DeleteAtTail();
		 
		void display(); //输出链表元素
		
}; 
//成员函数实现
template <class T>
LinkList<T> :: LinkList()
{
 	this->head = new Node<T>;
	this->tail = this->head; 
 	this->head->next = NULL;
 	this->head->data = 0;
}

template <class T>
LinkList<T> :: LinkList(T a[],int n)
{
	Node<T> * temp;
	this->head = new Node<T>;
	this->head->next = NULL;
	this->head->data = 0; 
	temp = head;
	for(int i=0;i<n;i++)
	{
		temp->next = new Node<T>;
		temp = temp->next;
		temp->data = a[i];
				
	}
	head->data = n;
	tail = temp;
	tail->next = NULL;
}
//析构函数 
template <class T>
LinkList<T> :: ~LinkList()
{
	Node<T> * temp,* destroy;
	temp = head;
	while(temp)
	{	
		destroy = temp;
		temp = temp->next;
		delete destroy;
	}
}
template <class T>
void LinkList<T> :: InsertAtHead(T data)
{
	Node<T> * temp;
	temp = new Node<T>;
	temp->data = head->data;
	head->data = data;
	temp->next = head;
	head = temp;
	head->data ++;
}
template <class T>
void LinkList<T> :: InsertAtIndex(int Index,T data)//索引从1开始  将data插入索引的位置 
{	
	if( Index>0 && Index <=(this->head->data)  )
	{ 
		Node<T> * temp,*newNode;
		temp = head;
		for(int i = 1;i < Index;i++)
			temp = temp->next;//找到前一个位置 
	 	newNode = new Node<T>;
		newNode->next = temp->next;
		newNode->data = data;
		temp->next = newNode;
		head->data++;
	}
	else
		cout<<"错误的索引输入"<<endl;
}
template <class T>
void LinkList<T> :: InsertAtTail(T data)
{
	tail->next = new Node<T>;
	tail = tail->next;
	tail->data = data;
	tail->next = NULL;
	head->data++;
}
template <class T>
void LinkList<T> :: Delete(int Index)
{
	if( Index>0 && Index<=(this->head->data) )
	{
		Node<T> * temp,*deNode;
		temp = head;
		for(int i = 1;i < Index;i++)
			temp = temp->next;//找到前一个位置 
		deNode = temp->next;
		temp->next = deNode->next;
		head->data--;
		delete deNode;
	}
	else
		cout<<"错误的索引输入或链表已空"<<endl; 
}
/*
template <class T>
LinkList<T> :: DeleteAtTail()
{
	Node<T> * temp;
	temp = tail;
	tail = NULL;
}*/
template <class T>
void LinkList<T> :: display()
{
	Node<T> * temp;
	temp = head->next;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->next;
	}

}
#endif

