#include<iostream>
using namespace std;

class Clock
{
	public:
		Clock(int newH=0,int newM=0,int newS=0)  //C++里面可以有参数默认避免了java中的类似构造函数重载 
		{
			H = newH;
			M = newM;
			S = newS;
		}
		
	//	Clock()
	//	{
	//		this->Clock(0,0,0);//这样在C++里是不被允许的； 
			//H = 0;
			//	M = 0;
			//	S = 0;
	//	}
	
		Clock(Clock &c)
		{
			H = c.H;
			M = c.M;
			S = c.S;
		} 
		void setTime(int newH,int newM,int newS);
		void showTime();
	private:
		int H,M,S;
}; 

void Clock::setTime(int newH,int newM,int newS)
{
	H = newH;
	M = newM;
	S = newS;
}
void Clock::showTime()
{
	cout<<H<<":"<<M<<":"<<S<<endl;
}

int main()
{
	Clock New1;
	New1.showTime();
	Clock New2=New1;
	New2.showTime();
	Clock New(7,8,9);
	New.showTime();
	New.setTime(1,2,3);
	New.showTime();
	return 0;
}

