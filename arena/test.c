#include <stdio.h>
#include <assert.h>

#define ARENA_IMPL
#include "./arena.h"

int main(void) {
	arena_t allocator = {0};
	if (init_arena(&allocator, sizeof(char) * 2048) < 0) {
		return 1;
	}
	assert(allocator.arena != NULL);
	assert(allocator.cap == 2048);
	assert(allocator.cursor == 0);

	int *array = arena_alloc(&allocator, sizeof(int) * 8);

	for (int i = 0; i < 8; i++) {
		array[i] = i + 1;
		printf("%d ", array[i]);
	}
	printf("\n");

	assert(allocator.cursor == sizeof(int) * 8);

	destroy_arena(&allocator);
	assert(allocator.cursor == 0);
	assert(allocator.cap == 0);
	assert(allocator.arena == NULL);
	return 0;
}
