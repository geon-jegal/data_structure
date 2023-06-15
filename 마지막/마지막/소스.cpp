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

//������ ��忡 insert�ϴ� �Լ�
void enQueue(Queue* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    node->link = NULL;

    //head�� NULL�̸� head�� insert
    if (head->front == NULL) {
        head->front = node;
        head->rear = node;
    }
    //head�� ������
    else {
        head->rear->link = node; // head�� �����͸� ��忡 �����Ͽ� ��带 ù��°�� ����
        head->rear = node; //��带 head�� ��ȯ(������ ���� ��ȯ?)
    }
}

element deQueue(Queue* head) {
    ListNode* node = head->front; // ù ��° ��带 ������

    if (node == NULL) return 0; // ť�� ��������� 0 ��ȯ

    head->front = node->link; // head�� front�� �� ��° ���� ������Ʈ

    if (head->front == NULL) // ť�� ��尡 �ϳ��� ���� ���
        head->rear = NULL; // rear�� NULL�� ������Ʈ

    element data = node->data;
    free(node); // ù ��° ��� ����

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

