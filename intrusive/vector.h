#ifndef INTRUSIVE_VECTOR_H
#define INTRUSIVE_VECTOR_H

#ifndef INTRUSIVE_VECTOR_INIT_CAPACITY
#define INTRUSIVE_VECTOR_INIT_CAPACITY 16
#endif // !INTRUSIVE_VECTOR_INIT_CAPACITY

#include <stddef.h>
#include <assert.h>

#define ivec_cont(ptr, type) (type *) ((char *) ((ivec_t*) ptr) - offsetof(type, vector))

typedef struct {
	size_t size;
	size_t len;
	size_t cap;
} ivec_t;

// Maybe have a callback?
// TODO: Implement callbacks on errors

#define grow_vector(ptr, type) do {					\
	type *cont = ivec_cont(ptr, type);				\
	void *res = _grow_vector(ptr, cont -> data);	\
	assert(res != NULL);							\
} while (0)											\

#define shrink_vector(ptr, type) do {				\
	type *cont = ivec_cont(ptr, type);				\
    void *res = _shrink_vector(ptr, cont -> data);	\
	assert(res != NULL);							\
} while (0)											\

#define append_vector(ptr, type, elem) do {			\
	type *cont = ivec_t(ptr, type);					\
	int res = _append_vector(ptr, cont -> data, elem);\
	assert(res == 0);								\
} while (0)											\

ivec_t new_ivec(size_t size);
void *init_vector(ivec_t *vec);
void *_grow_vector(ivec_t *vec, void *data);
void *_shrink_vector(ivec_t *vec, void *data);
int _append_vector(ivec_t *ptr, void *data, void *elem);

#ifdef INTRUSIVE_VECTOR_IMPL
#include <stdlib.h>

ivec_t new_ivec(size_t size) {
	return (ivec_t) {
		.size = size,
		.len = 0,
		.cap = 0,
	};
}

void *init_vector(ivec_t *vec) {
	vec -> cap = INTRUSIVE_VECTOR_INIT_CAPACITY;
	void *data = malloc(vec -> cap * vec -> size);
	return data;
}

void *_grow_vector(ivec_t *vec, void *data) {
	void *res = realloc(data, vec -> cap * 2 * vec -> size);
	if (res != NULL) {
		data = res;
		vec -> cap *= 2;
		return data;
	}
	return NULL;
}

void *_shrink_vector(ivec_t *vec, void *data) {
	void *res = realloc(data, (size_t) vec -> cap * 0.5 * vec -> size);
	if (res != NULL) {
		data = res;
		vec -> cap = (size_t) (vec -> cap / 0.5);
		return data;
	}
}

int _append_vector(ivec_t *ptr, void *data, void *elem) {
	// TODO: make this work, make this twerk
	return 0;
}

#endif // INTRUSIVE_VECTOR_IMPL

#endif // INTRUSIVE_VECTOR_H
