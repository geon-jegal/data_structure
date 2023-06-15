#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element; // 큐 원소(element)의 자료형 정의
typedef struct {
	int front, rear;
	int capacity;
	int* array;
} QueueType;

QueueType* Queue(int size) {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	if (!Q) return NULL;
	Q->capacity = size; // Queue 크기
	Q->front = Q->rear = -1; //front, rear 초깃값 설정
	Q->array = (int*)malloc(Q->capacity * sizeof(int));
	if (!Q->array) return NULL;
	return Q;
}

// 원형 큐가 공백 상태인지 검사하는 연산
int isEmpty(QueueType* Q) {
	return((Q->front) == -1);
}

// 원형 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType* Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

//출력함수
void print_Queue(QueueType* Q) {
	for (int i = Q->front; i == Q->rear; (i + 1) % Q->capacity) printf("%d	|	", Q->array[i]);
}

// 원형 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) printf(" Queue Overflow\n");
	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;
		if (Q->front == -1)	Q->front = Q->rear; // 첫 데이터의 경우 f=r=0 이되어야 함
	}
	print_Queue(Q);
}

//원형 큐의 front에서 원소를 삭제하고 반환하는 연산
element deQueue(QueueType* Q) {
	int data = 0;
	if (isEmpty(Q)) {
		printf(" Queue is empty");
		exit(1);
	}
	else {
		data = Q->array[Q->front];
		//공백상태가 되었음을 의미한다
		if (Q->front == Q->rear) Q->front = Q->rear = -1;
		else Q->front = (Q->front + 1) % Q->capacity;
	}
	print_Queue(Q);
	return data;
}

//큐 삭제 연산
void deleteQueue(QueueType* Q) {
	if (Q) {
		if (Q->array) free(Q->array);
	}
	free(Q);
}

int main(void) {
	int i = 0;
	printf("원형 큐의 크기를 입력하시오: ");
	scanf("%d", &i);

	QueueType* q = Queue(i);

	printf("enqueue실행\n");
	for (int i = 1; i <= 5; i++) enQueue(q, i * 10);

	printf("\ndequeue실행\n");
	for (int i = 1; i <= 3; i++) printf("dequeue: %d\n", deQueue(q));

	printf("\nenqueue실행\n");
	for (int i = 6; i <= 10; i++) enQueue(q, i * 10);

	printf("\ndequeue실행\n");
	for (int i = 1; i <= 3; i++) printf("dequeue: %d\n", deQueue(q));
	return 0;
}