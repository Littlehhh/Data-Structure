#ifndef myFile_H
#define myFile_H

#include<iostream>
#include<fstream>
using namespace std;
//������д���ļ�Rtest.txt 
void wFile(string Filename,int Enter[],int n)
{
	fstream file;
	file.open(Filename,ios::out);
	if(!file)
	{
		cout<<"���ļ�ʧ��"<<endl;
		return; 
	}
	for(int i=0;i<n;i++)
		file<<Enter[i]<<"  ";
	file.close();
}
//��Rtest.txt���������
void rFile(string Filename,int data[],int n)	
{	 
	fstream file;
	file.open(Filename,ios::in);
	if(!file)
	{
		cout<<"���ļ�ʧ��"<<endl;
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