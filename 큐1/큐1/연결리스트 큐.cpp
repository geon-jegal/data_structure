/*#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int element;

//head->link�� ù��° ��带 ����Ŵ
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

//����Ʈ ��� �Լ�
void print_list(ListNode* head){
    ListNode* p;

    if (head == NULL) return;
    p = head->link; //ù��° ���
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);// // ������ ��忡 �����ϸ� ��ȯ�� ������

    printf("%d->\n", p->data); // ������ ��� ���
}

//������ ��忡 insert�ϴ� �Լ�
ListNode* insert_last(ListNode* head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    //head�� NULL�̸� head�� insert
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    //head�� ������
    else {
        node->link = head->link; //node->link�� ù��° ���� ����
        head->link = node; // head�� �����͸� ��忡 �����Ͽ� ��带 ù��°�� ����
        head = node; //��带 head�� ��ȯ(������ ���� ��ȯ?)
    }
    return head;
}

// ù��° ��带 �����ϴ� �Լ�
ListNode* delete_first(ListNode* head) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) return head;

    //head�� ������
    node = head->link;// ù��° ��� ������
    head->link = node->link; // ������ ��带 �ι�° ���� ������� ù��° ��� �и��ϱ�
    free(node); // ù��° ��� ����
    return head;
}


int main() {

    return 0;
}*/