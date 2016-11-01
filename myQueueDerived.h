#ifndef _myQueueDerived_H
#define _myQueueDerived_H
#include"myLinKList.h"
using namespace std;


template <class T>
class Queue:public LinkList<T>{
	public:
		Queue()
		{
		}
		Queue(T a[],int n):LinkList(a,n){
		} 
		~Queue()
		{
		}
		void EnQueue(T data);
		void DeQueue();
};

template <class T>
void Queue<T> :: EnQueue(T data)
{
	this->InsertAtTail(data);
}
template <class T>
void Queue<T> :: DeQueue()
{
	this->Delete(1);
}



#endif