#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>
#include<cstdlib>

typedef int element;
// ���� ���Ḯ��Ʈ ��� Ÿ��
typedef struct DoubleListNode {
	element data;
	struct DoubleListNode* Leftlink; //�� ��带 ����Ű�� ������
	struct DoubleListNode* Rightlink; // �� ��带 ����Ű�� ������
}DoubleListNode;

// ���� ���Ḯ��Ʈ�� ��� ���
void print_dlist(DoubleListNode* phead) {
	DoubleListNode* p;
	printf("head->");
	for (p = phead->Rightlink; p != phead; p = p->Rightlink) {
		printf("|%d|<->", p->data);
	}
	printf("NULL\n");
}

DoubleListNode* dinsert_first(DoubleListNode* head, element data) {
	DoubleListNode* newnode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	newnode->data = data;

	if (head == NULL) {
		newnode->Leftlink = newnode;
		newnode->Rightlink = newnode;
	}
	else {
		newnode->Leftlink = head->Leftlink;
		newnode->Rightlink = head;
		head->Leftlink->Rightlink = newnode;
		head->Leftlink = newnode;
	}
	head = newnode; // head ������ ����

	return head;
}

void dinsert_pos2(DoubleListNode* head, element data, int count) {
	DoubleListNode* before = head;
	for (int i = 0; i < count && before->Rightlink != head; i++) { // before->Rightlink != head ����� ������ ���ߴ� �ڵ�
		before = before->Rightlink; // Leftlink�� ����ϸ� �ݴ� �������� �̵�
	}
	before->data += data;
}

// ���� �����͸� �̿��Ͽ� ����Ʈ�� �տ� ��带 �����ϴ� �Լ�
void ddelete_p(DoubleListNode** h, int position) {
	int k = 1;
	DoubleListNode* removed, * temp;
	removed = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	if (position == 0) { // insertion at beginning
		removed = (*h)->Rightlink;
		if (removed == *h) return;
		(*h)->Rightlink = removed->Rightlink;
		(*h)->Leftlink = removed->Leftlink;
		free(removed);
		return;
	}
	temp = *h;
	do {
		temp = temp->Rightlink;
		k++;
	} while ((k <= position - 1) && temp->Rightlink->Rightlink != *h);
		
	if (temp->Rightlink->Rightlink == *h) {// delete at the end
		removed = temp->Rightlink;
		temp->Rightlink = *h;
		(*h)->Leftlink = removed->Leftlink;
		free(removed);
	}
	else {// insert in the middle
		removed = temp->Rightlink;

		temp->Rightlink = removed->Rightlink;
		removed->Rightlink->Leftlink = removed->Leftlink;
		free(removed);
	}
}

// ����
int main() {
	int arry[10000];
	//////////////////////////////////////////////////////////
	clock_t array_start = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 10000; i++) arry[i] = i;
	clock_t array_finish = clock();   // �Լ��� ����ð� ����

	double array_duration = (double)(array_finish - array_start) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���

	printf("arry���� 10000���� �ִ� �ð� : %lf\n", array_duration);

	DoubleListNode* head = NULL;
	clock_t list_start = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 10000; i++) {
		head = dinsert_first(head, i);
	}
	clock_t list_finish = clock();   // �Լ��� ����ð� ����

	double list_duration = (double)(list_finish - list_start) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���

	printf("list���� 10000���� �ִ� �ð� : %lf\n", list_duration);

/////////////////////////////////////////////////////////////////////
	///// array 1�� ����
	double arry_sum[10000];
	clock_t array_start2 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		arry[j] += 1;
		arry_sum[i] = j;//rand�� ����
	}
	clock_t array_finish2 = clock();   // �Լ��� ����ð� ����

	double array_duration2 = (double)(array_finish2 - array_start2) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���

	printf("arry���� random ���ϴ� �ð� : %lf\n", array_duration2);


	/////// list����
	double list_sum[10000];
	clock_t list_start2 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		dinsert_pos2(head, j, 1);
		list_sum[i] = j;
	}
	clock_t list_finish2 = clock();   // �Լ��� ����ð� ����

	double list_duration2 = (double)(list_finish2 - list_start2) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���

	printf("list���� random ���ϴ� �ð� : %lf\n", list_duration2);
	//////////////////////////////////////////////////////////////////////////////
		/////// arry����
	double arry_sum2[10000];
	clock_t array_start3 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		arry[j] = -1;
		arry_sum2[i] = j;//rand�� ����
	}
	clock_t array_finish3 = clock();   // �Լ��� ����ð� ����

	double array_duration3 = (double)(array_finish3 - array_start3) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���

	printf("arry���� random ���� �ð� : %lf\n", array_duration3);


	///////// list����
	double list_sum2[1000];
	clock_t list_start3 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand() % (1000 - i);
		ddelete_p(&head, j);
		list_sum2[i] = j; // ���� �� ����
	}
	clock_t list_finish3 = clock();   // �Լ��� ����ð� ����

	double list_duration3 = (double)(list_finish3 - list_start3) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���

	printf("list���� random ���� �ð� : %lf\n", list_duration3);

	return 0;
}
