#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "link.h"

static linked_list* list;
int main(void) {
    node_t* head = (node_t*) malloc(sizeof(node_t));
    head -> data = 1;
    head -> next = NULL;
    initList(list, head);
    traverse(list);
    freeList(list);
    return 0;
}
