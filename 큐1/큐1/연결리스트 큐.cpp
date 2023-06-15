/*#define _CRT_SECURE_NO_WARNINGS

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


int main() {

    return 0;
}*/