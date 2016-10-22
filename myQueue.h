#ifndef myQueue_H
#define myQueue_H
#include<iostream>
//普通队列的数组实现 
using namespace std;
template<typename T>
class Queue{
	private:
		int head,tail,count,size;
		T * Ele;
	public:
		// constructor
		Queue(int capacity){
			this->Ele = new T[capacity];
			this->tail = -1;
			this->size = capacity;
		}	
		~Queue(){
			delete [] Ele;
		}
		//Dequeue
		inline void deQueue(){
			if(tail>-1)
			{
				for(int i=0;i<=tail;i++)
					Ele[i] = Ele[i+1];
				tail--;
			}
			else 
				cout<<"Empty"<<endl;
		}
		//Enqueue
		inline void enQueue(T Element){
			if(tail<size-1)
			{
				Ele[tail+1] = Element;
				tail++;
			}
			else
				cout<<"Full"<<endl;
		}
		inline int searchQueue(T Element){
			for(int i=0;i<=tail;i++)
				if(Ele[i]==Element)
					return i;
		}
		inline void display(){
			for(int i=0;i<=tail;i++)
				cout<<Ele[i]<<endl;
		}

};
 
#endif


