#include<iostream>
#include<fstream>
#include<ctime>
#include "myRandom.h"
#include "mySort.h" 
#include "myFile.h"
using namespace std;
void Menu(); 
void main()
{
	
	int Enter[1000],data[1000],n=900,start,end,select,Max,Min;
	while(1)
	{ 
		Menu();
		cin>>select;
		switch(select)
		{
			case 1:	cout<<"���������������"<<endl;
					cin>>n;
 					cout<<"�����������������Χ"<<endl;
 					cin>>start>>end; 
		 			//��������� 
					myRandom(start,end,n,Enter);					
					printArray(Enter,n);
					//������д���ļ�Rtest.txt 
					wFile("Rtest.txt",Enter,n); break;
			case 2:	//��Rtest.txt���������
					rFile("Rtest.txt",data,n);
					//�������С 
					Min = sMin(data,n);cout<<"Min = "<<Min<<endl;
					Max = sMax(data,n);cout<<"Max = "<<Max<<endl;break; 
			case 3:	rFile("Rtest.txt",data,n);
					//ð�� 
					bubbleSort(data,n);
					printArray(data,n);break;
			case 4: rFile("Rtest.txt",data,n);
					//���� 
					insertSort(data,n);
					printArray(data,n);break;
			case 5: rFile("Rtest.txt",data,n);
					//ѡ�� 
					selectSort(data,n);
					printArray(data,n);break;
			case 6: rFile("Rtest.txt",data,n);
					//ϣ�� 
					shellSort(data,n);
					printArray(data,n);break;			
			case 7: wFile("Result.txt",data,n);break;	
			case 8: return;
			default:cout<<"������1~8֮��Ĺ���"<<endl;
		}

	} 
}

void Menu()
{

	cout<<"*********DSAA experiment2**********"<<endl;

	cout<<"************************by WangHui*"<<endl;
	
	cout<<"          1 ���������"<<endl;
	cout<<"          2 ���Max��Min"<<endl;
	cout<<"          3 bubbleSort"<<endl;
	cout<<"          4 insertSort"<<endl;
	cout<<"          5 selectSort"<<endl;
	cout<<"          6 shellSort"<<endl;
	cout<<"          7 ����������"<<endl;
	cout<<"          8 EXIT"<<endl;
		 
}

