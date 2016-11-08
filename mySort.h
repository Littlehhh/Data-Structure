#ifndef mySort_H
#define mySort_H
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
//求最大值
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

//打印数组 
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
//冒泡排序 
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
//插入排序 
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
//选择排序 
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
//希尔排序
//使用希尔增量
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



//归并排序
void merge( vector<int> &a, vector<int> &temp, int leftPos, int rightPos, int rightEnd)
{
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while( leftPos <= leftEnd && rightPos <= rightEnd )
        if( a[ leftPos ] <= a[ rightPos ] )
            temp[ tmpPos++ ] = std::move( a[ leftPos++ ] );
        else
            temp[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    while( leftPos <= leftEnd )
        temp[ tmpPos++ ] = std::move( a[ leftPos++ ] );

    while( rightPos <= rightEnd )
        temp[ tmpPos++ ] = std::move( a[ rightPos++ ] );

    for( int i = 0; i < numElements; ++i, --rightEnd )
        a[ rightEnd ] = std::move( temp[ rightEnd ] );	
} 
void mergeSort( vector<int> &a, vector<int> &temp, int left,int right)
{
	if(left < right)
	{
		int center = (left + right) / 2;
		mergeSort( a,temp,left,center);
		mergeSort( a,temp,center+1,right);	
		merge( a,temp,left,center+1,right );
	}
}

void mergeSort( vector< int > & a )
{
    vector< int > tmpArray( a.size( ) );

    mergeSort( a, tmpArray, 0, a.size( ) - 1 );
}

#endif
