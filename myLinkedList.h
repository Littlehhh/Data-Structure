#ifndef myLinkedList_H
#define myLinkedList_H
using namespace std; 
template <class T>
struct Node
{
  T data;
  Node<T> * next;  			//�˴�<T>Ҳ����ʡ��
};

template <class T>
class LinkList
{
  	public:
    	LinkList( );  			//����ֻ��ͷ���Ŀ�����
    	LinkList(T a[ ]);  		//������n��Ԫ�صĵ�����
    	~LinkList();            //��������
		int getArrayLen(T &a);
		int Length();          	//������ĳ���
    	T Get(int i);           //ȡ�������е�i������Ԫ��ֵ
    	int Locate(T x);       	//��������ֵΪx��Ԫ�����
    	void Insert(int i, T x);   //�ڵ������е�i��λ�ò���Ԫ��ֵΪx�Ľ��
    	T Delete(int i);        	//�ڵ�������ɾ����i�����
    	void PrintList( );          //������������������������Ԫ��
 	private:
   		Node<T> *first;  			//�������ͷָ��
};


//*��    �ܣ�����һ��������
template <class T>
LinkList<T> :: LinkList()
{
 	first = new Node<T>; 
 	first->next = NULL;
}
//�ú�������������array�ĳ���
template <class T>
int LinkList<T>::getArrayLen(T	&a)
{
	return (sizeof(array) / sizeof(array[0]));
}

//*��    �ܣ�������a[]��Ԫ�ؽ�Ϊ����Ϊn�ĵ�����
template <class T>  
LinkList<T> :: LinkList(T a[ ])
{
    int n;
	first=new Node<T>;     //����ͷ���
	Node <T> *r,*s;
 	r=first;              //βָ���ʼ��
 	n = getArrayLen(T a[]);
    for (int i=0; i<n; i++)
	{ 
      	s = new Node<T>; 
	  	s->data = a[i];  //Ϊÿ������Ԫ�ؽ���һ�����
      	r->next = s;
		r = s;      //���뵽�ն˽��֮��
	}
    r->next= NULL;    //����������ϣ����ն˽���ָ�����ÿ�
}

//�������� 
template <class T>
LinkList<T> :: ~LinkList()
{
}

//��λ����λ��Ϊi��Ԫ�ز����ֵ

template <class T>
T LinkList<T> :: Get(int i) 
{   
	Node<T> *p; int j;
  	p=first->next;  
  	j=1;  //��p=first;  j=0;
  	while (p && j<i)    
  	{
    	p=p->next;       
    	j++;
  	}
 	return p->data;
}

//��ֵ����ֵ��Ԫ�ز����λ��

template <class T> 
int LinkList<T>::Locate(T x)
{
	Node<T> *p; int j;
	p=first->next; 
	j=1;
	if(p && p->next)
	{
	  	while(p->data!=x)
	  	{
		 	p=p->next;
	     	j++;
	  	}
		return j;
	}
	else
		cout<<"�޴�Ԫ��"<<endl; 
	
}


//��Ԫ��x���뵽��������λ��i��

template <class T>  
void LinkList<T>::Insert(int i, T x)
{  
	Node<T> *p; int j;
   	p = first ; j=0;    
   	while (p && j<i-1)
   	{
     	p=p->next;   
     	j++;
   	}
	
	Node<T> *s;
	s=new Node<T>; 
 	s->data=x;  //���ڴ�����һ�����s����������Ϊx
    s->next=p->next;       //�����s���뵽���p֮��
    p->next=s;

}


//�����������
template <class T> 
int LinkList<T>::Length( )
{
  Node <T> * p = first->next;
  int i = 0;
  while(p)
  {
	p = p->next;
    i++;
  }
  return i;
}

//ɾ��Ԫ�� 

template <class T>  
T LinkList<T>::Delete(int i)
{ 
  	Node<T> *p; int j;
  	p=first; 
  	j=0;  //����ָ��p��ʼ��
  	while (p && j<i-1)  //���ҵ�i-1�����
  	{
   	 	p=p->next;
    	j++;
  	}
  	if (!p || !p->next) 
  		cout<<"�����ڴ˽��"<<endl; //���p�����ڻ���p�ĺ�̽�㲻����
    else 
	{
		  Node<T> *q; int x;
          q=p->next; x=q->data;  //�ݴ汻ɾ���
          p->next=q->next;  //ժ��
          delete q; 
          return x;
	}
}


//�������Ԫ��

template <class T> 
void LinkList<T>::PrintList( )
{
	Node<T> *p;
	p=first->next;
	while (p)
	{
	  cout<<p->data<<endl;
	  p=p->next;
	}
	
}

#endif