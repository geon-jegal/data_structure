#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//top, size, full, empty, swap, printf


#define max_size 100

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

    printf("TOP\n");
    do {
        printf("|%d|\n", Top->data);
        Top = Top->under;
    } while (Top != NULL);
    printf("BOTTOM\n");
    if (isFullStack(Top)) return;
}

void push(Stack** Top, int data) {
    Stack* newNode = NULL;

    newNode = (Stack*)malloc(sizeof(Stack));
    if (isFullStack(*Top)) return;
    //리스트 맨 앞에 새로운 노드를 추가합니다.
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
    { //Top 위치(리스트 맨 앞)에 있는 노드를 제거합니다 
        temp = *Top;
        *Top = temp->under;
        data = temp->data;
        free(temp); // 노드 제거
    }
    return data;
}

void Top(Stack* Top) {//peek함수
    printf("\ntop: %d\n", Top->data);
    //return Top->data;
}

int size(Stack* Top) {
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

    for (int i = 0; i < 9; i++) {
        push(&S, i * 10);
    }

    printf("\n");
    printf("%d poped from stack\n", pop(&S));
    printStack(S);

    Top(S);

    printf("size: %d\n\n", size(S));

    printStack(S);


    return 0;
}