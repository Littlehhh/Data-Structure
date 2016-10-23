#ifndef _DoubleLinkList_H
#define _DoubleLinkList_H
//��ͷ�ڵ��˫������
//ͷ�ڵ�data�洢������ 
#include<iostream>
using namespace std;
template <class T>
struct DbNode{
	DbNode * left;
	T data;
	DbNode * right;
}; 


template <class T>
class DbLinkList{
	protected://����̳�
		DbNode<T> * head,* tail;
		int size;//��¼������ 
	public:
		DbLinkList();//	construction	 
		DbLinkList(T a[], int n); // construction with parameter
		virtual ~DbLinkList(); // destruction
		int getLength(); //return the length of linkedlist
		void Insertion(T data,int Index);//insert data at index
		void InsertAtTail(T data);//insert data at tail
		void deleteAtIndex(int Index); //delete element and return it
		T search(int Index) const;
		
		void display() const;
		
};
//implementation
//��ģ����������ͳ�Ա����ʵ������Щ���������޷��ֿ����� 
template <class T>
DbLinkList<T> :: DbLinkList()
{
	this->head = new DbNode<T>;
	this->tail = NULL;
	this->head->left = NULL;
	this->head->right = NULL;
	this->head->data = 0;
}
template <class T>
DbLinkList<T> :: DbLinkList(T a[], int n)
{
	DbNode<T> * temp;
	this->head = new DbNode<T>;
	this->tail = NULL;
	this->head->left = NULL;
	this->head->right = NULL;
	this->head->data = 0;
	temp = head;
	for(int i=0;i<n;i++)
	{
		temp->right =  new DbNode<T>;
		temp->right->left = temp;  //�½�����ָ��ָ��ǰ�����
		temp = temp->right;
		temp->data = a[i];
		temp->right = NULL;
	}
	tail = temp;
	//tail->right = head; //ѭ���������ؼ� 
	head->data = n;
}
template <class T>
DbLinkList<T> :: ~DbLinkList()
{

	DbNode<T> * temp,*destroy;
	temp = head;
	while(temp)
	{	
		destroy = temp;
		temp = temp->right;
		delete destroy;
	}

} 
template <class T>
void DbLinkList<T> :: Insertion(T data,int Index)
{
	if( Index>0 && Index <= (this->head->data)  )
	{ 
		DbNode<T> * temp,*newDbNode;
		temp = head;
		for(int i = 1;i < Index;i++)
			temp = temp->right;  //�ҵ�ǰһ��λ�� 
	 	newDbNode = new DbNode<T>;
	 	newDbNode->left = temp;
	 	newDbNode->right = temp->right;
	 	temp->right->left = newDbNode;
	 	newDbNode->data = data;
		head->data++;
	}
	else
		cout<<"�������������"<<endl;
}

template <class T>
void DbLinkList<T> ::  InsertAtTail(T data)
{
	tail->right = new DbNode<T>;
	tail->right->left = tail;
	tail = tail->right;
	tail->right = NULL;
	tail->data = data;
	head->data++;
}
template <class T>
void DbLinkList<T> :: deleteAtIndex(int Index)
{
	if( Index>0 && Index <= (this->head->data)  )
	{ 
		DbNode<T> * temp,*deDbNode;
		temp = head;
		for(int i = 1;i < Index;i++)
			temp = temp->right;//�ҵ�ǰһ��λ�� 
	 	deDbNode = temp->right;
	 	deDbNode->right->left = deDbNode->left;
	 	temp->right = deDbNode->right;
		delete deDbNode;
		head->data--;
	}
	else
		cout<<"�������������"<<endl;

}
template <class T>
T DbLinkList<T> :: search(int Index) const
{
	DbNode<T> * temp;
	if( (this->head->data) < Index )
	{cout<<"��������û�д�����"<<endl;return NULL;}
	else
	{
		temp = head; 
		for(int i = 1;i < Index;i++)
			temp = temp->right;//�ҵ�ǰһ��λ�� 
		return temp->right->data;
	}


}
template <class T>
void DbLinkList<T> :: display() const
{
	DbNode<T> * temp;
	temp = head->right;
	while(temp)
	{
		cout<<temp->data<<endl;
		temp = temp->right;
	}
}
template <class T>
int DbLinkList<T> :: getLength()
{
	return this->head->data;

}
#endif
