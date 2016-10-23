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
	Queue<int>q1;
	Stack<int>s1;
	LinkList<int>l1;
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
							case 4: break;
							case 5: flag = 1;break;
							default:cout<<"请输入1~4之间的功能"<<endl;
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
							case 4: break;
							case 5: flag = 1;break;
							default:cout<<"请输入1~4之间的功能"<<endl;
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
							case 4: break;
							case 5: flag = 1;break;
							default:cout<<"请输入1~4之间的功能"<<endl;
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
 
	cout<<"*********DSAA experiment3**********"<<endl;

	cout<<"************************by WangHui*"<<endl;
	
	cout<<"          1 Queue"<<endl;
	cout<<"          2 Stack"<<endl;
	cout<<"          3 List"<<endl;
	cout<<"          4 Exit"<<endl;

}
void Menu2()
{
	cout<<"          1 EnQueue"<<endl;
	cout<<"          2 Dequeue"<<endl;
	cout<<"          3 Display"<<endl;
	cout<<"          4 Search"<<endl;
}
void Menu3()
{
	cout<<"          1 Push"<<endl;
	cout<<"          2 Pop"<<endl;
	cout<<"          3 Display"<<endl;
	cout<<"          4 Search"<<endl;
}
void Menu4()
{
	cout<<"          1 Insert"<<endl;
	cout<<"          2 Delete"<<endl;
	cout<<"          3 Display"<<endl;
	cout<<"          4 Search"<<endl;
}


