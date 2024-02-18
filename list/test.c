#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include "./list.h"


int test_create(void) {
	list_t* list = create(10);
	assert(list != NULL);
	assert(list -> data == 10);

	list_t* another = create_default();
	assert(another != NULL);
	assert(another -> data == 0);

	delete_list(list);
	delete_list(another);
	return 1;
}

int test_append(void) {
	list_t* list = NULL;
	int result = list_append(list, 10);
	assert(result == -1);

	list = create_default();
	result = list_append(list, 10);

	assert(result != -1);
	assert(list -> next -> data == 10);

	delete_list(list);
	return 1;
}

int main(void) {
	int cases;
	cases += test_create();
	cases += test_append();
	printf("TEST CASES: PASSED %d\n", cases);
	return 0;
}
