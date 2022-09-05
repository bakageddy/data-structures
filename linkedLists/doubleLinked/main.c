#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

int main(void) {
    d_list *list = NULL;
    initList(&list);
    for (int i = 0; i < 10; i++)
        insertAt(list, i, i);
    insertAt(list, 10, 10);
    insertAt(list, 0, -1);
    printList(list);
    freeList(&list);
    return 0;
}
