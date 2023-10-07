#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE 100
#define MAX_MEANING_SIZE 200

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

int compare(element e1, element e2) {
	return strcmp(e1.word, e2.word);
}

void display(TreeNode* p) {
	if (p != NULL) {
		printf("(");
		display(p->left);
		printf(" % s: % s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");
	}
}

TreeNode* search(TreeNode* root, element key) {
	TreeNode* p = root;
	while (p != NULL) {
		if (compare(key, p->key) == 0) return p;
		else if (compare(key, p->key) < 0) p = p->left;
		else if (compare(key, p->key) > 0) p = p->right;
	}
	return p; // Ž���� �������� ��� NULL ��ȯ
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, element key) {
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (node == NULL) return newNode(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (compare(key, node->key) < 0) node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0) node->right = insert_node(node->right, key);

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return node;
}

BSTNode* min_value_node(BSTNode* node) {
	BSTNode* current = node;

	//�� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL) current = current->left;

	return current;
}

//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
BSTNode* delete_node(BSTNode* root, element key) {
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �̵�
	if (key < root->data)
		root->left = delete_node(root->left, key);

	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �̵�
	if (key < root->data)
		root->right = delete_node(root->right, key);
	else {
		// ù ��°�� �� ��° ���
		if (root->left == NULL) {
			BSTNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			BSTNode* temp = root->left;
			free(root);
			return temp;
		}
		//�� ��° ���
		BSTNode* temp = min_value_node(root->right);

		//�߿� ��ȸ�� �İ� ��带 �����Ѵ�
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

void help() {
	printf("\n **** i: �Է�, d: ����, s: Ž�� , p: ���, q: ���� ****");
}