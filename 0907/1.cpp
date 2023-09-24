#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>

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

// ����Լ�
/*
void print_Queue(QueueType* Q) {
	if (isEmpty(Q)) {
		printf("Queue is empty\n");
		return;
	}

	int i = Q->front;
	do {
		printf("%d | ", Q->array[i]);
		i = (i + 1) % Q->capacity;
	} while (i != (Q->rear + 1) % Q->capacity);
	printf("\n");
}*/


//����Լ�
void print_Queue(QueueType* Q) {
	for (int i = Q->front; i != (Q->rear + 1) % Q->capacity; i = (i + 1) % Q->capacity) printf("%d	|	", Q->array[i]);
	printf("\n");
}

// ���� ť�� ���� �������� �˻��ϴ� ����
int isEmpty(QueueType* Q) {
	return((Q->front) == -1);
}

// ���� ť�� ��ȭ �������� �˻��ϴ� ����
int isFull(QueueType* Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

// ���� ť�� rear�� ���Ҹ� �����ϴ� ����
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) printf(" Queue Overflow\n");
	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;
		if (Q->front == -1)	Q->front = Q->rear; // ù �������� ��� f=r=0 �̵Ǿ�� ��
	}
	//  print_Queue(Q);
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
	// print_Queue(Q);
	return data;
}

//ť ���� ����
void deleteQueue(QueueType* Q) {
	if (Q) {
		if (Q->array) free(Q->array);
	}
	free(Q);
}

#define MAX_STACK_SIZE 2 //�ӽ÷� �ִ� ũ�� 2�� ����

typedef struct {
	int top;// top���� ���� ������ ũ��
	int* array; // array�� �������� ������ �����Ѵ�.
	int capacity; //������ ��ü ũ��, size
}ArrayStack;

ArrayStack* createStack() {
	ArrayStack* S = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (!S) {
		return NULL;
	}
	S->capacity = MAX_STACK_SIZE;
	S->top = -1;
	S->array = (int*)malloc(S->capacity * sizeof(int));
	if (!S->array) {
		return NULL;
	}
	return S;
}

int is_empty(ArrayStack* s) {
	return (s->top == -1);
}

int is_full(ArrayStack* s) {
	return (s->top == (s->capacity - 1));
}

void push(ArrayStack* s, int item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->array = (int*)realloc(s->array, s->capacity * sizeof(int));
		//printf("Let's extend the array by double\n");
		//printf("size of array: %d\n", s->capacity);
	}
	//printf("push: %d\n", item);
	s->array[++(s->top)] = item;
}

int pop(ArrayStack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return -1;
	}
	else return s->array[(s->top)--]; // top�� ��ġ�� �̵� �� ���̰� �迭 ���� �����ʹ� �״�� ��������
}

// ��ũ�Լ�
int peek(ArrayStack* S)
{
	if (is_empty(S)) {
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else return S->array[S->top]; //top�� �ִ� �� ���
}

void deleteStack(ArrayStack* S) {
	if (S) {
		if (S->array) free(S->array);
		free(S);
	}
}

int Stacksize(ArrayStack* S) {
	if (is_empty(S)) {
		fprintf(stderr, "���� ���� ����\n");
		return -1;
	}
	return S->top + 1;
}

int main(void) {
	int n; // ����
	srand((unsigned int)time(NULL)); //seed������ ����ð� �ο� 

	scanf("%d", &n);

	ArrayStack* Stack = createStack();
	QueueType* Q = Queue(n + 1);

	for (int i = 0; i <= n; i++) {
		push(Stack, rand() % 10);
		enQueue(Q, rand() % 10);
	}

	for (int j = n; j > 0; j--) {
		int num1 = pop(Stack);
		if (num1 <= 0) break;
		printf("%dX^%d + ", num1, j);
	}
	int num3 = pop(Stack);
	if (num3 != 0) printf("%d", num3);

	printf("\n");

	for (int k = n; k > 0; k--) {
		int num2 = deQueue(Q);
		if (num2 <= 0) continue;
		printf("%dX^%d + ", num2, k);
	}

	int num4 = deQueue(Q);
	if (num4 != 0) printf("%d", num4);

	return 0;
}