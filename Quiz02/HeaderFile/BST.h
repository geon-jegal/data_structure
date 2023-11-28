#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left, * right;
} BSTNode;

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
BSTNode* NewNode(int item) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->data = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTNode* insert_node(BSTNode* root, int key) {
	//Ʈ���� �����̸� ���ο� ��� �����ϰ� ��ȯ�Ѵ�.
	if (root == NULL) return NewNode(key);

	if (root->data == key) { // �����Ͱ� �ߺ��� ���
		//printf("�ߺ��� �������Դϴ�.\n");
		return root;
	}

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return root;
}

//��ȯ���� Ž�� �Լ�
BSTNode* search(BSTNode* node, int key) {
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

void DeleteTree(BSTNode* node) {
	if (node == NULL)
		return;

	// ���� ���� ����Ʈ���� ����
	DeleteTree(node->left);

	// �������� ������ ����Ʈ���� ����
	DeleteTree(node->right);

	// ���� ��带 ����
	free(node);
}