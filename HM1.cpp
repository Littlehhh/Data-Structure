#include<iostream>
#include<fstream>
#include "myRandom.h"
#include "mySort.h" 
#include "myFile.h"
using namespace std;

void main()
{
	int Enter[1000],data[1000],n,start,end;
	cout<<"请输入随机数个数"<<endl;
	cin>>n;
 	cout<<"请输入随机数产生范围"<<endl;
 	cin>>start>>end;
 	//生成随机数 
	myRandom(start,end,n,Enter);
	//将数组写入文件Rtest.txt 
	wFile("Rtest.txt",Enter,n); 
	//从Rtest.txt读出随机数
	rFile("Rtest.txt",data,n); 
	printArray(data,n);
	//排序部分
	bubbleSort(data,n);
	insertSort(data,n);
	selectSort(data,n);	
	//打印数组 
	printArray(data,n);
	wFile("Result.txt",data,n);
}

