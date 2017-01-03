#include <stdio.h>
#include "heap.h"

enum {
	HEAPSIZE = 10
};

int compare_float_records(float_record r1, float_record r2)
{
	if(r1.data > r2.data)
		return -1;
	else if (r1.data < r2.data)
		return 1;
	else
		return 0;
}

int compare_int_records(int_record r1, int_record r2)
{
	if(r1.data > r2.data)
		return -1;
	else if (r1.data < r2.data)
		return 1;
	else
		return 0;
}

int main()
{
	//Backing arrays for the heaps
	int_record     int_record_store[HEAPSIZE];
	float_record float_record_store[HEAPSIZE];

	//Two different kinds of heaps created from the same function call.
	//Heap was only implemented once!
	int_record_heap     int_records = new_heap(int_record_store, HEAPSIZE);
	float_record_heap float_records = new_heap(float_record_store, HEAPSIZE);

	//Heap functions such as add and remove work correctly on both types of heap.
	for (int i = 0; i < HEAPSIZE; i++) {
		heap_add(&int_records, (int_record){.data = i}, compare_int_records);
		heap_add(&float_records, (float_record){.data = i}, compare_float_records);
	}

	for (int i = 0; i < HEAPSIZE; i++) {
		printf("int record: %2i|", heap_rem(&int_records, compare_int_records).data);
		printf("float record: %f\n", heap_rem(&float_records, compare_float_records).data);
	}

	return 0;
}