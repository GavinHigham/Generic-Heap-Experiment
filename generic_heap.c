#ifndef GENERIC_HEAP_C
#define GENERIC_HEAP_C

//Non-generic helper functions and includes are include-guarded to prevent duplication.
#include <assert.h>

static int parent_index(int i)
{
	return (i - 1) / 2;
}

//Left Child Index
static int lci(int i)
{
	return i*2 + 1;
}

//Right Child Index
static int rci(int i)
{
	return i*2 + 2;
}

#endif

HEAP GENERIC(new_heap)(GENERIC_TYPE arr[], int len)
{
	return (HEAP) {
		._arr = arr,
		.max = len,
		.len = 0
	};
}

GENERIC_TYPE GENERIC(peek)(HEAP *ph)
{
	if (ph->len < 1)
		assert(0);
	return ph->_arr[0];
}

static void GENERIC(swap)(GENERIC_TYPE *p1, GENERIC_TYPE *p2) {
	GENERIC_TYPE tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

static void GENERIC(sift)(HEAP *ph, int i, int (*compare)(GENERIC_TYPE, GENERIC_TYPE))
{
	int pi = parent_index(i);
	if (compare(ph->_arr[i], ph->_arr[pi]) > 0) {
		GENERIC(swap)(&ph->_arr[i], &ph->_arr[pi]);
		GENERIC(sift)(ph, pi, compare);
	}
}

static void GENERIC(sift_down)(HEAP *ph, int i, int (*compare)(GENERIC_TYPE, GENERIC_TYPE))
{
	int l = lci(i);
	int r = rci(i);
	int mi = i;
	
	if (l <= ph->len && compare(ph->_arr[l], ph->_arr[mi]) > 0)
		mi = l;
	if (r <= ph->len && compare(ph->_arr[r], ph->_arr[mi]) > 0)
		mi = r;
	
	if (mi != i) {
		GENERIC(swap)(&ph->_arr[i], &ph->_arr[mi]);
		GENERIC(sift_down)(ph, mi, compare);
	}
}

int GENERIC(heap_add)(HEAP *ph, GENERIC_TYPE v, int (*compare)(GENERIC_TYPE, GENERIC_TYPE))
{
	if (ph->len >= ph->max)
		return -1;
	ph->_arr[(ph->len)++] = v;
	GENERIC(sift)(ph, (ph->len - 1), compare);
	return 0;
}

GENERIC_TYPE GENERIC(heap_rem)(HEAP *ph, int (*compare)(GENERIC_TYPE, GENERIC_TYPE))
{
	if (ph->len < 1)
		assert(0); //Great error handling
	GENERIC_TYPE root = GENERIC(peek)(ph);
	ph->_arr[0] = ph->_arr[--(ph->len)];
	GENERIC(sift_down)(ph, 0, compare);
	return root;
}
