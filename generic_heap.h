#define HEAP GENERIC(heap)

typedef struct
{
	GENERIC_TYPE *_arr; //Internal array for our circular buffer.
	int len;    //Current size of the array.
	int max;   //Size of the internal array, including the empty space.
} HEAP;

//Returns a new HEAP of length "len."
HEAP GENERIC(new_heap)(GENERIC_TYPE arr[], int len);

//Adds an item into the heap ph, percolating it up to the correct level, based on the provided comparison function.
//Returns 0 if v was successfully added to the heap.
//Returns -1 if the heap was full and could not be enlarged. (v was not added in this case)
int GENERIC(heap_add)(HEAP *ph, GENERIC_TYPE v, int (*compare)(GENERIC_TYPE, GENERIC_TYPE));

//Removes an item from the heap ph, maintaining heapiness.
//Asserts if there are no more items in the heap, because laziness.
GENERIC_TYPE GENERIC(heap_rem)(HEAP *ph, int (*compare)(GENERIC_TYPE, GENERIC_TYPE));