#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>

#define max_size 100 // ����Ʈ�� �ִ�ũ��


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

//�� ó���� ��� ����(head�� ����?)
ListNode* insert_first(ListNode* head, int value) {
	// ����Ʈ�� ���� á�ٸ� insert��������
	if (is_full(head)) return head;

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = head;
	head = p; //head�� p�� �ٲٰ� p->link�� ���� head�� ����

	//print_list(head);

	return head; // head����
}

//pre�ڿ� ���ο� ��� ����(pre�� �𸥴ٴ� �������� ����, �츮�� head�� �˰��ִ�.)
ListNode* insert(ListNode* head, ListNode* pre, int value) {
	// ����Ʈ�� ���� á�ٸ� insert��������
	if (is_full(head)) return head;

	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = value;
	p->link = pre->link; //pre�� ����Ű�� ���� p�� ��ȯ(pre�� ����Ű�� ���� ���� p�� ����)
	pre->link = p; //p�� �ּҸ� pre�� ����(pre�� ����Ű�� ���� ���� p�� ��ȯ)

	//print_list(head);

	return head; // pre�� head�� head���� �ٲ�Ƿ� head ����
}

void insert_last(ListNode* head, int value) {
	ListNode* p2 = head;

	// ����Ʈ�� ���� á�ٸ� insert��������
	if (is_full(head)) return;
	ListNode* lst = (ListNode*)malloc(sizeof(ListNode));
	lst->data = value;

	// ������ ��� ������
	for (ListNode* p = head; p != NULL; p = p->link) p2 = p;

	p2->link = lst;
	lst->link = NULL;

	//print_list(head);
}

ListNode* insert_position(ListNode* head) {

	// ����Ʈ�� ���� á�ٸ� insert��������
	if (is_full(head)) return head;

	int pos = 0, value = 0;

	//insert�Ϸ��� ��ġ�� �Է��Ѵ�
	printf("what insert list position? ");
	scanf_s("%d", &pos);

	// pos�� �ùٸ��� �Է� �Ǿ��� �� �˻�, ����Ʈ�� ũ�⺸�� ũ�� ������ ���� �̵�
	if (pos > max_size) {
		printf("number over list max_size\n");
		return head;
	}

	//insert �Ϸ��� item�� �Է��Ѵ�
	printf("insert item: ");
	scanf_s("%d", &value);

	ListNode* p = head, * q = NULL;

	ListNode* lst = (ListNode*)malloc(sizeof(ListNode));
	lst->data = value;

	if (pos == 0) { //ù��° ��忡 insert�� ��
		lst->link = head; // head�� ����Ű�� ���� p�� ��ȯ
		head = lst; //p�� �ּҸ� head�� ����

		print_list(head);
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
	q->link = lst;
	lst->link = p;

	print_list(head);

	return head;
}

ListNode* delete_first(ListNode* head) {
	// ����Ʈ�� ����ִٸ� delete ��������
	if (is_empty(head)) {
		print_list(head);
		return head;
	}

	ListNode* removed;

	removed = head;
	head = removed->link;
	free(removed);

	print_list(head);

	return head;

}

void Delete_last(ListNode* head) {
	// ����Ʈ�� ����ִٸ� delete ��������
	if (is_empty(head)) return;

	ListNode* removed = (ListNode*)malloc(sizeof(ListNode));
	ListNode* lst = (ListNode*)malloc(sizeof(ListNode));
	for (ListNode* p = head; p->link != NULL; p = p->link) {
		// �������� �ٷ� �� ��� ������
		lst = p;

		// ������ ��� ������
		removed = p->link;
	}
	lst->link = NULL;
	free(removed);
	print_list(head);
}

ListNode* Delete_position(ListNode* head) {
	// ����Ʈ�� ����ִٸ� delete ��������
	if (is_empty(head)) return head;

	ListNode* p = head, * lst = NULL;

	int pos = 0;

	//�����Ϸ��� ��ġ �Է�
	printf("what delete list position? ");
	scanf_s("%d", &pos);

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

		print_list(head);

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
		print_list(head);
		return head;
	}

	// ��� ����
	lst->link = p->link;

	free(p);
	print_list(head);

	return head;
}

//��� ��带 �����ϴ� �Լ�
void DeleteLinkedList(ListNode* head) {
	ListNode* auxilaryNode, * iterator;
	iterator = head;
	while (iterator) {
		printf("������ ����� ������ : %d\n", iterator->data);
		auxilaryNode = iterator->link;
		free(iterator);
		iterator = auxilaryNode;
	}
	head = NULL;
}

//�˻� �Լ�
ListNode* search_list(ListNode* head, int data) {
	ListNode* p = head;
	while (p != NULL) {
		if (p->data == data) return p;
		p = p->link;
	}
	return NULL;
}

void add(ListNode* head1, ListNode* head2) {
	ListNode* p2 = head1;

	// ����Ʈ�� ���� á�ٸ� insert��������
	if (is_full(head1)) return;
	ListNode* lst = head2;

	// ������ ��� ������
	for (ListNode* p = head1; p != NULL; p = p->link) p2 = p;

	p2->link = lst;

	print_list(head1);
}

void mix(ListNode* head1, ListNode* head2) {
	ListNode* p2 = head1;
	ListNode* p3 = head2;
	// ����Ʈ�� ���� á�ٸ� insert��������
	ListNode* p = head1;

	while (p3 != NULL) {
		p = p2;
		p->link = p3;
		p2 = p2->link;
		p3 = p3->link;
		p = p->link;
	}

	print_list(p);
}


int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 1);
	insert_last(head1, 5);
	insert_last(head1, 11);
	insert_last(head1, 13);
	insert_last(head1, 19);
	print_list(head1);
	head2 = insert_first(head2, 6);
	insert_last(head2, 14);
	insert_last(head2, 25);
	print_list(head2);

	printf("add: ");
	add(head1, head2);

	ListNode* head3 = NULL;
	ListNode* head4 = NULL;

	head3 = insert_first(head3, 1);
	insert_last(head3, 5);
	insert_last(head3, 11);
	insert_last(head3, 13);
	insert_last(head3, 19);
	print_list(head3);
	head4 = insert_first(head4, 6);
	insert_last(head4, 14);
	insert_last(head4, 25);
	print_list(head4);

	//printf("mix: ");
	//mix(head3, head4);

	return 0;
}
