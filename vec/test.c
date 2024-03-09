#include "vec.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int test_vec_create(void) {
	vec *vec = vec_create();
	if (!vec) return EXIT_FAILURE;
	assert(vec -> cap == 10);
	assert(vec -> len == 0);
	return EXIT_SUCCESS;
}

int test_vec_grow(void) {
	vec *vec = vec_create();
	if (!vec) return EXIT_FAILURE;
	int res = vec_grow(vec);
	assert(res == 0);
	assert(vec -> len == 0);
	assert(vec -> cap == 20);
	vec_free(vec);
	return 0;
}

int test_vec_free(void) {
	vec *vec = vec_create();
	if (!vec) return EXIT_FAILURE;
	vec_free(vec);
	return EXIT_SUCCESS;
}

int test_vec_append(void) {
	vec *vector = vec_create();
	if (!vector) return EXIT_FAILURE;
	vec_append(vector, 10);
	assert(vector -> elems[vector -> len - 1] == 10);
	assert(vector -> len == 1);
	vec_free(vector);

	vec *another_vec = vec_create();
	for (int i = 0; i < 10; i++) {
		vec_append(another_vec, i);
		vec_debug_print(another_vec);
		assert(another_vec -> elems[vector -> len - 1] == i);
	}
	vec_append(another_vec, 10);
	assert(another_vec -> elems[vector -> len - 1] == 10);
	assert(another_vec -> len == 11);
	assert(another_vec -> cap == 20);


	vec_free(another_vec);

	return EXIT_SUCCESS;
}

int main(void) {
	assert(test_vec_create() == EXIT_SUCCESS);
	assert(test_vec_free() == EXIT_SUCCESS);
	assert(test_vec_grow() == EXIT_SUCCESS);
	assert(test_vec_append() == EXIT_SUCCESS);
	return 0;
}
