#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>

// 링크드 리스트(스택)
#define max_size 5000

typedef struct Stack {
    int data;
    struct Stack* under;
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
    //리스트 맨 앞에 새로운 노드를 추가합니다.
    newNode->data = data;
    newNode->under = *Top;
    *Top = newNode;

    //printf("%d pushed to stack\n", data);
}

int pop(Stack** Top) {
    Stack* temp = NULL;
    int data = 0;
    if (IsEmptyStack(*Top)) return INT_MIN;
    else
    { //Top 위치(리스트 맨 앞)에 있는 노드를 제거합니다 
        temp = *Top;
        data = (*Top)->data;
        *Top = (*Top)->under;
        free(temp); // 노드 제거
    }
    return data;
}

int peek(Stack* Top) {//peek함수
    if (IsEmptyStack(Top)) return INT_MIN;

    printf("\npeek_top: %d\n", Top->data);
    return Top->data;
}

int size(Stack* Top) { // 현재 스택의 개수 리턴
    if (isFullStack(Top)) return max_size;
    int size = 0;
    while (Top != NULL) {
        size++;
        Top = Top->under;
    }
    return size;
}

// 다이나믹 어레이
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
        printf("size of array: %d\n", s->capacity);
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
    int arry[10000], y = 0;
    ArrayStack* Ahead = createStack();
    Stack* Lhead = NULL;

    // 삽입
    clock_t array_start1 = clock(); // 함수의 시작 시간 저장
    for (int i = 0; i < 5000; i++) {
        push(Ahead, i);
    }
    clock_t array_finish1 = clock();   // 함수의 종료시간 저장
    double array_duration1 = (double)(array_finish1 - array_start1) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산
    printf("ArrayStack에서 5000개의 값을 넣는 시간 : %lf초\n", array_duration1);

    clock_t list_start2 = clock(); // 함수의 시작 시간 저장
    for (int i = 0; i < 5000; i++) {
        push(&Lhead, i);
    }
    //printStack(Lhead);
    clock_t list_finish2 = clock();   // 함수의 종료시간 저장
    double list_duration2 = (double)(list_finish2 - list_start2) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산
    printf("Linked ListStack에서 5000개의 값을 넣는 시간 : %lf초\n", list_duration2);
    printf("==========================================================================\n");


    clock_t array_start3 = clock(); // 함수의 시작 시간 저장
    for (int i = 0; i < 1000; i++) {
        int j = rand() % 5000;
        Ahead->array[j] += j;
    }
    clock_t array_finish3 = clock();   // 함수의 종료시간 저장
    double array_duration3 = (double)(array_finish3 - array_start3) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산
    printf("ArrayStack에서 랜덤값을 peek하는 시간 : %lf초\n", array_duration3);

    /*
    clock_t array_start4 = clock(); // 함수의 시작 시간 저장
    for (int i = 0; i < 100; i++) {
        int j = rand() % 5000;
        Stack* temp = Lhead;
        for (int k = 0; k < j; k++) {
            if (temp->under != NULL) temp = temp->under;
        }
        temp->data += j;
        free(temp); // 노드 제거
    }
    clock_t array_finish4 = clock();   // 함수의 종료시간 저장
    double array_duration4 = (double)(array_finish4 - array_start4) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산
    printf("Linked ListStack에서 랜덤값을 peek하는 시간 : %lf초\n", array_duration4);
    */

    return 0;
}