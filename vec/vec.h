#ifndef __VEC_H
#define __VEC_H

#ifndef VEC_TYPE
#define VEC_TYPE int
#endif // !VEC_TYPE

#ifndef VEC_DEFAULT_SIZE
#define VEC_DEFAULT_SIZE 16
#endif

#include <stddef.h>
#define OPTION_IMPL
#include "option.h"

typedef struct {
	VEC_TYPE* elems;
	size_t len;
	size_t cap;
} vec;

vec *vec_create(void);
int vec_grow(vec *vector);
int vec_append(vec *vector, const VEC_TYPE elem);
option vec_pop(vec *vector);
int vec_shrink(vec *vector);

void vec_debug_print(vec *vector);

void vec_free(vec *vector);

#endif // !__VEC_H
