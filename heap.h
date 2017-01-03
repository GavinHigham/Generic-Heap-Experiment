#ifndef HEAP_H
#define HEAP_H

//Macro expansion does not happen if you concatenate, so delegate concatenation to a second macro.
#define GENERIC_NAME(generic_type, function_suffix) generic_type ## _ ## function_suffix
#define GENERIC_FUNC(generic_type, function_suffix) GENERIC_NAME(generic_type, function_suffix)
#define GENERIC(function_suffix) GENERIC_FUNC(GENERIC_TYPE, function_suffix)

//Define data types if you want to create your own:
typedef struct {
	float data;
} float_record;

typedef struct {
	int data;
} int_record;

//For each desired type implementation of the data structure:
#define GENERIC_TYPE int_record
#include "generic_heap.h"
#undef GENERIC_TYPE

#define GENERIC_TYPE float_record
#include "generic_heap.h"
#undef GENERIC_TYPE

//If you want type-generic invocation, you have to do this for each exposed function:
#define new_heap(type, len) _Generic((type),\
	int_record *: int_record_new_heap, \
	float_record *: float_record_new_heap)(type, len)

#define heap_add(type, obj, comp) _Generic((type),\
	int_record_heap *: int_record_heap_add, \
	float_record_heap *: float_record_heap_add)(type, obj, comp)

#define heap_rem(type, comp) _Generic((type),\
	int_record_heap *: int_record_heap_rem, \
	float_record_heap *: float_record_heap_rem)(type, comp)

#endif