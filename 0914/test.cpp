#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* CreateNode(int data)
{
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

void MakeBinaryTree(TreeNode* parent, TreeNode* lson, TreeNode* rson)
{
	if (parent->left != NULL || parent->right != NULL) {
		printf("is Full");
	}
	else {
		parent->left = lson;
		parent->right = rson;
	}
}

void preorder(TreeNode* node) {
	if (node != NULL) {
		printf("[%d]	", node->data);
		if (node->left != NULL) preorder(node->left);
		if (node->right != NULL) preorder(node->right);
	}
}

int main(void) {

	TreeNode* root = CreateNode(0);
	TreeNode* node1 = CreateNode(10);
	TreeNode* node2 = CreateNode(20);
	TreeNode* node3 = CreateNode(30);
	TreeNode* node4 = CreateNode(40);
	TreeNode* node5 = CreateNode(50);

	MakeBinaryTree(root, node1, node2);
	MakeBinaryTree(node1, node3, node4);
	MakeBinaryTree(node2, node5, NULL);
	preorder(root);


	return 0;
}