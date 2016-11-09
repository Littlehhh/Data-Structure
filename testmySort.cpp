//test mySort
#include<iostream>
#include<vector>
#include<time.h>
#include"mySort.h"
#include"myRandom.h"


using namespace std;
void main()
{	
	const int n = 5;
	int aa[n] = {3,1,6,3,7};
	//myRandom(1,2*n,n,aa);
	vector<int> a(aa,aa+n);
	clock_t s1,s2,e1,e2;
	

	for(int i=0;i<n;i++)
	{
		cout<<aa[i]<<" ";	
	}
	cout<<endl;  
	for(vector<int>::iterator it = a.begin();it!=a.end();++it)  
    {  
        cout<<*it<<" ";   
    }  
    cout<<endl;  
    
	s1 = clock();	
	mergeSort(a);
	e1 = clock();
	cout<<e1<<endl;


	
	s2 = clock();
	//mergeSort(aa,n);
	quickSort(aa,n);
	e2 = clock();
	cout<<e2<<endl;

	for(int i=0;i<n;i++)
	{
		cout<<aa[i]<<" ";	
	}
	cout<<endl;
 	for(vector<int>::iterator it = a.begin();it!=a.end();++it)  
    {  
        cout<<*it<<" ";  
    }  
    cout<<endl;  
	cout<<e1<<endl;cout<<e2<<endl;
}

