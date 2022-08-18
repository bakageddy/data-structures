#include "./link.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void traverse(linked_list* list) {
    for (node_t* head = list -> head; head != NULL; head = head -> next) {
        printf("%d ", head -> data);
    }
    printf("\n");
}


size_t search(linked_list *list, node_t *elem) {
    size_t index = 0;
    for (node_t *head = list -> head; head != NULL; head = head -> next) {
        if (head -> data == elem -> data)
            return index;
        else index += 1;
    }
    return -1;
}


void insert(linked_list *list, size_t index, node_t *elem) {
    node_t *head = list -> head;
    size_t count = 0;
    if (index == 0)
        insertAtStart(list, elem);
    else if (index == list -> length + 1)
        insertAtEnd(list, elem);
    else {
        while (count < index - 1) {
            head = head -> next;
            count += 1;
        }
        elem -> next = head -> next;
        head -> next = elem;
        list -> length += 1;
    }
    return;
}

void insertAfter(linked_list *list, node_t *after, node_t *elem) {
    size_t index = search(list, after);
    if (index == -1)
        printf("Element not found!\n");
    else
        insert(list, index + 1, elem);
}

void insertBefore(linked_list *list, node_t* before, node_t* elem) {
    size_t index = search(list, before);
    if (index == -1)
        printf("Element not found!\n");
    else
        insert(list, index - 1, elem);
}

void insertAtEnd(linked_list *list, node_t *elem) {
    node_t *head = list -> head;
    while (head != NULL)
        head = head -> next;
    head -> next = elem;
    elem -> next = NULL;
    list -> length += 1;
}

void insertAtStart(linked_list *list, node_t *elem) {
    elem -> next = list -> head;
    list -> head = elem;
    list -> length += 1;
}

void deleteElem(linked_list *list, size_t index) {
    node_t *head = list -> head, *temp;
    size_t count = 0;
    while (count < index - 1) {
        head = head -> next;
        count += 1;
    }

    temp = head -> next;
    head -> next = head -> next -> next;
    free(temp);
    list -> length -= 1;
}

void freeList(linked_list *list) {
    node_t *head = list -> head, *temp;
    while (list -> head != NULL) {
        temp = head;
        head = head -> next;
        free(temp);
    }

    list -> length = 0;
}
