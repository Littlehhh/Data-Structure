//test mySort
#include<iostream>
#include<vector>
#include"mySort.h"
#include"myRandom.h"
using namespace std;
void main()
{
	vector<int> a(10);myRandom(1,20,10,a);
	for(vector<int>::iterator it = a.begin();it!=a.end();++it)  
    {  
        cout<<*it<<" ";   
    }  
    cout<<endl;  
	
	mergeSort(a);
	
 	for(vector<int>::iterator it = a.begin();it!=a.end();++it)  
    {  
        cout<<*it<<" ";  
    }  
    cout<<endl;  


}

