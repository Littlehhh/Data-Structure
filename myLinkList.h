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
template <class T>  //��ͬ������ע�� 
struct Node{
	T data;
	Node<T> * next;
};
template <class T>
class LinkList{
	//private:
	protected:
		Node<T> * head,* tail; //ͷ�ڵ���������������������
		int size; 
	public:
		//���캯�� 
		LinkList(); //��һ��ͷ�ڵ�Ŀ����� 
		LinkList(T a[],int n); //���ɴ�������a��Ԫ�ص����� 
		//�������� 
		virtual ~LinkList();
		//�������в���Ԫ��
		void InsertAtHead(T data);
		void InsertAtIndex(int Index,T data);
		void InsertAtTail(T data);  
		 //ɾ��Indexλ�õ�Ԫ��
		void Delete(int Index); 
		//void DeleteAtTail();//������ Delete��xx.getLength()��;���� 
	 	void Inversion();//��ת���� 
		void display(); //�������Ԫ��
		bool isEmpty(); //�ж������Ƿ�Ϊ�� 
		LinkList<T> * searchData(T data);//����Ԫ�ط������� 
		T searchIndex(int Index);//���������������� 
		int getLength(); 
}; 
//��Ա����ʵ��
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
//�������� 
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
void LinkList<T> :: InsertAtIndex(int Index,T data)//������1��ʼ  ��data����������λ�� 
{	
	if( Index>0 && Index <=(this->head->data)  )
	{ 
		Node<T> * temp,*newNode;
		temp = head;
		for(int i = 1;i < Index;i++)
			temp = temp->next;//�ҵ�ǰһ��λ�� 
	 	newNode = new Node<T>;
		newNode->next = temp->next;
		newNode->data = data;
		temp->next = newNode;
		head->data++;
	}
	else
		cout<<"�������������"<<endl;
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
			temp = temp->next;//�ҵ�ǰһ��λ�� 
		deNode = temp->next;
		temp->next = deNode->next;
		head->data--;
		delete deNode;
	}
	else
		cout<<"�������������������ѿ�"<<endl; 
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
void LinkList<T> :: Inversion()
{
	Node<T> * temp,*prev,*follow;
	temp = head->next;
	prev = temp;
	
	if(!temp)
		cout<<"Empty"<<endl;
	else
	{
		follow = temp->next;
		while(follow)
		{
			temp = follow;
			follow = temp->next;
			temp->next = prev;
			prev = temp;
		}
		head->next->next = NULL;
		head->next = temp;
	}
}
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
template <class T>
LinkList<T> * LinkList<T> :: searchData(T data)
{
	LinkList<T> * index = new LinkList<T>;
	Node<T> * temp;
	int Index=1;
	if(this->isEmpty())
	{	cout<<"������"<<endl;return NULL;}
	temp = this->head->next;
	while(temp)
	{
		if(temp->data == data)
			index->InsertAtTail(Index);
		temp = temp->next;
		Index++;	
	} 
	if(index->isEmpty())
	{	cout<<"��������û�д�����"<<endl;return NULL;}
	return index;
}

template <class T>
T LinkList<T> :: searchIndex(int Index)
{
	Node<T> * temp;
	if( (this->head->data) < Index )
	{cout<<"��������û�д�����"<<endl;return NULL;}
	else
	{
		temp = head; 
		for(int i = 1;i < Index;i++)
			temp = temp->next;//�ҵ�ǰһ��λ�� 
		return temp->next->data;
	}

}
template <class T>
bool LinkList<T> :: isEmpty()
{	
	if( this->head->data == 0)
		return true;
	else 
		return false;
}
template <class T>
int LinkList<T> :: getLength()
{
	return this->head->data;

}
#endif

