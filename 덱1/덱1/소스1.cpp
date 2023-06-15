/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef char element; // 데크 원소(element)의 자료형을 char로 정의
typedef struct DQNode { // 이중 연결 리스트 데크의 노드 구조를 구조체로 정의
	element data;
	struct DQNode* llink;
	struct DQNode* rlink;
} DQNode;

typedef struct { // 데크에서 사용하는 포인터 front와 rear를 구조체로 정의
	DQNode* front, * rear;
} DQueType;

// 공백 데크를 생성하는 연산
DQueType* createDQue()
{
	DQueType* DQ;
	DQ = (DQueType*)malloc(sizeof(DQueType));
	DQ->front = NULL;
	DQ->rear = NULL;
	return DQ;
}

// 데크가 공백 상태인지 검사하는 연산
int isEmpty(DQueType* DQ)
{
	if (DQ->front == NULL) {
		printf("\n Linked Queue is empty! \n");
		return 1;
	}
	else return 0;
}

// 데크의 front 앞으로 원소를 삽입하는 연산
void insertFront(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->front == NULL) { // 데크가 공백 상태인 경우
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


// 데크의 rear 뒤로 원소를 삽입하는 연산
void insertRear(DQueType* DQ, element item)
{
	DQNode* newNode = (DQNode*)malloc(sizeof(DQNode));
	newNode->data = item;
	if (DQ->rear == NULL) { // 데크가 공백 상태인 경우
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

// 데크의 front 노드를 삭제하고 반환하는 연산
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

// 데크의 rear 노드를 삭제하고 반환하는 연산
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