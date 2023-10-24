#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct AVLTreeNode {
	int data;
	struct AVLTreeNode* left, * right;
	int height;
} AVLTreeNode;

int max(int a, int b) {
	return (a > b) ? a : b;
}

int Height(AVLTreeNode* root) {
	if (!root) return -1;
	else return root->height;
}

// 새로운 노드를 생성하고 초기화합니다.
AVLTreeNode* newNode(int item) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("메모리 오류");
		exit(1);
	}
	newNode->data = item;
	newNode->height = 0; // 높이 초기화
	newNode->left = newNode->right = NULL;
	return newNode;
}

// 단순회전(LL)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // new root node;
}

// 단순회전(RR)
AVLTreeNode* SingleRotateRight(AVLTreeNode* W)
{
	AVLTreeNode* X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	return X; // new root node;
}


AVLTreeNode* insert_node(AVLTreeNode* root, int key) {
	//트리가 공백이면 새로운 노드 삽입하고 반환한다.
	if (root == NULL) return newNode(key);

	if (root->data == key) { // 데이터가 중복일 경우
		//printf("중복된 데이터입니다.\n");
		return root;
	}

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// 자기 자신의 높이 갱신
	root->height = max(Height(root->left), Height(root->right)) + 1;
	// 균형 유지(Balance 체크)
	int balance = Height(root->left) - Height(root->right);

	// LL 상황
	if (balance > 1 && root->left != NULL && key < root->left->data) {
		//printf("LL상황 발생\n");
		//print_node(root);
		//printf("\n%d : %d\n", root->data, root->height);
		//printf("\n수정 후 ->");
		return SingleRotateLeft(root);
	}

	// RR 상황
	if (balance < -1 && root->right != NULL && key > root->right->data) {
		//printf("RR상황 발생\n");
		//print_node(root);
		//printf("\n%d : %d\n", root->data, root->height);
		//printf("\n수정 후 ->");
		return SingleRotateRight(root);
	}

	// 변환된 루트 포인터를 반환
	return root;
}

//순환적인 탐색 함수
AVLTreeNode* search(AVLTreeNode* node, int key) {
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

void delete_all_nodes(AVLTreeNode* root) {
	if (root == NULL) return;

	delete_all_nodes(root->left);
	delete_all_nodes(root->right);

	free(root);
}