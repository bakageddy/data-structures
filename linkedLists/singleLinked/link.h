#ifndef __LINK_H
#define __LINK_H

#include <stddef.h>
struct Node {
    int data;
    struct Node* next;
};

typedef struct Node node_t;

typedef struct {
    node_t* head;
    size_t length;
} LinkedList;

#endif
