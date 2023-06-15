#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

typedef struct Queue {
    struct ListNode* front;
    struct ListNode* rear;
};

Queue* creatQueue() {
    Queue* Q;
    ListNode* temp;
    Q = (Queue*)malloc(sizeof(Queue));

    if (!Q) return NULL;

    temp = (ListNode*)malloc(sizeof(ListNode));
    Q->front = Q->rear = NULL;

    return Q;
}

//마지막 노드에 insert하는 함수
void enQueue(Queue* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = NULL;

    //head가 NULL이면 head에 insert
    if (head->front == NULL) {
        head->front = node;
        head->rear = node;
    }
    //head가 있으면
    else {
        head->rear->link = node; // head의 포인터를 노드에 연결하여 노드를 첫번째로 변경
        head->rear = node; //노드를 head로 전환(마지막 노드로 전환?)
    }
}

element deQueue(Queue* head) {
    ListNode* node = head->front; // 첫 번째 노드를 가져옴

    if (node == NULL) return 0; // 큐가 비어있으면 0 반환

    head->front = node->link; // head의 front를 두 번째 노드로 업데이트

    if (head->front == NULL) // 큐에 노드가 하나만 있을 경우
        head->rear = NULL; // rear도 NULL로 업데이트

    element data = node->data;
    free(node); // 첫 번째 노드 삭제

    return data;
}

void deleteQueue(Queue* q) {
    ListNode* temp;
    while (q->front) {
        temp = q->front;
        q->front = q->front->link;
        free(temp);
    }
    free(q);
}

void printQ(Queue* q) {
    ListNode* temp = q->front;
    printf("Linked Queue : [ ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->link;
    }
    printf("]\n");
}

