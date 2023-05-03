/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

typedef char element[100];
typedef struct DlistNode{
	string a;
	element data;
	struct DlistNode* LeftLink;
	struct DlistNode* RightLink;
}DlistNode;

DlistNode* current;

void init(DlistNode* phead) {
	phead->LeftLink = phead;
	phead->RightLink = phead;
}

void print_dlist(DlistNode* phead) {
	DlistNode* p;
	for (p = phead->RightLink; p != phead; p = p->RightLink) {
		if (p == current) printf("<-| #%s# | -> ", p->data);
		else printf("<-| %s | -> ", p->data);
	}
	printf("\n");
}

void dinsert(DlistNode* before, const element data) {
	DlistNode* newnode = (DlistNode*)malloc(sizeof(DlistNode));
	strcpy(newnode->data, data);
	newnode->LeftLink = before;
	newnode->RightLink = before->RightLink;
	before->RightLink->LeftLink = newnode;
	before->RightLink = newnode;
}

void ddelete(DlistNode* head, DlistNode* removed) {
	if (removed == head) return;
	// 노드 분리
	removed->LeftLink->RightLink = removed->RightLink;
	removed->RightLink->LeftLink = removed->LeftLink;
	free(removed);
}

int main(){
	char ch;
	DlistNode* head = (DlistNode*)malloc(sizeof(DlistNode));
	init(head);

	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->RightLink;
	print_dlist(head);

	do {
		printf("\n명령어를 입력하시오(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->LeftLink;
			if (current == head) current = current->RightLink;
		}
		else if (ch == '<') {
			current = current->RightLink;
			if (current == head) current = current->RightLink;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');

	return 0;
}
*/