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
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--]; //top�� ��ġ�� �̵� �� ���̰� �迭 ���� �����ʹ� �״�� ��������
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}

int bracket_checker(char* exp) {
	StackType s;
	char ch, open_ch;

	int len = strlen(exp);
	init_stack(&s);

	//���ڿ� ���̸�ŭ �ݺ�

	for (int i = 0; i < len; i++) {
		ch = exp[i];

		switch (ch) {
			//���� ���� ��ȣ���, ���ÿ� push
		case '(': case '[': case'{':
			push(&s, ch);
			break;

			// �ݴ� ��ȣ���, ���ÿ��� pop�Ͽ� ��(���� �ʴٸ� ����)
		case ')': case ']': case'}':
			if (is_empty(&s)) return 0; //����
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

		if (bracket_checker(str)) printf("%s ��ȣ �˻� ���� \n", str);
		else printf("%s ��ȣ �˻� ���� \n", str);
	}
	return 0;
}*/