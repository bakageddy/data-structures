#ifndef CUB_LL_H
#define CUB_LL_H

#include <stddef.h>
#include <stdbool.h>

#define container_of(ptr, type, member) ({					\
		const typeof(((type *) 0) -> member) *mptr = ptr;	\
		(type *)((char *) mptr - offsetof(type, member));}) \

typedef struct node {
	struct node *next;
} node;

node *new_node(void);
bool add_node(node *ref, node *n);
bool delete_node(node *ref);

// #define CUB_LL_IMPL
#ifdef CUB_LL_IMPL

#include <stdlib.h>

node *new_node(void) {
	return (node *) calloc(1, sizeof(node));
}

bool add_node(node *ref, node *n) {
	if (!ref && !n) return false;
	ref -> next = n;
	return true;
}

bool delete_node(node *ref) {
	free(ref);
}

#endif // CUB_LL_IMPL

#endif // CUB_LL_H
