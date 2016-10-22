//»ùÓÚÕ»µÝ¹éµÄººÅµËþ
#include <iostream>
#include "myLinkList.h"
#include "myStackDerived.h"
//#include "myRandom.h"
using namespace std;
template <class T>
void hannoi(int n,Stack<T> *src,Stack<T> *temp,Stack<T> *tar)
{
	int Temp;
	if(n==1)
	{
		Temp = src->pop();
		tar->push(Temp);		
	}
	else
	{
		hannoi(n-1,src,tar,temp);
		hannoi(1,src,temp,tar);
		hannoi(n-1,temp,src,tar);	
	}
}
void main()
{
	int a[] = {8,7,6,5,4,3,2,1};
	Stack<int> *src,*tar,*temp;
	src = new Stack<int> (a,8);
	tar = new Stack<int>;
	temp = new Stack<int>;
	hannoi(8,src,temp,tar);
	tar->display();
}



 