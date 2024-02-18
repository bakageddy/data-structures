#ifndef __LIST_H
#define __LIST_H

#ifndef LIST_TYPE
#define LIST_TYPE int
#endif // !__LIST_TYPE
	   
typedef struct node_t {
	LIST_TYPE data;
	struct node_t* next;
} node_t;

typedef node_t list_t;

list_t *create(LIST_TYPE initial);
list_t *create_default(void);

int list_append(list_t *head, LIST_TYPE elem);

void delete_list(list_t *head);

#endif // !__LIST_H
