//�����㷨ʱ��Ƚ�
#include<iostream>
#include<fstream>
#include<ctime>
#include<stdlib.h>
#include "myRandom.h"
#include "mySort.h" 
#include "myFile.h"
using namespace std;
void Menu(); 
int main(void)
{
	
	int *data,n=900,select;
	clock_t s,e;
	while(1)
	{ 
		Menu();
		cin>>select;
		switch(select)
		{
			case 1:	cout<<"���������������"<<endl;
					cin>>n;
					data = new int [n];
/*
 					cout<<"�����������������Χ"<<endl;
 					cin>>start>>end; */
		 			//��������� 
					myRandom(1,2*n,n,data);					
					//printArray(data,n);
					//������д���ļ�Rtest.txt 
					wFile("Rtest.txt",data,n); break;
			case 2:/*
					rFile("Rtest.txt",data,n);
					//ð�� 
					s = clock();
					bubbleSort(data,n);
					e = clock();
					cout<<e-s<<endl;*/
					/*
					rFile("Rtest.txt",data,n);
					//���� 
					s = clock();
					insertSort(data,n);
					e = clock();
					cout<<e-s<<endl;
					rFile("Rtest.txt",data,n);
					//ѡ�� 
					s = clock();
					selectSort(data,n);
					e = clock();
					cout<<e-s<<endl;*/
					
					//ϣ�� 
					rFile("Rtest.txt",data,n);	
					cout<<"shellSort����ʱ��"<<endl;				
					s = clock();
					shellSort(data,n);
					e = clock();			
					cout<<e-s<<" ms"<<endl;
					
					//�鲢 
					rFile("Rtest.txt",data,n);
					cout<<"mergeSort����ʱ��"<<endl;
					s = clock();
					mergeSort( data, n);
					e = clock();			
					cout<<e-s<<" ms"<<endl;
					
					//���� 
					rFile("Rtest.txt",data,n);
					cout<<"quickSort����ʱ��"<<endl;
					s = clock();
					quickSort(data,n);
					e = clock();			
					cout<<e-s<<" ms"<<endl;
					
					//������
					rFile("Rtest.txt",data,n);
					
					{
						binaryHeap< int > a(data,n);
						cout<<"heapSort����ʱ��"<<endl;
						s = clock();
						heapSort(a,data,n);
						e = clock();
						//printArray(data,n);			
						cout<<e-s<<" ms"<<endl;
					}
					
					
					delete [] data;
					break;
			case 3: return 0;
			default:cout<<"������1~3֮��Ĺ���"<<endl;
		}

	} 
	return 0;
}

void Menu()
{

	cout<<"*********DSAA experiment3**********"<<endl;

	cout<<"************************by WangHui*"<<endl;
	
	cout<<"          1 ����������ļ�"<<endl;
	cout<<"          2 ���ø�����Ƚ�ʱ��"<<endl;

	cout<<"          3 EXIT"<<endl;
		 
}

 