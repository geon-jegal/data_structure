/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	int top;
	element* data; // data은 포인터로 정의된다.
	int capacity; //현재 스택의 전체 크기 size
}StackType;

void init_stack(StackType* s, int size) {
	s->top = -1;
	s->capacity = size;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (s->capacity - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		return -1;
	}
	else return s->data[(s->top)--]; // top의 위치만 이동 한 것이고 배열 안의 데이터는 그대로 남아있음
}

int main(void) {
	StackType s1;
	srand(time(NULL));
	int random_size = rand()%100;
	init_stack(&s1, random_size);

	for (int i = 0; i <= random_size; i++) push(&s1, i * 10);

	for (int i = random_size; i >= 0; i--) printf("Stack top : %d data : %d\n", i, pop(&s1));

	printf("Stack Random_size : %d\n", random_size);

	StackType s;
	int size = 0;

	printf("Stack의 크기를 입력하시오: ");
	scanf("%d", &size);

	init_stack(&s, size);

	for(int i = 0; i <= size; i++) push(&s, i * 10);

	for (int i = size; i >= 0; i--) printf("Stack top : %d data : %d\n", i, pop(&s));

	return 0;
}*/