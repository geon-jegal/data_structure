#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left, * right;
} BSTNode;

// 새로운 노드를 생성하고 초기화합니다.
BSTNode* NewNode(int item) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (newNode == NULL) {
		printf("메모리 오류");
		exit(1);
	}
	newNode->data = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTNode* insert_node(BSTNode* root, int key) {
	//트리가 공백이면 새로운 노드 삽입하고 반환한다.
	if (root == NULL) return NewNode(key);

	if (root->data == key) { // 데이터가 중복일 경우
		//printf("중복된 데이터입니다.\n");
		return root;
	}

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// 변환된 루트 포인터를 반환
	return root;
}

//순환적인 탐색 함수
BSTNode* search(BSTNode* node, int key) {
	if (node == NULL) {
		//printf("데이터를 검색하지 못 하였습니다.\n");
		return NULL;
	}
	if (key == node->data) {
		//printf("%d", node->data);
		return node; // (1)
	}
	else if (key < node->data)
		return search(node->left, key); // (2)
	else
		return search(node->right, key); // (3)
}

void DeleteTree(BSTNode* node) {
	if (node == NULL)
		return;

	// 먼저 왼쪽 서브트리를 삭제
	DeleteTree(node->left);

	// 다음으로 오른쪽 서브트리를 삭제
	DeleteTree(node->right);

	// 현재 노드를 삭제
	free(node);
}