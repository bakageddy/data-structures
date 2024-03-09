#include <stdio.h>
#include <stdlib.h>
#define OPTION_IMPL
#include "option.h"
#include "../vec/vec.h"

option safe_malloc(unsigned int bytes) {
	void* t = malloc(bytes);
	if (t == NULL) return none();
	return some(t);
}

int main(void) {
	option o = safe_malloc(sizeof(int) * 100);
	if (is_none(o)) return EXIT_FAILURE;
	int *xs = (int *) o.data;
	vec vector = (vec) {
		.cap = 100,
		.len = 0,
		.elems = xs,
	};
	return 0;
}
