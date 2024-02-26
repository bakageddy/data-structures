#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include "./list.h"


void print_list(list_t *list) {
	assert(list != NULL);
	assert(list -> len != 0);
	assert(list -> head != NULL);

	node_t *head = list -> head;
	while (head != NULL) {
		printf("%d ", head -> data);
		head = head -> next;
	}
	printf("\n");
}

// int test_create(void) {
// 	list_t* list = create(10);
// 	assert(list != NULL);
// 	assert(list -> data == 10);
//
// 	list_t* another = create_default();
// 	assert(another != NULL);
// 	assert(another -> data == 0);
//
// 	delete_list(list);
// 	delete_list(another);
// 	return 1;
// }

// int test_append(void) {
// 	list_t* list = NULL;
// 	int result = list_append(list, 10);
// 	assert(result == -1);
//
// 	list = create_default();
// 	result = list_append(list, 10);
//
// 	assert(result != -1);
// 	assert(list -> next -> data == 10);
//
// 	delete_list(list);
// 	return 1;
// }

int test_delete(void) {
	list_t *list = NULL;
	list = create(1);
	list_append(list, 2);
	list_append(list, 3);
	print_list(list);

	int result = list_delete(list, 0);
	assert(result != -1);
	print_list(list);

	result = list_delete(list, 3);
	assert(result == -1);
	print_list(list);

	list_append(list, 4);
	list_append(list, 5);
	print_list(list);

	result = list_delete(list, 3);
	assert(result != -1);
	print_list(list);

	delete_list(list);
	return 1;
}

int test_insert(void) {
	list_t *list = NULL;
	list = create(1);
	assert(list != NULL);

	int result = list_insert(list, 2, list -> len);
	assert(result != -1);
	print_list(list);

	result = list_insert(list, 3, list -> len);
	assert(result != -1);
	print_list(list);

	result = list_insert(list, 0, 0);
	assert(result != -1);
	print_list(list);

	result = list_insert(list, 69, 2);
	assert(result != -1);
	print_list(list);

	print_list(list);
	delete_list(list);
	return 1;

}

int main(void) {
	// int cases;
	// cases += test_create();
	// cases += test_append();
	// printf("TEST CASES: PASSED %d\n", cases);
	test_insert();
	return 0;
}
