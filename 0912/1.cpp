#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

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
	for (p = phead->Rightlink; p != phead; p = p->Rightlink) {
		printf("|%d|<->", p->data);
	}
	printf("head\n");
}

//ù ��° ��忡 ��� �߰�
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

//���ϴ� ��ġ�� ��� �����ʿ� ����
void dinsert_pos_right(DoubleListNode* head, element data, int count) {
	DoubleListNode* newnode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	DoubleListNode* before = head;
	newnode->data = data; // ��� ����
	for (int i = 0; i < count && before->Rightlink != head; i++) { // before->Rightlink != head ����� ������ ���ߴ� �ڵ�
		before = before->Rightlink; // Leftlink�� ����ϸ� �ݴ� �������� �̵�
	}
	newnode->Leftlink = before; // �� ����� ���� ��ũ�� before���� ����
	newnode->Rightlink = before->Rightlink; //�� ����� ������ ��ũ�� before����� ������ ��ũ�� ����Ű�� ���� ����
	before->Rightlink->Leftlink = newnode; // before����� ������ ��ũ�� ����Ű�� ����� ���� ��ũ�� �� ���� ����
	before->Rightlink = newnode; //before����� ������ ��ũ�� �� ���� ����
	//printf("left: 0x%p, me: 0x%p, right: 0x%p\n", newnode->Leftlink, newnode, newnode->Rightlink);
}

//���ϴ� ��ġ�� ��� ���ʿ� ����
void dinsert_pos_left(DoubleListNode* head, element data, int count) {
	DoubleListNode* newnode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	DoubleListNode* before = head;
	newnode->data = data; // ��� ����
	for (int i = 0; i < count && before->Rightlink != head; i++) { // before->Rightlink != head ����� ������ ���ߴ� �ڵ�
		before = before->Rightlink; // Leftlink�� ����ϸ� �ݴ� �������� �̵�
	}
	newnode->Rightlink = before; // �� ����� ������ ��ũ�� before���� ����
	newnode->Leftlink = before->Leftlink; //�� ����� ���� ��ũ�� before����� ���� ��ũ�� ����Ű�� ���� ����
	before->Leftlink->Rightlink = newnode; // before����� ���� ��ũ�� ����Ű�� ����� ������ ��ũ�� �� ���� ����
	before->Leftlink = newnode; //before����� ������ ��ũ�� �� ���� ����
	//printf("left: 0x%p, me: 0x%p, right: 0x%p\n", newnode->Leftlink, newnode, newnode->Rightlink);
}

//������ ��忡 ���ο� ��� ����
void dinsert_last(DoubleListNode* head, element data) {
	DoubleListNode* newnode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	DoubleListNode* before = head;
	newnode->data = data; // ��� ����
	while (before->Rightlink != head) { //��峡���� �̵�
		before = before->Rightlink;
	}
	newnode->Leftlink = before; // �� ����� ���� ��ũ�� before���� ����
	newnode->Rightlink = before->Rightlink; //�� ����� ������ ��ũ�� before����� ������ ��ũ�� ����Ű�� ���� ����
	before->Rightlink->Leftlink = newnode; // before����� ������ ��ũ�� ����Ű�� ����� ���� ��ũ�� �� ���� ����
	before->Rightlink = newnode; //before����� ������ ��ũ�� �� ���� ����
	//printf("left: 0x%p, right: %p\n" , before, before->Rightlink);
}

//���ϴ� ��ġ�� ��� ����
void ddelete_pos(DoubleListNode* head, int count) {
	DoubleListNode* before = head;
	DoubleListNode* removed = NULL;
	for (int i = 0; i < count && before->Rightlink->Rightlink != head; i++) { // before->Rightlink != head ����� ������ ���ߴ� �ڵ�
		before = before->Rightlink; // Leftlink�� ����ϸ� �ݴ� �������� �̵�
	}
	removed = before->Rightlink;

	if (removed == head) return;

	before->Rightlink = removed->Rightlink;
	removed->Rightlink->Leftlink = removed->Leftlink;
	free(removed);
}

// ����
int main(void) {
	DoubleListNode* head = NULL;
	printf("�߰� �ܰ�\n");
	head = dinsert_first(head, 0);
	for (int i = 1; i <= 5; i++) {
		dinsert_last(head, i * 10); // head�����ʿ� insert
		//printf("right: 0x%p\n", head->Rightlink);
		print_dlist(head);
	}

	dinsert_pos_right(head, 60, 10); //10��° ���(������ ��ġ)�� 44�� insert
	print_dlist(head);

	dinsert_pos_left(head, 5, 1); // ������ ��忡 10 insert
	print_dlist(head);


	return 0;
}