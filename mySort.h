#ifndef mySort_H
#define mySort_H
#include<iostream>
#include<stdio.h>
//´òÓ¡Êı×é 
void printArray(int data[] , int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%4d",data[i]);
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
//Ã°ÅİÅÅĞò 
void bubbleSort(int data[], int n)
{


    for(int i=0; i<n-1; i++)
        for( int j = n-1; j >= i; j--)
        {
            if( data[j] > data[j+1] )
            {
                swap(data[j],data[j+1]);
				/*data[j] = data[j] ^ data[j+1];
                data[j+1] = data[j] ^ data[j+1];
                data[j] = data[j] ^ data[j+1];*/
            }
        }
}
//²åÈëÅÅĞò 
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
//Ñ¡ÔñÅÅĞò 
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



#endif
