#ifndef _myStackDerived_H
#define _myStackDerived_H
#include "myLinkList.h"
template <class T>
class Stack:public LinkList<T>{
	public:
		Stack(){
		  //不含参构造函数默认继承 
		}
		//含参析构函数需要重新实现 
		Stack(T a[],int n) : LinkList (a,n) {
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
