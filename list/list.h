#ifndef __LIST_H
#define __LIST_H

#ifndef LIST_TYPE
#define LIST_TYPE int
#endif // !__LIST_TYPE

#include <stddef.h>
	   
typedef struct node_t {
	LIST_TYPE data;
	struct node_t* next;
} node_t;

typedef struct {
	node_t *head;
	size_t len;
} list_t;

list_t *create(LIST_TYPE initial);
list_t *create_default(void);

node_t *create_node(LIST_TYPE val);

int list_append(list_t *list, LIST_TYPE elem);
int list_delete(list_t *list, size_t idx);

void delete_list(list_t *list);

#endif // !__LIST_H
