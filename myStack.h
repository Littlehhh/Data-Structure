#ifndef myStack_H
#define myStack_H
#include<iostream>
//栈的数组实现 
using namespace std;
template<typename T>
class Stack{
	private:
		int size,top;			
		T * Ele;		// the elements array
	public:
		// constructor
		Stack(int capacity){
			this->Ele = new T[capacity];
			this->top = -1;
			this->size = capacity;
		}
		~Stack(){
			delete [] Ele;
		}
			
		inline void pop(){
			if(top>-1)
				top--;
			else 
				cout<<"Empty"<<endl;
		}
		inline void push(T Element){
			if(top<size)			
				Ele[++top] = Element;
			else
				cout<<"Full"<<endl;
		}
		inline int searchQueue(T Element){
			for(int i=0;i<=top;i++)
				if(Ele[i]==Element)
					return i;
		}
		inline void display(){
			for(int i=0;i<top;i++)
				cout<<Ele[i]<<endl;
		}

	

};

#endif