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

// 첫번째 노드를 삭제하는 함수
element deQueue(Queue* head) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head->front == NULL) return 0;

    //head가 있으면
    node = head->front;// 첫번째 노드 들고오기
    head->front = node->link;
    
    element data = node->data;

    free(node); // 첫번째 노드 삭제

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
    printf("\n ******삽입******\n");
    printf("\n 삽입 A>> ");
    enQueue(q, 'A');
    printQ(q);
    printf("\n 삽입 B>> ");
    enQueue(q, 'B');
    printQ(q);
    printf("\n 삽입 C>> ");
    enQueue(q, 'C');
    printQ(q);

    printf("\n 삭제 >> ");
    data = deQueue(q);
    //printQ(q);
    printf("\n 삭제 데이터: %c", data);
    printf("\n 삭제 >> ");
    data = deQueue(q);
    //printQ(q);
    printf("\n 삭제 데이터: %c", data);
    printf("\n 삭제 >> ");
    data = deQueue(q);
    //printQ(q);
    printf("\n 삭제 데이터: %c", data);

    printf("\n 삽입 D>> ");
    enQueue(q, 'D');
    //printQ(q);
    printf("\n 삽입 E>> ");
    enQueue(q, 'E');
    //printQ(q);

    deleteQueue(q);

    return 0;
}