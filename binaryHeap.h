//优先队列的实现
#ifndef binaryHeap_H
#define binaryHeap_H
 
#include <iostream>
#include <vector>
using namespace std;

template<class Comparable> 
class binaryHeap{
	private:
		vector<Comparable> array;
		int currentSize;
		void buildHeap()
  		{
        	for( int i = currentSize / 2; i > 0; --i )
            	percolateDown( i );
    	}
		void percolateDown( int hole );
		
	public:
		explicit binaryHeap( const vector<Comparable> & items)
 		 : array( items.size( ) + 10 ), currentSize( items.size( ) )
	    {
	        for( int i = 0; i < items.size( ); ++i )
	            array[ i + 1 ] = items[ i ];
	        buildHeap( );
	    }
	    binaryHeap( Comparable *items , int n)
	    : array( n + 10 ), currentSize(n)  
		{
  			for( int i = 0; i < n; ++i )
	            array[ i + 1 ] = items[ i ];
	        buildHeap( );
		}
		bool isEmpty() const
		{ return currentSize == 0; }
		const Comparable & findMin() const
		{	
			if( isEmpty( ) )
				return;
			return array[1];
		}
		void insert( const Comparable & x);
		void deleteMin();
		void deleteMin( Comparable & minItem );
		void makeEmpty()
		{ currentSize = 0; }  
};
//implemention 
template<class Comparable> 
void binaryHeap<Comparable> :: insert(const Comparable & x)
{
	if( currentSize == array.size() -1 )
		array.resize( array.size() * 2 );
		//上滤   percolate up
	int hole = ++currentSize;
	for( ;hole>1 && x<array[ hole/2 ] ; hole/2 )
		array[ hole ] = array[ hole/2 ];
	array[ hole ] = x;

}
template<class Comparable> 
void binaryHeap<Comparable> :: deleteMin()
{
	if( isEmpty() )
		return;
	
	array[1] = array[ currentSize-- ]; 
	percolateDown( 1 );
}
template<class Comparable> 
void binaryHeap<Comparable> :: deleteMin(Comparable &minItem)
{
	if( isEmpty() )
		return;	
	minItem = array[ 1 ];
	array[1] = array[ currentSize-- ]; 
	percolateDown( 1 );
}
template<class Comparable> 
void binaryHeap<Comparable> :: percolateDown( int hole )
{
	int child;
	Comparable temp = array[ hole ];

	for( ; hole*2<=currentSize ; hole = child)
	{
		child = hole * 2;
		if( child != currentSize && array[ child + 1] < array[ child ])
			child++;
		if( array[child] < temp)
			array[ hole ] = array[ child ];
		else
			break;
	}	
	array[ hole ] = temp;
}



#endif



