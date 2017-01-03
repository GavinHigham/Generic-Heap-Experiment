#include "heap.h"


#define GENERIC_TYPE int_record
#include "generic_heap.c"
#undef GENERIC_TYPE

#define GENERIC_TYPE float_record
#include "generic_heap.c"
#undef GENERIC_TYPE