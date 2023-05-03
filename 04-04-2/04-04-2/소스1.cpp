/*linked list
* 배열, 구조체 포인터 + linked list
* 순수 linked list에서 기능 추가, 또는 변경
* 
* 
* r=q;
* q=p;
* p=p->link;
* q->link = r;
* 
* Dynamic Array : reallok
* 구조체를 linked list에 넣기
*
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef int element;

//head->link는 첫번째 노드를 가리킴
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

//리스트 출력 함수
void print_list(ListNode* head){
    ListNode* p;

    if (head == NULL) return;
    p = head->link; //첫번째 노드
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);// // 마지막 노드에 도착하면 순환을 끝내라

    printf("%d->\n", p->data); // 마지막 노드 출력
}

//첫번째 노드에 insert하는 함수
ListNode* insert_first(ListNode* head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    //head가 NULL이면 head에 insert
    if (head == NULL) {
        head = node;
        node->link = head;
    }

    else {
        node->link = head->link;//node->link를 첫번째 노드로 연결
        head->link = node; // head의 포인터를 노드에 연결하여 노드를 첫번째로 변경
    }
    return head;
}

//마지막 노드에 insert하는 함수
ListNode* insert_last(ListNode* head, element data){
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;

    //head가 NULL이면 head에 insert
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    //head가 있으면 
    else {
        node->link = head->link; //node->link를 첫번째 노드로 연결
        head->link = node; // head의 포인터를 노드에 연결하여 노드를 첫번째로 변경
        head = node; //노드를 head로 전환(마지막 노드로 전환?) 
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

// 첫번째 노드를 삭제하는 함수
ListNode* delete_first(ListNode* head) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) return head;

    //head가 있으면
    node = head->link;// 첫번째 노드 들고오기
    head->link = node->link; // 마지막 노드를 두번째 노드와 연결시켜 첫번째 노드 분리하기
    free(node); // 첫번째 노드 삭제
    return head;
}

//마지막 노드를 삭제하는 함수
ListNode* delete_last(ListNode* head) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) return head;

    //head가 있으면 
    ListNode* p;

    if (head == NULL) return head;
    
    // 마지막 직전의 노드로 이동(마지막 직전의 노드 들고오기)
    p = head->link;
    do {
        p = p->link;
    } while (p->link != head);

    node = p->link; // 마지막 노드
    p->link = head->link; // 마지막 노드 분리
    head = p; //head를 뒤로 전환
    free(node); // 마지막 노드 삭제
    return head;
}

ListNode* Delete(ListNode* head, int position) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    if (head == NULL) return head;

    //head가 있으면 
    ListNode* p;
    p = head;

    int i = 0;
    while (p->link != head && i < position) {
        p = p->link;
        i++;
    }

    // 마지막 노드에서 삭제해야한다면 다음을 실행
    if (p->link == head) {
        node = p->link; // 마지막 노드
        p->link = head->link; // 마지막 노드 분리
        head = p; //head를 뒤로 전환
        free(node); // 마지막 노드 삭제
        return head;
    }

    node = p->link; // 삭제해야 할 노드 꺼내기
    p->link = node->link; // 노드 분리
    free(node); // 해당 노드 삭제
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