#define CUB_LL_IMPL
#include "ll.h"
#include <assert.h>

typedef struct {
	int data;
	node *node;
} List;

int main(void) {
	List x = {0};
	x.node = new_node();
	if (!x.node) return 0;
	List y = {1};
	y.node = new_node();
	if (!y.node) return 0;
	add_node(x.node, y.node);
	assert(x.node -> next == y.node);
	return 0;
}
