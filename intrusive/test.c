#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#define INTRUSIVE_VECTOR_IMPL
#include "vector.h"

typedef struct {
	char *data;
	ivec_t vector;
} vector_t;

int main(void) {

	vector_t vec = {
		.data = NULL,
		.vector = new_ivec(sizeof(char)),
	};

	vec.data = init_vector(&vec.vector);
	grow_vector(&vec.vector, vector_t);
	free(vec.data);
	return 0;
}
