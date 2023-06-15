/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// 선입선출

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	int front;
	int rear;
	int size;
	element *data;
}QueueType;

void error(const char* message) {
	fprintf(stdout, "%s\n", message);
	return;
}

void init_queue(QueueType* q) {
	int size;
	q->rear = -1;
	q->front = -1;
	printf("큐의 크기를 입력하시오: ");
	scanf("%d", &size);
	q->size = size;
	q->data = (element*)malloc(q->size * sizeof(element));
}

void queue_print(QueueType* q) {
	for (int i = 0; i < q->size; i++) {
		if (q->data[i] <= 0) printf("	|	");
		else printf("%d	|	", q->data[i]);
	}
	printf("\n");
}

int is_full(QueueType* q) {
	if (q->rear == -1 && q->front == -1) return 0;
	else if (q->rear == q->front) return 1;
	else return 0;
}

int is_empty(QueueType* q) {
	if (q->front == q->rear && q->data[q->front] == NULL) return 1;
	else return 0;
}

//push 함수
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("큐가 포화상태입니다.");
		return;
	}
	if (q->rear == q->size - 1) {
		if (q->front > 0) q->rear = - 1;
	}

	q->data[++(q->rear)] = item;
	queue_print(q);
}

//pop 함수
int dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백입니다.");
		return -1;
	}

	if (q->front == q->size - 1) {
		q->front = -1;
	}
	int item = q->data[++(q->front)];
	q->data[(q->front)] = NULL;
	queue_print(q);
	return item;
}

//peek 함수
int peek(QueueType* q) {
	if (is_empty(q)) {
		error("큐가 공백입니다.\n");
		return -1;
	}
	int item = q->data[(q->front)];
	return item;
}

int main(void) {
	int item = 0;
	QueueType q;

	init_queue(&q);

	printf("enqueue실행\n");
	for (int i = 1; i <= 5; i++) enqueue(&q, i * 10);

	printf("\ndequeue실행\n");
	for (int i = 1; i <= 3; i++) printf("dequeue: %d\n", dequeue(&q));

	printf("\nenqueue실행\n");
	for (int i = 6; i <= 10; i++) enqueue(&q, i * 10);

	printf("\ndequeue실행\n");
	for (int i = 1; i <= 3; i++) printf("dequeue: %d\n", dequeue(&q));

	return 0;
}*/