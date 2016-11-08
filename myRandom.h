#ifndef myRandom_H_
#define myRandom_H_
#include <iostream>     
#include <ctime>  
#include <cstdio>  
#include <vector>      
using namespace std;  
      
void myRandom(int start,int end,int num,int array[])  
{  
	srand(unsigned(time(0)));
	for(int i=0;i<num;i++)  
	{  
		array[i] = start+rand()%(end-start+1);   
	}  
}  


void myRandom(int start,int end,int num,vector<int> &array)  
{  
	srand(unsigned(time(0)));
	for(int i=0;i<num;i++)  
	{  
		array[i] = start+rand()%(end-start+1);   
	}  
}
#endif
