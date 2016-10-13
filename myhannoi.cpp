//经典汉诺塔问题 
//典型分治策略，从分治角度去理解更为清晰
#include<iostream>

using namespace std;
void hannoi(int n,char A,char B,char C)     
{
	if(n == 1)
		//最小的子问题(递归基) 
		cout<<"Move the "<<n<<" from "<<A<<" to "<<C<<endl;
	else	//将 "把盘子从A移到C" 这个大问题分成几个小问题 
	{
		hannoi(n-1,A,C,B);	//第一个小问题  "将n-1个盘子从A移到B" 
		cout<<"Move the "<<n<<" from "<<A<<" to "<<C<<endl;
		//第二个小问题 "将第n个盘子从A移到C" 
		hannoi(n-1,B,A,C);	//第三个小问题 "将n-1个盘子从B移到C" 
		
		//而每一个小问题又分解为他们各自的小问题 
		//最后达到解决问题的目标
		//而他们的最小的子问题就是一开始的把一个盘子从A移到C
		//这个最小的子问题可以称为递归基 
	}

}

void main()
{
    int n;
    cin >> n;

    hannoi (n, 'A', 'B', 'C');
} 



