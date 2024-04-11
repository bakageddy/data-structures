#ifndef ARENA_H
#define ARENA_H

#include <stdlib.h>

typedef struct {
	void *arena;
	size_t cursor;
	size_t cap;
} arena_t;

int init_arena(arena_t *arena, size_t cap);
void *arena_alloc(arena_t *arena, size_t nbytes);
void destroy_arena(arena_t *arena);

#ifdef ARENA_IMPL
int init_arena(arena_t *arena, size_t cap) {
	if (arena == NULL) return -1;
	arena -> cap = cap;
	arena -> arena = malloc(sizeof(char) * cap);
	if (arena -> arena == NULL) {
		return -1;
	}
	arena -> cursor = 0;
	return 0;
}

void *arena_alloc(arena_t *arena, size_t nbytes) {
	if (arena == NULL || nbytes == 0) return NULL;
	if (arena -> cap < arena -> cursor + nbytes) return NULL;
	char *pool = (char *) arena -> arena;
	char *ptr = pool + arena -> cursor;
	arena -> cursor += nbytes;
	return (void *) ptr;
}


void destroy_arena(arena_t *arena) {
	if (arena == NULL || arena -> arena == NULL) return;
	free(arena -> arena);
	arena -> cap = 0;
	arena -> arena = NULL;
	arena -> cursor = 0;
}

#endif // !ARENA_IMPL

#endif // !ARENA_H
