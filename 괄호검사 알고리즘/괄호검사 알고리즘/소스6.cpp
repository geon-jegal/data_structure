#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s)
{
    s->top = -1;
}

int is_empty(StackType* s)
{
    return (s->top == -1);
}

int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->data[s->top];
}

int prec(char op)
{
    switch (op) {
    case '(': case ')': return 0;
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1;
}

char* infix_to_postfix(char exp[])
{
    int i = 0;
    char ch, top_op;
    int len = strlen(exp);
    StackType s;
    init_stack(&s);

    char* postfix = (char*)malloc(sizeof(char) * (len + 1)); // ���ڿ��� ������ �޸� ���� �Ҵ�
    int postfix_index = 0;

    for (i = 0; i < len; i++) {
        ch = exp[i];
        switch (ch) {
        case '+': case '-': case '*': case '/':
            postfix[postfix_index++] = ' ';
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))) {
                postfix[postfix_index++] = pop(&s);
                //postfix[postfix_index++] = ' ';
            }
            push(&s, ch);
            break;
        case '(':
            push(&s, ch);
            break;
        case ')':
            top_op = pop(&s);
            while (top_op != '(') {
                postfix[postfix_index++] = top_op;
                top_op = pop(&s);
            }
            break;
        default:
            postfix[postfix_index++] = ch;
            break;
        }
    }

    while (!is_empty(&s)) {
        postfix[postfix_index++] = pop(&s);
    }

    postfix[postfix_index] = '\0'; // ���ڿ��� ���� ǥ��

    return postfix;
}

int eval(char exp[])
{
    int op1, op2, value, i = 0, k = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            if (ch == ' ') {
                int j = pop(&s);
                int t = pop(&s);
                j = j + t * 10;
                printf("%d/", j);
                push(&s, j);
            }
            else {
                value = ch - '0';
                //printf("%d/", value);
                push(&s, value);
            }
        }
        else {
            op2 = pop(&s);
            op1 = pop(&s);

            printf("%d/", op2);
            printf("%d/", op1);
            switch (ch) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            }
        }
        k = i;
    }
    return pop(&s);
}

int main(void)
{
    char s[] = "(23+3)*4+9";
    char* postfix;
    int result;

    printf("����ǥ�ü���: %s \n", s);
    printf("����ǥ�ü���: ");
    postfix = infix_to_postfix(s);
    printf("%s\n", postfix);

    result = eval(postfix);
    printf("������� %d\n", result);

    //free(postfix); // ���� �Ҵ�� �޸� ����

    return 0;
}
