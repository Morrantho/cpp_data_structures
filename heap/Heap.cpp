#include "Heap.h"
#include <cmath>
#include <iostream>
// MINHEAP
template<typename T, int N>
Heap<T,N>::Heap()
{

}

template<typename T, int N>
Heap<T,N>::~Heap()
{
	for( int i=0; i < N; i++ )
		if( table[i] == 0 ) delete table[i];
}

// log 2n, kinda
template<typename T, int N>
void Heap<T,N>::Insert(T value)
{
	int index = N-1;
	if(table[1] == 0){ table[1] = new T(value); return; } // First index null? Assign it.
	while( table[index] == 0 ) index--; // Decrement until not null.
	if(index+1 > N) return; // Heap is full.
	table[++index] = new T(value); // Assign at next null.

	while(index > 0)
	{
		int parent = (int)floor(index/2);
		if(table[ parent ] != 0)
		{
			if( *table[index] < *table[parent] )
			{
				T* t = table[index];
				table[index] = table[parent];
				table[parent] = t;
			}
		}
		index = parent;
	}
}

// TODO
template<typename T, int N>
T* Heap<T,N>::Extract()
{

	return 0;
}

// 1/2n
template<typename T, int N>
bool Heap<T,N>::Contains(T value)
{
	for( int i = 1, j = N-1; i < j; i++, j--)
		if( table[i] != 0 )
			if(*table[i] == value) return true;
		if( table[j] != 0 )
			if(*table[j] == value) return true;
	return false;
}