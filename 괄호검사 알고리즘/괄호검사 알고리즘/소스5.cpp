/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

*/
//top, size, full, empty, swap, printf
/* �������
* prefix, infix, postfix
* postfix - stack
* ���� ����
*/

/*
* 1. ���� ������ element�� ������ ���ϴ� ����
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
    //����Ʈ �� �տ� ���ο� ��带 �߰��մϴ�.
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

bool check_matching(Stack** Top, const char* expr) {
    /*
    * operator : ������
    * operand : �ǿ�����
    *//*
    int i = 0;
    char ch = 0;
    char open_ch;

    while (expr[i] != NULL) { //�Է� expr�� ������ �� ������ ��ȸ�Ѵ�.
        ch = expr[i]; //ch �� expr�� ���� ����
        switch (ch) {
        case '(': case '[': case'{':
            push(Top, ch); //ch�� ���ÿ� ����
            break;
        case ')': case ']': case'}':
            // ������ ��� ������(no open bracket) false
            if (IsEmptyStack((*Top))) {
                printStack(*Top);
                printf("no open bracket");
                return false;
            }

            else { //���ÿ��� open_ch�� ������
                open_ch = pop(Top);

                // ���� pop�� ���ڰ� pair�� ���� �ʴٸ�(wrong pair) false
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
        printf("���� ���");
        return true; // ����ִٸ� ture
    }
    //������ ��� ���� ������(no close bracket) false
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
