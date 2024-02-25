#include "list.h"
#include <stdlib.h>

list_t *create(LIST_TYPE initial) {
	list_t *list = (list_t *) malloc(sizeof(list_t));
	if (!list) return NULL;

	node_t* node = create_node(initial);
	if (!node) return NULL;

	list -> head = node;
	list -> len = 1;
	return list;
}

list_t *create_default(void) {
	return create(0);
}

node_t *create_node(LIST_TYPE val) {
	node_t *node = (node_t *) malloc(sizeof(node_t));
	if (!node) return NULL;
	node -> data = (LIST_TYPE) val;
	node -> next = NULL;
	return node;
}

int list_append(list_t *list, LIST_TYPE elem) {
	// Can't make append on a empty list
	if (!list) return -1;

	node_t *head = list -> head;
	while (head -> next != NULL) {
		head = head -> next;
	}

	head -> next = create_node(elem);

	if (!head -> next) return -1;

	list -> len += 1;
	return 0;
}

int list_delete(list_t *list, const size_t idx) {
	if (list -> len <= idx) return -1;

	if (idx == 0 && list -> len == 1) {
		free(list -> head);
		list -> len -= 1;
		return 0;
	}

	// TODO: fix this bug
	node_t *head = list -> head;
	size_t counter = idx;
	while (counter >= 1) {
		head = head -> next;
		counter -= 1;
	}

	node_t *to_delete = head -> next;
	head -> next = head -> next -> next;
	list -> len -= 1;
	free(to_delete);

	return 0;
}

void __delete_nodes(node_t *head) {
	if (head == NULL) return;
	__delete_nodes(head -> next);
	free(head);
}

void delete_list(list_t *list) {
	__delete_nodes(list -> head);
}

