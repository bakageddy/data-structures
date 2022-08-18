#ifndef __LINK_H
#define __LINK_H
#define NODE_CREATE (node_t*) malloc(sizeof(node_t))

#include <stddef.h>
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node_t;

typedef struct {
    node_t* head;
    size_t length;
} linked_list;

void traverse(linked_list *list);
size_t search(linked_list *list, node_t* elem);
void insert(linked_list *list, size_t index, node_t *elem);
void insertAfter(linked_list *list, node_t* after, node_t* elem);
void insertBefore(linked_list *list, node_t* before, node_t* elem);
void insertAtStart(linked_list *list, node_t *elem);
void insertAtEnd(linked_list *list, node_t *elem);
void deleteElem(linked_list *list, size_t index);
void freeList(linked_list *list);

#endif
