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
	return p; // 탐색에 실패했을 경우 NULL 반환
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, element key) {
	//트리가 공백이면 새로운 노드를 반환한다.
	if (node == NULL) return newNode(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (compare(key, node->key) < 0) node->left = insert_node(node->left, key);
	else if (compare(key, node->key) > 0) node->right = insert_node(node->right, key);

	// 변환된 루트 포인터를 반환
	return node;
}

BSTNode* min_value_node(BSTNode* node) {
	BSTNode* current = node;

	//맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL) current = current->left;

	return current;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
// 새로운 루트 노드를 반환한다.
BSTNode* delete_node(BSTNode* root, element key) {
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리로 이동
	if (key < root->data)
		root->left = delete_node(root->left, key);

	// 만약 키가 루트보다 크면 오른쪽 서브 트리로 이동
	if (key < root->data)
		root->right = delete_node(root->right, key);
	else {
		// 첫 번째나 두 번째 경우
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
		//세 번째 경우
		BSTNode* temp = min_value_node(root->right);

		//중외 순회시 후계 노드를 복사한다
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}
	return root;
}

void help() {
	printf("\n **** i: 입력, d: 삭제, s: 탐색 , p: 출력, q: 종료 ****");
}
