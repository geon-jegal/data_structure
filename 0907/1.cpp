#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>

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

// 출력함수
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


//출력함수
void print_Queue(QueueType* Q) {
	for (int i = Q->front; i != (Q->rear + 1) % Q->capacity; i = (i + 1) % Q->capacity) printf("%d	|	", Q->array[i]);
	printf("\n");
}

// 원형 큐가 공백 상태인지 검사하는 연산
int isEmpty(QueueType* Q) {
	return((Q->front) == -1);
}

// 원형 큐가 포화 상태인지 검사하는 연산
int isFull(QueueType* Q) {
	return ((Q->rear + 1) % Q->capacity == Q->front);
}

// 원형 큐의 rear에 원소를 삽입하는 연산
void enQueue(QueueType* Q, element item) {
	if (isFull(Q)) printf(" Queue Overflow\n");
	else {
		Q->rear = (Q->rear + 1) % Q->capacity;
		Q->array[Q->rear] = item;
		if (Q->front == -1)	Q->front = Q->rear; // 첫 데이터의 경우 f=r=0 이되어야 함
	}
	//  print_Queue(Q);
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
	// print_Queue(Q);
	return data;
}

//큐 삭제 연산
void deleteQueue(QueueType* Q) {
	if (Q) {
		if (Q->array) free(Q->array);
	}
	free(Q);
}

#define MAX_STACK_SIZE 2 //임시로 최대 크기 2로 수정

typedef struct {
	int top;// top이자 현재 스택의 크기
	int* array; // array는 실질적인 스택을 구현한다.
	int capacity; //스택의 전체 크기, size
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
		fprintf(stderr, "스택 공백 에러\n");
		return -1;
	}
	else return s->array[(s->top)--]; // top의 위치만 이동 한 것이고 배열 안의 데이터는 그대로 남아있음
}

// 피크함수
int peek(ArrayStack* S)
{
	if (is_empty(S)) {
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else return S->array[S->top]; //top에 있는 값 출력
}

void deleteStack(ArrayStack* S) {
	if (S) {
		if (S->array) free(S->array);
		free(S);
	}
}

int Stacksize(ArrayStack* S) {
	if (is_empty(S)) {
		fprintf(stderr, "스택 공백 에러\n");
		return -1;
	}
	return S->top + 1;
}

int main(void) {
	int n; // 차수
	srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여 

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