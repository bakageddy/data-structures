#include <stdio.h>
#include <stdlib.h>

#define MAX 20

static int *stack;
static int last;

void stackInit() {
    stack = (int *) malloc(sizeof(int) * MAX);
    last = 0;
}

int stackIsFull() {
    return last + 1 == MAX;
}

int stackIsEmpty() {
    return last == 0;
}

int stackPop() {
    if (!stackIsEmpty()) {
        int elem = stack[last - 1];
        last--;
        return elem;
    } else {
        puts("Stack Underflow!\n");
        exit(1);
    }
}

void stackPush(int elem) {
    if (!stackIsFull()) {
        stack[last++] = elem;
    } else {
        puts("Stack Overflow\n");
        exit(1);
    }
}

void stackPrint() {
    for (int i = 0; i < last; i++) {
        printf("%d ", stack[i]);
    }
    puts("\n");
}

void freeStack() {
    if (stack == NULL) {
        puts("Don't do this bish\n");
        exit(1);
    }
    free(stack);
    stack = NULL;
}

int getInput() {
    int option;
    puts("1. Push");
    puts("2. Pop");
    puts("3. Print");
    puts("4. Quit");
    printf("Enter your option: ");
    scanf("%d", &option);
    return option;
}

int main(void) {
    int elem, option;
    stackInit();
    option = getInput();
    do {
        if (option == 1) {
            printf("Enter a elem: ");
            scanf("%d", &elem);
            stackPush(elem);
        } else if (option == 2) {
            printf("Deleted: %d\n", stackPop());
        } else if (option == 3) {
            stackPrint();
        } else {
            puts("Wrong Option!\n");
        }
        option = getInput();
    } while (option != 4);
    freeStack();
    return 0;
}
