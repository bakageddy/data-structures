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

int list_extend(list_t *list, list_t *other) {
	if (!list || !other) return 1;
	node_t *head = list -> head;
	while (!head) head = head -> next; 

	head -> next = other -> head;
	list -> len += other -> len;
	return 0;
}

int list_insert(list_t *list, LIST_TYPE elem, size_t idx) {
	if (list == NULL) return -1;
	if (idx > list -> len) return -1;

	if (idx == 0) {
		node_t *node = create_node(elem);
		if (!node) return -1;
		node -> next = list -> head;
		list -> head = node;
		list -> len += 1;
		return 0;
	}

	node_t *ptr = list -> head;
	size_t ctr = 0;
	while (ctr + 1 != idx) {
		ptr = ptr -> next;
		ctr += 1;
	}
	node_t *to_insert = create_node(elem);
	if (!to_insert) return -1;
	to_insert -> next = ptr -> next;
	ptr -> next = to_insert;
	list -> len += 1;
	return 0;
}

int list_delete(list_t *list, const size_t idx) {
	if (list == NULL || list -> head == NULL) return -1;
	if (idx >= list -> len) return -1;

	if (idx == 0) {
		node_t *head = list -> head;
		list -> head = head -> next;
		free(head);
		list -> len -= 1;
		return 0;
	}

	node_t *ptr = list -> head;
	size_t ctr = 0;
	while (ctr + 1 != idx) {
		ptr = ptr -> next;
		ctr += 1;
	}

	node_t *to_delete = ptr -> next;
	ptr -> next = ptr -> next -> next;
	list -> len -= 1;
	free(to_delete);

	return 0;
}

int list_remove(list_t *list, LIST_TYPE elem) {
	if (!list) return 1;
	node_t *head = list -> head;
	if (head -> data == elem) {
		list -> head = head -> next;
		free(head);
		return 0;
	}

	while (head -> next != NULL) {
		if (head -> next -> data == elem) {
			node_t *temp = head -> next;
			head -> next = head -> next -> next;
			free(temp);
			return 0;
		}
		head = head -> next;
	}
	return 1;
}

size_t list_find(list_t *list, LIST_TYPE elem) {
	if (!list) return -1;
	size_t idx = 0;
	node_t *head = list -> head;
	while (!head) {
		if (head -> data == elem) {
			return idx;
		}
		idx += 1;
		head = head -> next;
	}
	return -1;
}

void __delete_nodes(node_t *head) {
	if (head == NULL) return;
	__delete_nodes(head -> next);
	free(head);
}

void delete_list(list_t *list) {
	if (!list) return;
	__delete_nodes(list -> head);
}

