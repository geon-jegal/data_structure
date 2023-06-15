/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

*/
//top, size, full, empty, swap, printf
/* 산술연산
* prefix, infix, postfix
* postfix - stack
* 퀴즈 있음
*/

/*
* 1. 현재 스택의 element의 개수를 구하는 문제
* 2.
*/
/*
#define max_size 100

typedef struct ListStack {
    char data;
    struct ListStack* under;
} Stack;

bool IsEmptyStack(Stack* Top) {
    if (Top == NULL) {
        //printf("Stack is Empty\n");
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

    //printf("Stack :TOP");
    do {
        printf(" %c", Top->data);
        Top = Top->under;
    } while (Top != NULL);
    printf("\n");
    if (isFullStack(Top)) return;
}

void push(Stack** Top, char data) {
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

bool check_matching(Stack** Top, const char* expr) {
    /*
    * operator : 연산자
    * operand : 피연산자
    *//*
    int i = 0;
    char ch = 0;
    char open_ch;

    while (expr[i] != NULL) { //입력 expr의 끝으로 갈 때까지 순회한다.
        ch = expr[i]; //ch ← expr의 다음 글자
        switch (ch) {
        case '(': case '[': case'{':
            push(Top, ch); //ch를 스택에 삽입
            break;
        case ')': case ']': case'}':
            // 스택이 비어 있으면(no open bracket) false
            if (IsEmptyStack((*Top))) {
                printStack(*Top);
                printf("no open bracket");
                return false;
            }

            else { //스택에서 open_ch를 꺼낸다
                open_ch = pop(Top);

                // 만약 pop한 문자가 pair가 맞지 않다면(wrong pair) false
                if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')) {
                    printStack(*Top);
                    printf("wrong pair");
                    return false;
                }
                break;
            }
        }
        i++;
    }
    printStack(*Top);

    if (IsEmptyStack((*Top))) {
        printf("정상 출력");
        return true; // 비어있다면 ture
    }
    //스택이 비어 있지 않으면(no close bracket) false
    else {
        printf("no close bracket");
        return false;
    }
}

int main(void)
{
    Stack* S = NULL;
    const char* exp = "[({2+3}*4)+9]";
    //const char* exp = "[({2+3*4)}+9]"; //worng pair
    //const char* exp = "{(2+3*4)}+9]"; // no open bracket
    //const char* exp = "[({2+3}*4)+9"; // no close bracket

    printf("\nExpression => %s\n", exp);

    check_matching(&S, exp);

    free(S);


    return 0;
}*/
