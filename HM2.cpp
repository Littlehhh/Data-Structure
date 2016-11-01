#include<iostream>
#include"myLinkList.h"
#include"myQueueDerived.h"
#include"myStackDerived.h"

using namespace std;

void Menu();
void Menu2();
void Menu3();
void Menu4();


void main()
{
	int select,data,Index,flag=0;
	int a[] = {5,2,3,5,6,8};
	Queue<int> q1(a,(sizeof(a)/sizeof(a[0])));
	Stack<int> s1(a,(sizeof(a)/sizeof(a[0])));
	LinkList<int> l1(a,(sizeof(a)/sizeof(a[0])));
	LinkList<int> * index;
	while(1)	
	{	
		Menu();
		cin>>select;
		switch(select)
		{
			case 1:	while(1)
					{	
						Menu2();
						cin>>select;
						switch(select)
						{
							case 1:	cout<<"Enter the Data"<<endl;cin>>data;q1.EnQueue(data);break;
							case 2:	q1.DeQueue();break; 
							case 3:	q1.display();break;
							case 4: cout<<"Enter the Data"<<endl;cin>>data;
									index=q1.searchData(data);
									cout<<"该数据所在索引为："<<endl; 
									index->display();
									index->~LinkList();break;
							case 5: flag = 1;break;
							default:cout<<"请输入1~5之间的功能"<<endl;
						}
						if(flag == 1)
							break;
					}
					break;
			case 2:	while(1)
					{
						Menu3();
						cin>>select;
						switch(select)
						{
							case 1:	cout<<"Enter the Data"<<endl;cin>>data;s1.push(data);break;
							case 2:	s1.pop();break; 
							case 3:	s1.display();break;
							case 4: cout<<"Enter the Data"<<endl;cin>>data;
									index=s1.searchData(data);
									cout<<"该数据所在索引为："<<endl;
									index->display();
									index->~LinkList();break;
							case 5: flag = 1;break;
							default:cout<<"请输入1~5之间的功能"<<endl;
						}
						if(flag == 1)
							break;
					}
					break; 
			case 3:	while(1)
					{
						Menu4();				
						cin>>select;
						switch(select)
						{
							case 1:	cout<<"Enter the Data"<<endl;cin>>data;l1.InsertAtTail(data);break;
							case 2:	cout<<"Enter the Index"<<endl;cin>>Index;l1.Delete(Index);break; 
							case 3:	l1.display();break;
							case 4: cout<<"Enter the Data"<<endl;cin>>data;
									index=l1.searchData(data);
									cout<<"该数据所在索引为："<<endl; 
									index->display();
									index->~LinkList();break;
							case 5: l1.Inversion();break;
							case 6: flag = 1;break;
							default:cout<<"请输入1~6之间的功能"<<endl;
						}
						if(flag == 1)
							break;
					}
					break;
			case 4: return;
			default:cout<<"请输入1~4之间的功能"<<endl;
		}
		flag = 0;
	}
}
void Menu()
{
 
	cout<<"\t\t\t*********DSAA Experiment3**********"<<endl;
	cout<<"\t\t\t***********************************"<<endl;
	cout<<"\t\t\t************************by WangHui*"<<endl;
	
	cout<<"\t\t\t          1 Queue"<<endl;
	cout<<"\t\t\t          2 Stack"<<endl;
	cout<<"\t\t\t          3 List"<<endl;
	cout<<"\t\t\t          4 Exit"<<endl;

}
void Menu2()
{
	cout<<"\t\t\t          1 EnQueue"<<endl;
	cout<<"\t\t\t          2 Dequeue"<<endl;
	cout<<"\t\t\t          3 Display"<<endl;
	cout<<"\t\t\t          4 Search"<<endl;
	cout<<"\t\t\t          5 EXIT"<<endl;
}
void Menu3()
{
	cout<<"\t\t\t          1 Push"<<endl;
	cout<<"\t\t\t          2 Pop"<<endl;
	cout<<"\t\t\t          3 Display"<<endl;
	cout<<"\t\t\t          4 Search"<<endl;
	cout<<"\t\t\t          5 EXIT"<<endl;
}
void Menu4()
{
	cout<<"\t\t\t          1 Insert"<<endl;
	cout<<"\t\t\t          2 Delete"<<endl;
	cout<<"\t\t\t          3 Display"<<endl;
	cout<<"\t\t\t          4 Search"<<endl;
	cout<<"\t\t\t          5 Inversion"<<endl;
	cout<<"\t\t\t          6 EXIT"<<endl;
}


