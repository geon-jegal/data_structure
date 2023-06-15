/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef char element; // ��ũ ����(element)�� �ڷ����� char�� ����
typedef struct DQNode { // ���� ���� ����Ʈ ��ũ�� ��� ������ ����ü�� ����
	element data;
	struct DQNode* llink;
	struct DQNode* rlink;
} DQNode;

typedef struct { // ��ũ���� ����ϴ� ������ front�� rear�� ����ü�� ����
	DQNode* front, * rear;
} DQueType;

// ���� ��ũ�� �����ϴ� ����
DQueType* createDQue()
{
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// ��ũ�� ���� �������� �˻��ϴ� ����
int isEmpty(DQueType* DQ)
{
	if (DQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}

// ��ũ�� front ������ ���Ҹ� �����ϴ� ����
void insertFront(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->front == NULL) { // ��ũ�� ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->front->llink = newNode;
		newNode->rlink = DQ->front;
		newNode->llink = NULL;
		DQ->front = newNode;
	}
}


// ��ũ�� rear �ڷ� ���Ҹ� �����ϴ� ����
void insertRear(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->rear == NULL) { // ��ũ�� ���� ������ ���
		DQ->front = newNode;
		DQ->rear = newNode;
		newNode->rlink = NULL;
		newNode->llink = NULL;
	}
	else {
		DQ->rear->rlink = newNode;
		newNode->rlink = NULL;
		newNode->llink = DQ->rear;
		DQ->rear = newNode;
	}
}

// ��ũ�� front ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteFront(DQueType* DQ)
{
	DQNode* temp = DQ->front;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = temp->data;
		if (DQ->front->rlink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->front = DQ->front->rlink;
			DQ->front->llink = NULL;
		}
		free(temp);
		return item;
	}
}

// ��ũ�� rear ��带 �����ϰ� ��ȯ�ϴ� ����
element deleteRear(DQueType* DQ)
{
	DQNode* temp = DQ->rear;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = temp->data;
		if (DQ->rear->llink == NULL) {
			DQ->front = NULL;
			DQ->rear = NULL;
		}
		else {
			DQ->rear = DQ->rear->llink;
			DQ->rear->rlink = NULL;
		}
		free(temp);
		return item;
	}
}

void DequePrint(DQueType* DQ) {
	DQNode* temp;
	printf("Deque : [	");
	DQueType* tmp = DQ;
	while (tmp->front != DQ->rear) {
		temp = tmp->front;
		tmp->front = tmp->front->llink;
		printf("%c  ", temp->data);
	}
	printf("]");
}

element get_front(DQueType* DQ) {
	DQNode* temp = DQ->front;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = temp->data;
		free(temp);
		return item;
	}
}

element get_rear(DQueType* DQ) {
	DQNode* temp = DQ->rear;
	element item;
	if (isEmpty(DQ)) return 0;
	else {
		item = temp->data;
		free(temp);
		return item;
	}
}

int main() {

	return 0;
}*/