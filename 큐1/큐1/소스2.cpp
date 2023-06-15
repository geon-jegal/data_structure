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

// ù��° ��带 �����ϴ� �Լ�
element deQueue(Queue* head) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head->front == NULL) return 0;

    //head�� ������
    node = head->front;// ù��° ��� ������
    head->front = node->link;
    
    element data = node->data;

    free(node); // ù��° ��� ����

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
    ListNode* temp;
    printf("Linked Queue : [    ");
    Queue* tmp = q;
    while (tmp->front != q->rear) {
        temp = tmp->front;
        tmp->front = tmp->front->link;
        printf("%c  ", temp->data);
    }
    printf("]");
}

int main() {
    Queue* q = creatQueue();
    element data;
    printf("\n ******����******\n");
    printf("\n ���� A>> ");
    enQueue(q, 'A');
    printQ(q);
    printf("\n ���� B>> ");
    enQueue(q, 'B');
    printQ(q);
    printf("\n ���� C>> ");
    enQueue(q, 'C');
    printQ(q);

    printf("\n ���� >> ");
    data = deQueue(q);
    //printQ(q);
    printf("\n ���� ������: %c", data);
    printf("\n ���� >> ");
    data = deQueue(q);
    //printQ(q);
    printf("\n ���� ������: %c", data);
    printf("\n ���� >> ");
    data = deQueue(q);
    //printQ(q);
    printf("\n ���� ������: %c", data);

    printf("\n ���� D>> ");
    enQueue(q, 'D');
    //printQ(q);
    printf("\n ���� E>> ");
    enQueue(q, 'E');
    //printQ(q);

    deleteQueue(q);

    return 0;
}