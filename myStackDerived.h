#ifndef _myStackDerived_H
#define _myStackDerived_H
#include "myLinkList.h"
template <class T>
class Stack:public LinkList<T>{
	public:
		Stack(){
		  //�����ι��캯��Ĭ�ϼ̳� 
		}
		//��������������Ҫ����ʵ�� 
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
