#include "./link.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void checkList(linked_list *list) {
    if (list == NULL) {
        printf("INVALID LIST!\n");
        exit(1);
    }
}

void initList(linked_list *list, node_t *head) {
    list -> head = head;
    list -> length = 1;
}

void traverse(linked_list* list) {
    checkList(list);
    for (node_t* head = list -> head; head != NULL; head = head -> next) {
        printf("%d ", head -> data);
    }
    printf("\n");
}


size_t search(linked_list *list, int elem) {
    size_t index = 0;
    for (node_t *head = list -> head; head != NULL; head = head -> next) {
        if (head -> data == elem)
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
    size_t index = search(list, after -> data);
    if (index == -1)
        printf("Element not found!\n");
    else
        insert(list, index + 1, elem);
}

void insertBefore(linked_list *list, node_t* before, node_t* elem) {
    size_t index = search(list, before -> data);
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

void replace(linked_list *list, size_t index, int data) {
    node_t *head = list -> head;
    size_t count = 0;
    if ((index > list -> length) || (index < 0)) {
        printf("INVALID INDEX!\n");
        exit(1);
    }
    while (count < index - 1) {
        head = head -> next;
        count += 1;
    }
}

void deleteElem(linked_list *list, size_t index) {
    node_t *head = list -> head, *temp;
    size_t count = 0;
    if ((index > list -> length) || (index < 0)) {
        printf("INVALID INDEX!\n");
        exit(1);
    }
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
    checkList(list);
    node_t *head = list -> head, *temp;
    while (head != NULL) {
        temp = head;
        head = head -> next;
        free(temp);
        list -> length--;
    }
}
