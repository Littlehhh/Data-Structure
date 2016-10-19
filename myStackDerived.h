#ifndef _myStackDerived_H
#define _myStackDerived_H
#include "myLinkList.h"
template <class T>
class Stack:public LinkList<T>{
	public:
		Stack(){
		
		}
		Stack(T a[],int n) : LinkList<T> (T a[],int n) {
		
		} 
		
		~Stack(){
		}
		void pop();
		void push(T data);
};
template <class T>
void Stack<T> :: pop()
{
	this->Delete(1);	
}
template <class T>
void Stack<T> :: push(T data)
{
	this->InsertAtHead(data);
}


#endif
