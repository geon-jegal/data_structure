#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>


typedef struct ListNode {
	int data = 0; // ���� �ڷ�, size = ��üũ��
	struct ListNode* link = NULL; // ���� ��带 ����Ű�µ� ����ϴ� ������
}ListNode;

//�� ó���� ��� ����(head�� ����?)
ListNode* insert_first(ListNode* head, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value; // p ����
	p->link = head; // head�� ����Ű�� ���� p�� ��ȯ
	head = p; //p�� �ּҸ� head�� ����
	return head; // head����
}

//pre�ڿ� ���ο� ��� ����(pre�� �𸥴ٴ� �������� ����, �츮�� head�� �˰��ִ�.)
ListNode* insert(ListNode* head, ListNode* pre, int value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link; //pre�� ����Ű�� ���� p�� ��ȯ(pre�� ����Ű�� ���� ���� p�� ����)
	pre->link = p; //p�� �ּҸ� pre�� ����(pre�� ����Ű�� ���� ���� p�� ��ȯ)
	return head; // pre�� head�� head���� �ٲ�Ƿ� head ����
}

void insert_last(ListNode* head, int value) {
	ListNode* p2 = head;
	ListNode* lst = (ListNode*)malloc(sizeof(ListNode));
	lst->data = value;
	for (ListNode* p = head; p != NULL; p = p->link) {
		p2 = p; // ������ ��� ������
	}
	p2->link = lst;
	lst->link = NULL;
	/*while (p->link != null) {
	* p = p->link;
	* }
	* p2 = p;
	*/
}

ListNode* delete_first(ListNode* head) {
	//emptyüũ �ʿ�
	ListNode* removed;

	if (head == NULL) {
		printf("NULL : No element in the list!!\n");
		exit(0);
	}
	removed = head;
	head = removed->link;
	free(removed);

	return head;
}

void Delete_last(ListNode* head) {
	//emptyüũ �ʿ�
	if (head == NULL) {
		printf("NULL : No element in the list!!\n");
		exit(0);
	}

	ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
	ListNode* lst = (ListNode*)malloc(sizeof(ListNode));
	for (ListNode* p = head; p->link != NULL; p = p->link) {
		lst = p; // �������� �ٷ� �� ��� ������
		removed = p->link; // ������ ��� ������
	}
	lst->link = NULL;
	free(removed);

}

void print_list(ListNode* head) {
	if (head == NULL) {
		printf("NULL : No element in the list!!\n");
		exit(0);
	}

	for (ListNode* p = head; p != NULL; p = p->link) printf("%d->", p->data); // �˻� ���
	printf("NULL\n");
	// for (ListNode* p = head; p->data == item; p = p->link) // �����͸� �Է¹޴� ���
}

int main() {
	ListNode* head = NULL;

	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i * 10);
		print_list(head);
	}

	insert_last(head, 60);
	print_list(head);

	for (int i = 0; i < 4; i++) {
		head = delete_first(head);
		print_list(head);
	}

	Delete_last(head);
	print_list(head);

	return 0;
}