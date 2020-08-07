#define _CRT_SECURE_NO_WARNINGS
#define MAX_STACK_SIZE 10000
#define True 1
#define False 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int stackArr[MAX_STACK_SIZE];
	int top;
} Stack;

int empty(Stack* pstack) {
	if (pstack->top == -1)
		return True;
	else return False;
}

int full(Stack* pstack) {
	if (pstack->top == MAX_STACK_SIZE - 1)
		return True;
	else return False;
}

void push(Stack* pstack, int data) {
	if (!full(pstack))
		pstack->stackArr[++pstack->top] = data;
	else return;
}

int pop(Stack* pstack) {
	if(!empty(pstack))
		return pstack->stackArr[pstack->top--];
	return -1;
}

int size(Stack* pstack) {
	return (pstack->top) + 1;
}

int top(Stack* pstack) {
	if (!empty(pstack))
		return pstack->stackArr[pstack->top];
	else return - 1;
}

int main(void) {
	int n, add;
	char com[10];
	Stack* pstack = (Stack*)malloc(sizeof(Stack));
	pstack->top = -1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", com);
		fgetc(stdin);  //버퍼 지우기!!
	
		if (!strcmp(com,"push")) {
			scanf("%d", &add);
			fgetc(stdin);
			push(pstack, add);
		}
		else if (!strcmp(com, "pop")) {
			printf("%d\n", pop(pstack));
		}
		else if (!strcmp(com, "size")) {
			printf("%d\n", size(pstack));
		}
		else if (!strcmp(com, "empty")) {
			printf("%d\n", empty(pstack));
		}
		else if (!strcmp(com,"top")) {
			printf("%d\n", top(pstack));
		}
	}
}