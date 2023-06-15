/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
*/
//top, size, full, empty, swap, printf
/* �������
* prefix, infix, postfix
* postfix - stack
* ���� ����
*/
/*
#define max_size 5

typedef struct ListStack {
    int data;
    struct ListStack* under;
} Stack;

bool IsEmptyStack(Stack* Top) {
    if (Top == NULL) {
        printf("Stack is Empty\n");
        return true;
    }
    return false;
}

bool isFullStack(Stack* Top) {
    int size = 0;
    if (Top == NULL) return false;
    while (Top != NULL && size <= max_size) {
        size++;
        Top = Top->under;
    }
    if (size >= max_size) {
        printf("Stack is Full\n");
        return true;
    }
    return false;
}

void printStack(Stack* Top) {
    if (IsEmptyStack(Top)) return;

    printf("Stack :TOP");
    do {
        printf("->|%d|", Top->data);
        Top = Top->under;
    } while (Top != NULL);
    printf("\n");
    if (isFullStack(Top)) return;
}

void push(Stack** Top, int data) {
    Stack* newNode = NULL;

    newNode = (Stack*)malloc(sizeof(Stack));
    if (isFullStack(*Top)) return;
    //����Ʈ �� �տ� ���ο� ��带 �߰��մϴ�.
    newNode->data = data;
    newNode->under = *Top;
    *Top = newNode;

    printf("%d pushed to stack\n", data);
}

int pop(Stack** Top) {
    Stack* temp = NULL;
    int data = 0;
    if (IsEmptyStack(*Top)) return INT_MIN;
    else
    { //Top ��ġ(����Ʈ �� ��)�� �ִ� ��带 �����մϴ� 
        temp = *Top;
        data = (*Top)->data;
        *Top = (*Top)->under;
        free(temp); // ��� ����
    }
    return data;
}

int peek(Stack* Top) {//peek�Լ�
    if (IsEmptyStack(Top)) return INT_MIN;

    printf("\npeek_top: %d\n", Top->data);
    return Top->data;
}

int size(Stack* Top) { // ���� ������ ���� ����
    if (isFullStack(Top)) return max_size;
    int size = 0;
    while (Top != NULL) {
        size++;
        Top = Top->under;
    }
    return size;
}

int main(void)
{
    Stack* S = NULL;

    for (int i = 0; i < 10; i++)  push(&S, i * 10);

    int Stack_Data1 = peek(S);

    printf("size: %d\n\n", size(S));
    printStack(S);
    printf("\n%d poped from stack\n", pop(&S));

    int Stack_Data2 = peek(S);

    printf("size: %d\n\n", size(S));

    printStack(S);

    return 0;
}*/