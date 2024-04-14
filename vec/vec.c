#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vec.h"

vec *vec_create(void) {
	vec *tmp = malloc(sizeof(vec));
	if (!tmp) return NULL;
	tmp -> elems = malloc(sizeof(VEC_TYPE) * VEC_DEFAULT_SIZE);
	if (!tmp -> elems) return NULL;
	tmp -> len = 0;
	tmp -> cap = 10;

	memset(tmp -> elems, 0, tmp -> cap);

	return tmp;
}

int vec_grow(vec *vector) {
	VEC_TYPE *tmp = malloc(sizeof(VEC_TYPE) * (2 * vector -> cap));
	if (!tmp) return 1;
	// What the fuck did you do dinesh?
	// NOTE: memcpy takes in Bytes, not no of elems
	memcpy(tmp, vector -> elems, (sizeof(VEC_TYPE)) * vector -> cap);
	free(vector -> elems);
	vector -> elems = tmp;
	vector -> cap *= 2;
	return 0;
}

int vec_append(vec *vector, const VEC_TYPE elem) {
	if (vector -> len == vector -> cap) {
		int res = vec_grow(vector);
		if (res == 1) return 1;
	}
	vector -> elems[vector -> len] = elem;
	vector -> len += 1;
	return 0;
}

option vec_pop(vec *vector) {
	if (!vector) return none();
	vector -> len -= 1;
	return some(&vector -> elems[vector -> len]);
}

int vec_shrink(vec *vector) {
	VEC_TYPE *tmp = malloc(sizeof(VEC_TYPE) * (vector -> cap / 2));
	if (!tmp) return 1;
	memcpy(tmp, vector -> elems, vector -> cap);
	free(vector -> elems);
	vector -> elems = tmp;
	vector -> cap /= 2;
	return 0;
}

void vec_debug_print(vec *vector) {
	if (!vector) {
		printf("Uninitialized Vector\n");
		return;
	}
	for (size_t i = 0; i < vector -> len; i++) {
		printf("Index: %zu -> Elem: %d\n", i, vector -> elems[i]);
	}
}

void vec_free(vec *vector) {
	free(vector -> elems);
	vector -> len = 0;
	vector -> cap = 0;
	free(vector);
}
