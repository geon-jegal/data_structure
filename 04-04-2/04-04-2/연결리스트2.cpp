/*linked list
* �迭, ����ü ������ + linked list
* ���� linked list���� ��� �߰�, �Ǵ� ����
* 
* 
* r=q;
* q=p;
* p=p->link;
* q->link = r;
* 
* Dynamic Array : reallok
* ����ü�� linked list�� �ֱ�
*
#define _CRT_SECURE_NO_WARNINGS

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

//ù��° ��忡 insert�ϴ� �Լ�
ListNode* insert_first(ListNode* head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    //head�� NULL�̸� head�� insert
    if (head == NULL) {
        head = node;
        node->link = head;
    }

    else {
        node->link = head->link;//node->link�� ù��° ���� ����
        head->link = node; // head�� �����͸� ��忡 �����Ͽ� ��带 ù��°�� ����
    }
    return head;
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

ListNode* insert(ListNode* head, element data, int position) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    ListNode* p;
    p = head;

    int i = 0;
    while (p->link != head && i < position) {
        p = p->link;
        i++;
    }
    node->link = p->link;
    p->link = node;

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

//������ ��带 �����ϴ� �Լ�
ListNode* delete_last(ListNode* head) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) return head;

    //head�� ������ 
    ListNode* p;

    if (head == NULL) return head;
    
    // ������ ������ ���� �̵�(������ ������ ��� ������)
    p = head->link;
    do {
        p = p->link;
    } while (p->link != head);

    node = p->link; // ������ ���
    p->link = head->link; // ������ ��� �и�
    head = p; //head�� �ڷ� ��ȯ
    free(node); // ������ ��� ����
    return head;
}

ListNode* Delete(ListNode* head, int position) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) return head;

    //head�� ������ 
    ListNode* p;
    p = head;

    int i = 0;
    while (p->link != head && i < position) {
        p = p->link;
        i++;
    }

    // ������ ��忡�� �����ؾ��Ѵٸ� ������ ����
    if (p->link == head) {
        node = p->link; // ������ ���
        p->link = head->link; // ������ ��� �и�
        head = p; //head�� �ڷ� ��ȯ
        free(node); // ������ ��� ����
        return head;
    }

    node = p->link; // �����ؾ� �� ��� ������
    p->link = node->link; // ��� �и�
    free(node); // �ش� ��� ����
    return head;
}

int main() {
    ListNode* head = NULL;

    for (int i = 0; i < 5; i++) {
        head = insert_last(head, i * 10);
        print_list(head);
    }
    head = Delete(head, 2);
    print_list(head);

    head = delete_first(head);
    print_list(head);

    head = delete_last(head);
    print_list(head);

    free(head);

    return 0;
}*/