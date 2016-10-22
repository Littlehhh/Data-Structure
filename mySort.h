#ifndef mySort_H
#define mySort_H
#include<iostream>
#include<stdio.h>
//�����ֵ
int sMax(int data[] , int n)
{
	int temp = data[0];
	for(int i = 0; i < n; i++)
	{
		if(temp < data[i])
			temp = data[i];
	}
	return temp;	
}
int sMin(int data[] , int n)
{
	int temp = data[0];
	for(int i = 0; i < n; i++)
	{
		if(temp > data[i])
			temp = data[i];
	}
	return temp;
}

//��ӡ���� 
void printArray(int data[] , int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%6d",data[i]);
    }

    cout<<endl;
}
void swap(int *x,int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp; 
}
//ð������ 
void bubbleSort(int data[], int n)
{


    for(int i=0; i<n-1; i++)
        for( int j = n-2; j >= i; j--)
        {
            if( data[j] > data[j+1] )
            {
				data[j] = data[j] ^ data[j+1];
                data[j+1] = data[j] ^ data[j+1];
                data[j] = data[j] ^ data[j+1];
            }
        }
}
//�������� 
void insertSort(int data[], int n)
{

    for(int i=1; i<n; i++)
    {
        int temp = data[i];
        int j ;
        for( j = i-1; temp < data[j]  && j>=0  ; j--)
             data[j+1] = data[j] ;
        data[j+1] = temp;
    }

}
//ѡ������ 
void selectSort(int data[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min = i;
        for( int j = i+1;  j<n  ; j++)
            if( data[min] > data[j])
                min = j;
         if(min != i)
         {
         	swap(data[i],data[min]);
            /*data[i] = data[i] ^ data[min];
            data[min] = data[i] ^ data[min];
            data[i] = data[i] ^ data[min];*/
         }

    }
}
//ϣ������
//ʹ��ϣ������
void shellSort(int data[], int n)
{	
	int temp,i; 
	for(int Increment = n/2; Increment > 0 ; Increment /=2)
	{
		for(i = Increment;i<n;i++)
		{
			temp = data[i];
			int j=0;
			for(j=i; j>=Increment; j -= Increment)
				if( temp < data[j-Increment] )
					data[j] = data[ j-Increment ];
				else 
					break;
			data[j] = temp;
		 
	 	} 
	
	
	}

}

#endif
