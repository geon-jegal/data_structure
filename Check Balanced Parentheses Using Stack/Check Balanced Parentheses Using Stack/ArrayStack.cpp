/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
typedef char element;

typedef struct {
	int top;
	char data[MAX_STACK_SIZE];
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType *s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
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
		exit(1);
	}
	else return s->data[(s->top)--]; //top의 위치만 이동 한 것이고 배열 안의 데이터는 그대로 남아있음
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int bracket_checker(char* exp) {
	StackType s;
	char ch, open_ch;

	int len = strlen(exp);
	init_stack(&s);

	//문자열 길이만큼 반복

	for (int i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
			//만약 여는 괄호라면, 스택에 push
		case '(': case '[': case'{':
			push(&s, ch);
			break;

			// 닫는 괄호라면, 스택에서 pop하여 비교(같지 않다면 오류)
		case ')': case ']': case'}':
			if (is_empty(&s)) return 0; //오류
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) return 0;
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0;
	return 1;
}

int main(void) {
	FILE* fp;
	char str[1024] = { 0 };
	fp = fopen("Data.txt", "rt");

	while (!feof(fp)) {
		fscanf(fp, "%s", str);

		if (bracket_checker(str)) printf("%s 괄호 검사 성공 \n", str);
		else printf("%s 괄호 검사 실패 \n", str);
	}
	return 0;
}*/