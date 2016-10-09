#ifndef myFile_H
#define myFile_H

#include<iostream>
#include<fstream>
using namespace std;
//将数组写入文件Rtest.txt 
void wFile(string Filename,int Enter[],int n)
{
	fstream file;
	file.open(Filename,ios::out);
	if(!file)
	{
		cout<<"打开文件失败"<<endl;
		return; 
	}
	for(int i=0;i<n;i++)
		file<<Enter[i]<<"  ";
	file.close();
}
//从Rtest.txt读出随机数
void rFile(string Filename,int data[],int n)	
{	 
	fstream file;
	file.open(Filename,ios::in);
	if(!file)
	{
		cout<<"打开文件失败"<<endl;
		return; 
	}
	for(int i=0;i<n;i++)
	{
		file>>data[i];
		//cout<<NUM<<"    "<<data[i]<<endl;
	}
	file.close();
}
#endif