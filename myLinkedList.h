#ifndef myLinkedList_H
#define myLinkedList_H
using namespace std; 
template <class T>
struct Node
{
  T data;
  Node<T> * next;  			//此处<T>也可以省略
};

template <class T>
class LinkList
{
  	public:
    	LinkList( );  			//建立只有头结点的空链表
    	LinkList(T a[ ]);  		//建立有n个元素的单链表
    	~LinkList();            //析构函数
		int getArrayLen(T &a);
		int Length();          	//求单链表的长度
    	T Get(int i);           //取单链表中第i个结点的元素值
    	int Locate(T x);       	//求单链表中值为x的元素序号
    	void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
    	T Delete(int i);        	//在单链表中删除第i个结点
    	void PrintList( );          //遍历单链表，按序号依次输出各元素
 	private:
   		Node<T> *first;  			//单链表的头指针
};


//*功    能：构建一个单链表
template <class T>
LinkList<T> :: LinkList()
{
 	first = new Node<T>; 
 	first->next = NULL;
}
//该函数将返回数组array的长度
template <class T>
int LinkList<T>::getArrayLen(T	&a)
{
	return (sizeof(array) / sizeof(array[0]));
}

//*功    能：将数组a[]中元素建为长度为n的单链表
template <class T>  
LinkList<T> :: LinkList(T a[ ])
{
    int n;
	first=new Node<T>;     //生成头结点
	Node <T> *r,*s;
 	r=first;              //尾指针初始化
 	n = getArrayLen(T a[]);
    for (int i=0; i<n; i++)
	{ 
      	s = new Node<T>; 
	  	s->data = a[i];  //为每个数组元素建立一个结点
      	r->next = s;
		r = s;      //插入到终端结点之后
	}
    r->next= NULL;    //单链表建立完毕，将终端结点的指针域置空
}

//析构函数 
template <class T>
LinkList<T> :: ~LinkList()
{
}

//按位查找位置为i的元素并输出值

template <class T>
T LinkList<T> :: Get(int i) 
{   
	Node<T> *p; int j;
  	p=first->next;  
  	j=1;  //或p=first;  j=0;
  	while (p && j<i)    
  	{
    	p=p->next;       
    	j++;
  	}
 	return p->data;
}

//按值查找值的元素并输出位置

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
		cout<<"无此元素"<<endl; 
	
}


//将元素x插入到单链表中位置i处

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
 	s->data=x;  //向内存申请一个结点s，其数据域为x
    s->next=p->next;       //将结点s插入到结点p之后
    p->next=s;

}


//输出单链表长度
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

//删除元素 

template <class T>  
T LinkList<T>::Delete(int i)
{ 
  	Node<T> *p; int j;
  	p=first; 
  	j=0;  //工作指针p初始化
  	while (p && j<i-1)  //查找第i-1个结点
  	{
   	 	p=p->next;
    	j++;
  	}
  	if (!p || !p->next) 
  		cout<<"不存在此结点"<<endl; //结点p不存在或结点p的后继结点不存在
    else 
	{
		  Node<T> *q; int x;
          q=p->next; x=q->data;  //暂存被删结点
          p->next=q->next;  //摘链
          delete q; 
          return x;
	}
}


//输出所有元素

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