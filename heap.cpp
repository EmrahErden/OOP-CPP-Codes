/*
There’s another kind of memory that persists independent of the
functions in a program. You, the programmer, are in charge of allocating and
freeing this memory, collectively called the heap (or free store).

The heap also allows you to create an object in one function that you
can access even after that function ends (without having to return a 
copy of the object)
*/

#include <iostream>

using namespace std;

int* intOnHeap(void);	//returns an int on the heap memmory
//void leak1(void);	//creates memmory leak
//void leak2(void);
int main(void)
{
	int* pHeap = new int;	//The new int part of the statement 
				//allocates enough memory on the heap for one
				//int and returns the address on the heap 
				//for that chunk of memory

				//***pHeap points to a piece of memory on 
				//the heap, not the stack.***
	*pHeap = 10;
	cout << "*pHeap : " << *pHeap << "\n";
	int* pHeap2 = intOnHeap();
	cout << "pHeap2 : " << *pHeap2 << "\n";
	cout << "freeing memory pointed by pHeap\n";
	delete pHeap;
	cout << "freeing memory pointed by pHeap2\n";
	delete pHeap2;
	pHeap = pHeap2 = 0;
/*
Unlike storage for local variables on the stack, memory that you’ve allocated on
the heap must be explicitly freed. When you’re finished with memory that
you’ve allocated with new , you should free it with delete .

Another good way to deal with a dangling pointer is to assign a valid memory
address to it.
*/
}

int* intOnHeap(void)
{
	int* pTemp = new int(20);
	return pTemp;
}
