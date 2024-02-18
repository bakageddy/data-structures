#ifndef __LINKED_H
#define __LINKED_H

#include <stddef.h>
struct node {
    int data;
    struct node *next, *prev;
};

typedef struct node node_t;

typedef struct {
    node_t *head;
    size_t len;
} d_list;

void initList(d_list **list);
node_t* create_node(int data);
void printList(d_list *list);

void insertAtStart(d_list *list, int data);
void deleteAtStart(d_list *list);

void insertAtEnd(d_list *list, int data);
void deleteAtEnd(d_list *list);

void deleteAt(d_list *list, size_t index);
void insertAt(d_list *list, size_t index, int data);

void get(d_list *list, size_t index);

void freeList(d_list **list);

#endif
