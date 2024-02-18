#include "list.h"
#include <stdlib.h>

list_t *create(LIST_TYPE initial) {
	list_t *temp = (list_t *) malloc(sizeof(list_t));
	if (!temp) return NULL;
	temp -> data = (LIST_TYPE) initial;
	temp -> next = NULL;
	return temp;
}

list_t *create_default(void) {
	return create(0);
}

int list_append(list_t *head, LIST_TYPE elem) {
	// Can't make append on a empty list
	if (!head) return -1;

	list_t *temp = head;
	while (temp -> next != NULL) temp = temp -> next;
	temp -> next = create(elem);
	if (!temp -> next) return -1;
	else return 0;
}

void delete_list(list_t *head) {
	if (head == NULL) return;
	delete_list(head -> next);
	free(head);
}
