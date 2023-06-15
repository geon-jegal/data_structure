#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}DequeType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//init함수
void init_queue(DequeType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

//포화상태 검출
int is_full(DequeType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//원형큐 출력 함수
void deque_print(DequeType* q) {
	printf("DEQUE(front = %d rear = %d) =	", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d	|	", q->data[i]);
			if (i == q->rear) break;
		} while (i != q->front);
	}
	printf("\n");
}

// 삽입 함수
void add_front(DequeType* q, element val) {
	if (is_full(q)) error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

// 삭제 함수
element delete_front(DequeType* q) {
	if (is_empty(q)) error("큐가 공백상태입니다");
	q->rear = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

//peek 함수
element get_front(DequeType* q) {
	if (is_empty(q)) error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

//삽입 함수
void add_rear(DequeType* q, element item) {
	if (is_full(q)) error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

//삭제 함수
element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q)) error("큐가 공백상태입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

//peek 함수
element get_rear(DequeType* q) {
	if (is_empty(q)) error("큐가 공백입니다.");
	return q->data[q->rear];
}

int main(void) {
	DequeType queue;

	init_queue(&queue);
	for (int i = 0; i < 3; i++) {
		add_front(&queue, i);
		deque_print(&queue);
	}

	for (int i = 0; i < 3; i++) {
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}