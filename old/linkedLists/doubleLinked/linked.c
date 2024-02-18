#include <stdio.h>
#include <stdlib.h>

#include "linked.h"

node_t *create_node(int data) {
    node_t *nd = (node_t *) malloc(sizeof(node_t));
    nd -> next = NULL;
    nd -> prev = NULL;
    nd -> data = data;
    return nd;
}

void printList(d_list *list) {
    node_t *head = list -> head;
    if (head == NULL) {
        printf("Empty List\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

void insertAtStart(d_list *list, int data) {
    node_t *my_node = create_node(data);
    if (list == NULL) {
        initList(&list);
        list -> head = my_node;
        list -> len += 1;
        return;
    }
    if (list -> head == NULL) {
        list -> head = my_node;
        list -> len += 1;
        return;
    }
    my_node -> prev = NULL;
    my_node -> next = list -> head;
    list -> head -> prev = my_node;
    list -> head = my_node;
    list -> len += 1;
}

void freeList(d_list **list) {
    node_t *head = (*list) -> head, *temp = NULL;
    while (head != NULL) {
        temp = head;
        head = head -> next;
        free(temp);
    }
    free(*list);
}

void initList(d_list **list) {
    *list = malloc(sizeof(list));
    (*list) -> head = NULL;
    (*list) -> len = 0;
}

void deleteAtStart(d_list *list) {
    node_t* temp = list -> head;
    if (temp == NULL) {
        printf("Empty List\n");
        return;
    }
    if (temp -> next == NULL) {
        list -> head = NULL;
        free(temp);
        list -> len -= 1;
        return;
    }
    list -> head = list -> head -> next;
    list -> head -> prev = NULL;
    list -> len -= 1;
    free(temp);
}

void insertAtEnd(d_list *list, int data) {
    if (list == NULL) {
        initList(&list);
    }

    if (list -> head == NULL) {
        list -> head = create_node(data);
        list -> len += 1;
        return;
    }

    node_t *temp = list -> head, *toInsert = create_node(data);
    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    toInsert -> prev = temp;
    toInsert -> next = NULL;
    temp -> next = toInsert;
    list -> len += 1;
}

void deleteAtEnd(d_list *list) {
    node_t *temp = list -> head;
    if (list == NULL) {
        printf("Empty list");
        return;
    } else if (temp -> next == NULL) {
        list -> head = NULL;
        free(temp);
        list -> len -= 1;
        return;
    }

    while (temp -> next != NULL) {
        temp = temp -> next;
    }
    temp -> prev -> next = NULL;
    free(temp);
    list -> len -= 1;
}

void deleteAt(d_list *list, size_t index) {
    size_t count = index;
    node_t *temp = list -> head;
    if (list == NULL) {
        printf("Empty List\n");
        return;
    }
    if (index == 0) {
        deleteAtStart(list);
        return;
    }
    else if (index == list -> len - 1) {
        deleteAtEnd(list);
        return;
    }
    else if (index > list -> len - 1) {
        printf("Index out of bounds, cannot delete!\n");
        return;
    }
    while (temp != NULL && count != 0) {
        temp = temp -> next;
        count--;
    }
    temp -> next -> prev = temp -> prev;
    temp -> prev -> next = temp -> next;
    free(temp);
    list -> len -= 1;
}

void insertAt(d_list *list, size_t index, int data) {
    size_t count = index;
    node_t *temp = list -> head, *toInsert = NULL;
    if (index == list -> len) {
        insertAtEnd(list, data);
        return;
    } else if (index == 0) {
        insertAtStart(list, data);
        return;
    } else if (index > list -> len || index < 0) {
        printf("Invalid index!\n");
        return;
    }

    while (temp != NULL && count != 0) {
        temp = temp -> next;
        count--;
    }
    toInsert = create_node(data);
    toInsert -> next = temp -> next;
    toInsert -> prev = temp;
    temp -> next -> prev = toInsert;
    temp -> next = toInsert;

    list -> len += 1;
}

void get(d_list *list, size_t index) {
    node_t *temp = list -> head;
    if (index > list -> len || index < 0) {
        printf("Invalid index!");
        return;
    }
    while (index != 0) {
        temp = temp -> next;
        index--;
    }

    printf("Element Found: %d\n", temp -> data);
}
