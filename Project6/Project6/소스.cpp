#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element; // ť ����(element)�� �ڷ��� ����
typedef struct {
	int front, rear;
	int capacity;
	int* array;
} QueueType;

QueueType* Queue(int size) {
	QueueType* Q;
	Q = (QueueType*)malloc(sizeof(QueueType));
	if (!Q) return NULL;
	Q->capacity = size; // Queue ũ��
	Q->front = Q->rear = -1; //front, rear �ʱ갪 ����
	Q->array = (int*)malloc(Q->capacity * sizeof(int));
	if (!Q->array) return NULL;
	return Q;
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty(QueueType* Q) {
	return((Q->front) == -1);
}

// ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull(QueueType* Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

//����Լ�
void print_Queue(QueueType* Q) {
	for (int i = Q->front; i == Q->rear; (i + 1) % Q->capacity) printf("%d	|	", Q->array[i]);
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) printf(" Queue Overflow\n");
	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;
		if (Q->front == -1)	Q->front = Q->rear; // ù �������� ��� f=r=0 �̵Ǿ�� ��
	}
	print_Queue(Q);
}

//���� ť�� front���� ���Ҹ� �����ϰ� ��ȯ�ϴ� ����
element deQueue(QueueType* Q) {
	int data = 0;
	if (isEmpty(Q)) {
		printf(" Queue is empty");
		exit(1);
	}
	else {
		data = Q->array[Q->front];
		//������°� �Ǿ����� �ǹ��Ѵ�
		if (Q->front == Q->rear) Q->front = Q->rear = -1;
		else Q->front = (Q->front + 1) % Q->capacity;
	}
	print_Queue(Q);
	return data;
}

//ť ���� ����
void deleteQueue(QueueType* Q) {
	if (Q) {
		if (Q->array) free(Q->array);
	}
	free(Q);
}

int main(void) {
	int i = 0;
	printf("���� ť�� ũ�⸦ �Է��Ͻÿ�: ");
	scanf("%d", &i);

	QueueType* q = Queue(i);

	printf("enqueue����\n");
	for (int i = 1; i <= 5; i++) enQueue(q, i * 10);

	printf("\ndequeue����\n");
	for (int i = 1; i <= 3; i++) printf("dequeue: %d\n", deQueue(q));

	printf("\nenqueue����\n");
	for (int i = 6; i <= 10; i++) enQueue(q, i * 10);

	printf("\ndequeue����\n");
	for (int i = 1; i <= 3; i++) printf("dequeue: %d\n", deQueue(q));
	return 0;
}