//排序算法时间比较
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
			case 1:	cout<<"请输入随机数个数"<<endl;
					cin>>n;
					data = new int [n];
/*
 					cout<<"请输入随机数产生范围"<<endl;
 					cin>>start>>end; */
		 			//生成随机数 
					myRandom(1,2*n,n,data);					
					//printArray(data,n);
					//将数组写入文件Rtest.txt 
					wFile("Rtest.txt",data,n); break;
			case 2:/*
					rFile("Rtest.txt",data,n);
					//冒泡 
					s = clock();
					bubbleSort(data,n);
					e = clock();
					cout<<e-s<<endl;*/
					/*
					rFile("Rtest.txt",data,n);
					//插入 
					s = clock();
					insertSort(data,n);
					e = clock();
					cout<<e-s<<endl;
					rFile("Rtest.txt",data,n);
					//选择 
					s = clock();
					selectSort(data,n);
					e = clock();
					cout<<e-s<<endl;*/
					
					//希尔 
					rFile("Rtest.txt",data,n);	
					cout<<"shellSort花费时间"<<endl;				
					s = clock();
					shellSort(data,n);
					e = clock();			
					cout<<e-s<<" ms"<<endl;
					
					//归并 
					rFile("Rtest.txt",data,n);
					cout<<"mergeSort花费时间"<<endl;
					s = clock();
					mergeSort( data, n);
					e = clock();			
					cout<<e-s<<" ms"<<endl;
					
					//快排 
					rFile("Rtest.txt",data,n);
					cout<<"quickSort花费时间"<<endl;
					s = clock();
					quickSort(data,n);
					e = clock();			
					cout<<e-s<<" ms"<<endl;
					
					//堆排序
					rFile("Rtest.txt",data,n);
					
					{
						binaryHeap< int > a(data,n);
						cout<<"heapSort花费时间"<<endl;
						s = clock();
						heapSort(a,data,n);
						e = clock();
						//printArray(data,n);			
						cout<<e-s<<" ms"<<endl;
					}
					
					
					delete [] data;
					break;
			case 3: return 0;
			default:cout<<"请输入1~3之间的功能"<<endl;
		}

	} 
	return 0;
}

void Menu()
{

	cout<<"*********DSAA experiment3**********"<<endl;

	cout<<"************************by WangHui*"<<endl;
	
	cout<<"          1 生成随机数文件"<<endl;
	cout<<"          2 调用各排序比较时间"<<endl;

	cout<<"          3 EXIT"<<endl;
		 
}

 