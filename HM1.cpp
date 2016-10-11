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
			case 1:	cout<<"请输入随机数个数"<<endl;
					cin>>n;
 					cout<<"请输入随机数产生范围"<<endl;
 					cin>>start>>end; 
		 			//生成随机数 
					myRandom(start,end,n,Enter);					
					printArray(Enter,n);
					//将数组写入文件Rtest.txt 
					wFile("Rtest.txt",Enter,n); break;
			case 2:	//从Rtest.txt读出随机数
					rFile("Rtest.txt",data,n);
					//求最大最小 
					Min = sMin(data,n);cout<<"Min = "<<Min<<endl;
					Max = sMax(data,n);cout<<"Max = "<<Max<<endl;break; 
			case 3:	rFile("Rtest.txt",data,n);
					//冒泡 
					bubbleSort(data,n);
					printArray(data,n);break;
			case 4: rFile("Rtest.txt",data,n);
					//插入 
					insertSort(data,n);
					printArray(data,n);break;
			case 5: rFile("Rtest.txt",data,n);
					//选择 
					selectSort(data,n);
					printArray(data,n);break;
			case 6: rFile("Rtest.txt",data,n);
					//希尔 
					shellSort(data,n);
					printArray(data,n);break;			
			case 7: wFile("Result.txt",data,n);break;	
			case 8: return;
			default:cout<<"请输入1~8之间的功能"<<endl;
		}

	} 
}

void Menu()
{

	cout<<"*********DSAA experiment2**********"<<endl;

	cout<<"************************by WangHui*"<<endl;
	
	cout<<"          1 生成随机数"<<endl;
	cout<<"          2 输出Max，Min"<<endl;
	cout<<"          3 bubbleSort"<<endl;
	cout<<"          4 insertSort"<<endl;
	cout<<"          5 selectSort"<<endl;
	cout<<"          6 shellSort"<<endl;
	cout<<"          7 保存排序结果"<<endl;
	cout<<"          8 EXIT"<<endl;
		 
}

