#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "link.h"

void getPoly(linked_list *list, int terms);
int main(void) {
    linked_list *p = NULL;
    insertAtEnd(p, 10);
    // getPoly(p, 4);
    traverse(p);
    freeList(p);
    return 0;
}

void getPoly(linked_list *list, int terms) {
    int temp = 0;
    for (int i = 0; i < terms; i++) {
        printf("Enter the coefficient of ith term: ");
        scanf("%d", &temp);
        insertAtEnd(list, temp);
    }
}
