//���人ŵ������ 
//���ͷ��β��ԣ��ӷ��νǶ�ȥ����Ϊ����
#include<iostream>

using namespace std;
void hannoi(int n,char A,char B,char C)     
{
	if(n == 1)
		//��С��������(�ݹ��) 
		cout<<"Move the "<<n<<" from "<<A<<" to "<<C<<endl;
	else	//�� "�����Ӵ�A�Ƶ�C" ���������ֳɼ���С���� 
	{
		hannoi(n-1,A,C,B);	//��һ��С����  "��n-1�����Ӵ�A�Ƶ�B" 
		cout<<"Move the "<<n<<" from "<<A<<" to "<<C<<endl;
		//�ڶ���С���� "����n�����Ӵ�A�Ƶ�C" 
		hannoi(n-1,B,A,C);	//������С���� "��n-1�����Ӵ�B�Ƶ�C" 
		
		//��ÿһ��С�����ַֽ�Ϊ���Ǹ��Ե�С���� 
		//���ﵽ��������Ŀ��
		//�����ǵ���С�����������һ��ʼ�İ�һ�����Ӵ�A�Ƶ�C
		//�����С����������Գ�Ϊ�ݹ�� 
	}

}

void main()
{
    int n;
    cin >> n;

    hannoi (n, 'A', 'B', 'C');
} 



