#include<iostream>
#include<fstream>
#include "myRandom.h"
#include "mySort.h" 
#include "myFile.h"
using namespace std;

void main()
{
	int Enter[1000],data[1000],n,start,end;
	cout<<"���������������"<<endl;
	cin>>n;
 	cout<<"�����������������Χ"<<endl;
 	cin>>start>>end;
 	//��������� 
	myRandom(start,end,n,Enter);
	//������д���ļ�Rtest.txt 
	wFile("Rtest.txt",Enter,n); 
	//��Rtest.txt���������
	rFile("Rtest.txt",data,n); 
	printArray(data,n);
	//���򲿷�
	bubbleSort(data,n);
	insertSort(data,n);
	selectSort(data,n);	
	//��ӡ���� 
	printArray(data,n);
	wFile("Result.txt",data,n);
}

