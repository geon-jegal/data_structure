#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>

#define max_size 100000 // ����Ʈ�� �ִ�ũ��

typedef struct ListNode {
	int data = 0; // ���� �ڷ�
	struct ListNode* link = NULL; // ���� ��带 ����Ű�µ� ����ϴ� ������
}ListNode;


// ����Ʈ�� ��� �ִ� �� Ȯ���ϴ� �Լ�
bool is_empty(ListNode* head) {
	if (head == NULL) {
		printf("NULL : No element in the list!!\n");
		printf("list is empty\n");
		return true;
	}
	return false;
}

// ����Ʈ�� ���� �� �ִ� �� Ȯ���ϴ� �Լ�
bool is_full(ListNode* head) {
	int size = 0;
	for (ListNode* p = head; p != NULL; p = p->link) size++;
	if (size == max_size) {
		printf("list is full\n");
		return true;
	}
	return false;
}

void print_list(ListNode* head) {
	// ����Ʈ�� ����ִٸ� print ��������
	if (is_empty(head)) return;

	for (ListNode* p = head; p != NULL; p = p->link) printf("%d->", p->data); // �˻� ���
	printf("NULL\n");
}

//�� ó���� ��� ����
ListNode* insert_first(ListNode* head, int value) {
	// ����Ʈ�� ���� á�ٸ� insert��������
	if (is_full(head)) return head;

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p; //head�� p�� �ٲٰ� p->link�� ���� head�� ����

	return head; // head����
}

ListNode* insert_position(ListNode* head, int pos, int value) {

	// ����Ʈ�� ���� á�ٸ� insert��������
	if (is_full(head)) return head;

	// pos�� �ùٸ��� �Է� �Ǿ��� �� �˻�, ����Ʈ�� ũ�⺸�� ũ�� ������ ���� �̵�
	if (pos > max_size) {
		printf("number over list max_size\n");
		return head;
	}

	ListNode* p = head, * q = NULL;

	if (pos == 0) { //ù��° ��忡 insert�� ��
		head->data += value;

		//print_list(head);
		return head;
	}

	// �ش� ��ġ���� �̵�
	int i = 0;
	while ((i < pos) && (p != NULL)) {
		q = p;
		p = p->link;
		i++;
	}

	//�ش� ��ġ�� ��� ����
	q->data += value;

	//print_list(head);

	return head;
}

ListNode* Delete_position(ListNode* head, int pos) {
	// ����Ʈ�� ����ִٸ� delete ��������
	if (is_empty(head)) return head;

	ListNode* p = head, * lst = NULL;

	//num�� �ùٸ��� �ԷµǾ��� �� �˻�, ����Ʈ�� ũ�⺸�� ũ�� ������ ���� �̵�
	if (pos < 0 || pos > max_size) {
		printf("number is out of range\n");
		return head;
	}

	ListNode* removed = (ListNode*)malloc(sizeof(ListNode));

	// �ش� ��ġ�� ���� �տ� ������ ������ ����
	if (pos == 0) {
		removed = head;
		head = removed->link;
		free(removed);

		return head;
	}

	// ���� ���� �ƴϸ� �ش� ��ġ���� �̵�
	int i = 0;
	while ((i < pos) && (removed != NULL)) {
		lst = p;
		p = p->link;
		removed = p->link;
		i++;
	}

	//��尡 ���� �������� ������ �ش� �Լ� ����
	if (removed == NULL) {
		lst->link = NULL;
		free(p);
		free(removed);
		return head;
	}

	// ��� ����
	lst->link = p->link;

	free(p);

	return head;
}

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

void dinsert_pos(DoubleListNode* head, element data, int count) {
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


int main(void) {
	int arry[10000], y = 0;
	ListNode* head = NULL;
	DoubleListNode* dhead = NULL;
	
	// ����
	clock_t array_start = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 10000; i++) {
		arry[i] = i;
		for (int t = 0; t < 500; t++) y++; // �ð� ������ ���� �����ڵ�
	}
	clock_t array_finish = clock();   // �Լ��� ����ð� ����
	double array_duration = (double)(array_finish - array_start) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Array���� 10000���� ���� �ִ� �ð� : %lf��\n", array_duration);

	clock_t list_start = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 10000; i++) {
		head = insert_first(head, i);
		for (int t = 0; t < 500; t++) y++;
	}
	clock_t list_finish = clock();   // �Լ��� ����ð� ����
	double list_duration = (double)(list_finish - list_start) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Linked List���� 10000���� ���� �ִ� �ð� : %lf��\n", list_duration);

	clock_t dlist_start = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 10000; i++) {
		dhead = dinsert_first(dhead, i);
		for (int t = 0; t < 500; t++) y++;
	}
	clock_t dlist_finish = clock();   // �Լ��� ����ð� ����
	double dlist_duration = (double)(dlist_finish - dlist_start) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Doubly Linked List���� 10000���� ���� �ִ� �ð� : %lf��\n", dlist_duration);

	printf("==========================================================================\n");

	// Random Access
	clock_t array_start2 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		arry[j] += 1;
		for (int t = 0; t < 500; t++) y--;
	}
	clock_t array_finish2 = clock();   // �Լ��� ����ð� ����
	double array_duration2 = (double)(array_finish2 - array_start2) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Array���� Random Access�� �ð� : %lf��\n", array_duration2);

	clock_t list_start2 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand()%10000;
		head = insert_position(head, j, j);
		for (int t = 0; t < 500; t++) y--;
	}
	clock_t list_finish2 = clock();   // �Լ��� ����ð� ����
	double list_duration2 = (double)(list_finish2 - list_start2) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Linked List���� Random Access�� �ð� : %lf��\n", list_duration2);

	clock_t dlist_start2 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		dinsert_pos(dhead, j, j);
		for (int t = 0; t < 500; t++) y--;
	}
	clock_t dlist_finish2 = clock();   // �Լ��� ����ð� ����
	double dlist_duration2 = (double)(dlist_finish2 - dlist_start2) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Doubly Linked List���� Random Access�� �ð� : %lf��\n", dlist_duration2);

	printf("==========================================================================\n");

	// ����
	clock_t array_start3 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand()%10000;
		arry[j] = -1;
		for (int t = 0; t < 500; t++) y++;
	}
	clock_t array_finish3 = clock();   // �Լ��� ����ð� ����
	double array_duration3 = (double)(array_finish3 - array_start3) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Array���� 1000���� ���� ������ �ð� : %lf��\n", array_duration3);

	clock_t list_start3 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand()%(1000 - i);
		head = Delete_position(head, j);
		for (int t = 0; t < 500; t++) y--;
	}
	clock_t list_finish3 = clock();   // �Լ��� ����ð� ����
	double list_duration3 = (double)(list_finish3 - list_start3) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Linked List���� 1000���� ���� ������ �ð� : %lf��\n", list_duration3);

	clock_t dlist_start3 = clock(); // �Լ��� ���� �ð� ����
	for (int i = 0; i < 1000; i++) {
		int j = rand() % (1000 - i);
		ddelete_p(&dhead, j);
		for (int t = 0; t < 500; t++) y++;
	}
	clock_t dlist_finish3 = clock();   // �Լ��� ����ð� ����
	double dlist_duration3 = (double)(dlist_finish3 - dlist_start3) / CLOCKS_PER_SEC;  // Iteration�Լ��� �ҿ�ð� ���
	printf("Doubly Linked List���� 1000���� ���� ������ �ð� : %lf��\n", dlist_duration3);

	return 0;
}
