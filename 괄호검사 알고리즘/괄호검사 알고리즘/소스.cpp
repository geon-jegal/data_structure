/*#define _CRT_SECURE_NO_WARNINGS

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

// ���� ǥ�� ���� ��� �Լ�
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
            value = ch - '0';   // �Է��� �ǿ������̸�
            push(&s, value);
        }
        else {   //�������̸� �ǿ����ڸ� ���ÿ��� ����
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

void check_error(element exp[]) {
    err = -1;
    int len = strlen(exp);

    // error 0 : / ������ �� 0�� ���� ����ó��
    for (int i = 0; i < len; i++) {
        if (i + 1 < len && exp[i] == '/' && exp[i + 1] == '0') {
            printf("<<error �߻�>>\n");
            printf("infix_to_postfix error0: divide by 0\n\n");
            err = 0;
            break;
        }
    }

    int count = 0;
    // error 1 : ��ȣ�� ¦�� ���� ������ ����ó��
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(') {
            count++;
        }
        else if (exp[i] == ')') {
            count--;
        }
    }
    if (count > 0) {
        printf("<<error �߻�>>\n");
        printf("infix_to_postfix error1: ��ȣ ��Ī �Ұ���\n\n");
        err = 1;
    }
    else if (count < 0) {
        printf("<<error �߻�>>\n");
        printf("infix_to_postfix error1: ��ȣ ��Ī �Ұ���2\n\n");
        err = 1;
    }

    // error 2 : ���� ���� ����
    for (int i = 0; i < len; i++) {
        if (exp[i] == '(' || exp[i] == ')') {
            continue;
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            continue;
        }
        else if ('0' <= exp[i] && exp[i] <= '9') {
            continue;
        }
        else {
            printf("<<error �߻�>>\n");
            printf("infix_to_postfix error2: ���� ���� ����\n\n");
            err = 2;
        }
    }

    // error 3 : �� �ڸ� �� �̻��� �� �Է¿� ���� ���� ó��(����: 23, 123, ...)
    int count_len = 0;
    int max_len = 0;
    for (int i = 0; i < len; i++) {
        if ('0' <= exp[i] && exp[i] <= '9') {
            count_len++;
            if (count_len >= max_len) {
                max_len = count_len;
            }
        }
        else {
            count_len = 0;
        }
    }
    if (max_len >= 2) {
        printf("<<error �߻�>>\n");
        printf("infix_to_postfix error3: �� �ڸ��� �̻��� �Է� ����\n\n");
        err = 3;
    }
}

// ���� ��ȯ�Լ�
element* infix_to_postfix(element exp[])
{
    // �Է¹��� ǥ��� ���� �˻�
    check_error(exp);
    // ������ �ִٸ� �ٽ� ����
    if (err != -1) {
        return NULL;
    }

    int i, idx = 0; //i�� for���� �����, idx�� post_arr�� index
    int len = strlen(exp);
    char ch, op;
    StackType s;
    element* postfix_arr = (element*)malloc(MAX_STACK_SIZE);
    if (postfix_arr == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }

    init_stack(&s);  //���� �ʱ�ȭ

    // ���� ǥ������� ǥ���� ���� ��ȸ
    for (int i = 0; i < len; i++)
    {
        // ���� �̴´�
        ch = exp[i];

        // �Ϲ� ���ڶ�� �״�� postfix_arr�� �߰�
        if ('0' <= ch && ch <= '9') {
            postfix_arr[idx++] = ch;
        }

        // ������ +,-,*,/���
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // ������ top ���� ���� �����ں��� �켱������ ���ٸ�
            while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
            {
                // �ش� ������ ��� �߰����ش�.
                postfix_arr[idx++] = peek(&s);
                pop(&s);
            }
            // �ڱ��ڽ��� ���ÿ� �߰��Ѵ�.
            push(&s, ch);
        }

        // '('�� ������ ���ÿ� �߰��Ѵ�.
        else if (ch == '(') {
            push(&s, ch);
        }

        // ')'�� ������ '('�� ���ö� ���� ���ÿ��� pop�Ͽ� �߰����ش�.
        else if (ch == ')') {
            op = pop(&s);
            while (op != '(')
            {
                postfix_arr[idx++] = op;
                op = pop(&s);
            }
        }
    }

    //���� ���ÿ� �����ִ� ������ ��� �߰����ش�.
    while (!is_empty(&s)) {
        op = peek(&s);
        pop(&s);
        postfix_arr[idx++] = op;
    }

    // ���ڿ��� ���� �������ش�.
    postfix_arr[idx] = '\0';
    return postfix_arr;
}

int main(void)
{
    element expression[MAX_STACK_SIZE];
    char word[100];

    // ���� �ݺ���
    while (1) {
        // ���� ǥ��� �Է�
        printf("����ǥ����� �Է� :");
        scanf("%s", expression);

        // ���� ǥ��� �� ��� �� ǥ��
        printf("<����ǥ������� ����ǥ��������� ��ȯ>\n");
        element* result = infix_to_postfix(expression);
        if (err == -1) {
            printf("����ǥ����� : %s\n", result);
            printf("����� : %d\n\n", eval(result));
        }

        // �ٽ� �Է����� ���� �˻�
        int exit = 0;
        while (1) {
            printf("�ٽ� �Է��Ͻðڽ��ϱ�?(yes/no) : ");
            scanf("%s", word);

            // yes�� �ٽ� ����
            if (strcmp(word, "yes") == 0) {
                break;
            }
            // no �� exit = 1�� �� ����
            else if (strcmp(word, "no") == 0) {
                exit = 1;
                break;
            }
            // �̿� ���� yes, no�� �Է� �������� while�� �ٽ� ����
            else {
                printf("yes Ȥ�� no�� �Է����ּ���.\n");
                continue;
            }
        }
        // exit�� 1�̸� (no�Է½�) break�� ���� ����
        if (exit == 1) {
            break;
        }
        else {
            printf("\n");
        }
    }

    return 0;
}*/