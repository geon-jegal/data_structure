/*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

int err = 0;

typedef char element;

// ===== ���� �ڵ��� ���� ===== 
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s)
{
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== ���� �ڵ��� �� ===== 

// �������� �켱������ ��ȯ�Ѵ�.
int prec(char op)
{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

// ���� ǥ�� ���� -> ���� ǥ�� ����
 char* infix_to_postfix(char exp[])
{
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;
	init_stack(&s); // ���� �ʱ�ȭ
	for (i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/': // ������
			// ���ÿ� �ִ� �������� �켱����
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(': // ���� ��ȣ
			push(&s, ch);
			break;
		case ')': // ������ ��ȣ
			top_op = pop(&s);
			// ���� ��ȣ�� ���������� ���
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: // �ǿ�����
			printf("%c", ch);
			break;
		}
	}
	char * ch[50] = {};
	while (!is_empty(&s)) {
		// ���ÿ� ����� �����ڵ� ���
		ch += pop(&s);
		printf("%s", ch);
	}
	return ch;
}

int eval(char exp[])
{
	int op1, op2, value, i = 0;
	int len = strlen(exp);
	char ch;
	StackType s;
	init_stack(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
			value = ch - '0'; // �Է��� �ǿ������̸�
			push(&s, value);
		}
		else { //�������̸� �ǿ����ڸ� ���ÿ��� ����
			op2 = pop(&s);
			op1 = pop(&s);
			switch (ch) { //������ �����ϰ� ���ÿ� ����
			case '+': push(&s, op1 + op2); break;
			case '-': push(&s, op1 - op2); break;
			case '*': push(&s, op1 * op2); break;
			case '/': push(&s, op1 / op2); break;
			}
		}
	}
	return pop(&s);
}

int main(void)
{
	char s[] = "(2+3)*4+9";
	char postfix[50] = {NULL};
	int result;

	printf("����ǥ�ü���: %s \n", s);
	printf("����ǥ�ü���: ");
	postfix = infix_to_postfix(s);
	printf("\n");

	printf("%s", postfix);

	result = eval(postfix);
	printf("������� %d\n", result);

	return 0;
}*/