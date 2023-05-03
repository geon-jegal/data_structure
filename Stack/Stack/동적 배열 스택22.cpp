#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_STACK_SIZE 100

typedef struct {
	int top;
	int* array; // array는 실질적인 스택을 구현한다.
	int capacity; //현재 스택의 전체 크기 size
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
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->array[++(s->top)] = item;
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
	else return S->array[S->top];
}
void deleteStack(ArrayStack* S) {
	if (S) {
		if (S->array)
			free(S->array);
		free(S);
	}
}

int main(void) {
	ArrayStack* mys;
	mys = createStack();
	for (int i = 0; i < 5; i++) {
		push(mys, i);
	}
	printf("%d\n", peek(mys));
	for (int j = 0; j < 5; j++) {
		int tmp = pop(mys);
		printf("%d\n", tmp);
	}
	deleteStack(mys);
	return 0;

}