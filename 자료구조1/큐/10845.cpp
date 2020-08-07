#define _CRT_SECURE_NO_WARNINGS
#define MAX_QUEUE_SIZE 10000
#define Success 1
#define Error -1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int head;
	int tail;
}QueueType;

QueueType* created() {
	QueueType* q;

	q = (QueueType*)malloc(sizeof(QueueType));
	q->head = 0;
	q->tail = 0;

	return q;
}

int is_empty(QueueType* q) {
	return (q->head == q->tail);
}

int is_full(QueueType* q) {
	return ((q->tail + 1) % MAX_QUEUE_SIZE == q->head);
}

int enqueue(QueueType* q, int item) {
	if (is_full(q))
		return Error;

	q->tail = (q->tail + 1) % MAX_QUEUE_SIZE;
	q->queue[q->tail] = item;
	return Success;
}

int dequeue(QueueType* q) {
	if (is_empty(q))
		return Error;

	q->head = (q->head + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->head];
}

int main() {
	char com[10];
	int num, item;
	QueueType* q = created();

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf("%s", com);
		fgetc(stdin);

		if (!strcmp(com, "push")) {
			scanf("%d", &item);
			fgetc(stdin);

			enqueue(q, item);
		}
		else if (!strcmp(com, "pop")) {
			printf("%d\n", dequeue(q));
		}
		else if (!strcmp(com, "size")) {
			printf("%d\n", q->tail - q->head);
		}
		else if (!strcmp(com, "empty")) {
			printf("%d\n", is_empty(q));
		}
		else if (!strcmp(com, "front")) {
			if (is_empty(q))
				printf("%d\n", -1);
			else
				printf("%d\n", q->queue[q->head + 1]);
		}
		else if (!strcmp(com, "back")) {
			if (is_empty(q))
				printf("%d\n", -1);
			else
				printf("%d\n", q->queue[q->tail]);
		}
	}

	return 0;
}