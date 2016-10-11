#ifndef myRandom_H
#define myRandom_H
#include <iostream>     
#include <ctime>  
#include <cstdio>  
//用于产生随机数      
using namespace std;  
      
void myRandom(int start,int end,int num,int array[])  
{  
	srand(unsigned(time(0)));
	for(int i=0;i<num;i++)  
	{  
		array[i] = start+rand()%(end-start+1);   
	}  
}  

#endif
