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

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
AVLTreeNode* newNode(int item) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->data = item;
	newNode->height = 0; // ���� �ʱ�ȭ
	newNode->left = newNode->right = NULL;
	return newNode;
}

// �ܼ�ȸ��(LL)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // new root node;
}

// �ܼ�ȸ��(RR)
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
	//Ʈ���� �����̸� ���ο� ��� �����ϰ� ��ȯ�Ѵ�.
	if (root == NULL) return newNode(key);

	if (root->data == key) { // �����Ͱ� �ߺ��� ���
		//printf("�ߺ��� �������Դϴ�.\n");
		return root;
	}

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// �ڱ� �ڽ��� ���� ����
	root->height = max(Height(root->left), Height(root->right)) + 1;
	// ���� ����(Balance üũ)
	int balance = Height(root->left) - Height(root->right);

	// LL ��Ȳ
	if (balance > 1 && root->left != NULL && key < root->left->data) {
		//printf("LL��Ȳ �߻�\n");
		//print_node(root);
		//printf("\n%d : %d\n", root->data, root->height);
		//printf("\n���� �� ->");
		return SingleRotateLeft(root);
	}

	// RR ��Ȳ
	if (balance < -1 && root->right != NULL && key > root->right->data) {
		//printf("RR��Ȳ �߻�\n");
		//print_node(root);
		//printf("\n%d : %d\n", root->data, root->height);
		//printf("\n���� �� ->");
		return SingleRotateRight(root);
	}

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return root;
}

//��ȯ���� Ž�� �Լ�
AVLTreeNode* search(AVLTreeNode* node, int key) {
	if (node == NULL) {
		//printf("�����͸� �˻����� �� �Ͽ����ϴ�.\n");
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