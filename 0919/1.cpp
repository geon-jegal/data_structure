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
	parent->left = lson;
	parent->right = rson;
}

#define MAX_STACK_SIZE 2 //�ӽ÷� �ִ� ũ�� 2�� ����

typedef struct {
	int top;// top���� ���� ������ ũ��
	TreeNode* array; // array�� �������� ������ �����Ѵ�.
	int capacity; //������ ��ü ũ��, size
}ArrayStack;

ArrayStack* createStack() {
	ArrayStack* S = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (!S) {
		return NULL;
	}
	S->capacity = MAX_STACK_SIZE;
	S->top = -1;
	S->array = (TreeNode*)malloc(S->capacity * sizeof(TreeNode));
	if (!S->array) {
		return NULL;
	}
	return S;
}

int is_empty(ArrayStack* s) {
	return (s->top == -1);
}

int is_full(ArrayStack* s) {
	return (s->top == (s->capacity - 1));
}

void push(ArrayStack* s, TreeNode item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->array = (TreeNode*)realloc(s->array, s->capacity * sizeof(TreeNode));
		//printf("Let's extend the array by double\n");
		//printf("size of array: %d\n", s->capacity);
	}
	//printf("push: %d\n", item);
	s->array[++(s->top)] = item;
}


TreeNode* pop(ArrayStack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return &s->array[(s->top)--]; // top�� ��ġ�� �̵� �� ���̰� �迭 ���� �����ʹ� �״�� ��������
}

// ��ũ�Լ�
TreeNode* peek(ArrayStack* S)
{
	if (is_empty(S)) {
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else return &S->array[S->top]; //top�� �ִ� �� ���
}

void deleteStack(ArrayStack* S) {
	if (S) {
		if (S->array) free(S->array);
		free(S);
	}
}

int Stacksize(ArrayStack* S) {
	if (is_empty(S)) {
		fprintf(stderr, "���� ���� ����\n");
		return -1;
	}
	return S->top + 1;
}


void Preorder_iter(TreeNode* root)
{
	ArrayStack* top;
	top = createStack();
	while (1) {
		while (root) {
			printf("%2d", root->data);
			push(top, *root);
			root = root->left;
		}
		if (is_empty(top)) break;
		root = pop(top);
		root = root->right;
	}
	deleteStack(top);
}

void Postorder_iter(TreeNode* root)
{
	ArrayStack* top;
	top = createStack();
	TreeNode* last_visited = NULL;
	TreeNode* temp = NULL;

	while (1) {
		while (root) {
			if (root->right)
				push(top, *root->right); // ������ ���� ���ÿ� �ִ´�
			push(top, *root);
			root = root->left;
		}
		if (is_empty(top)) break;
		temp = peek(top);
		if (temp->right && last_visited == temp->right) {
			root = pop(top);
			printf("%2d	|", root->data);
			last_visited = root;
		}
		else {
			root = temp->right;
		}
	}
	deleteStack(top);
}

void preorder(TreeNode* node) {
	if (node != NULL) {
		printf("%d	|", node->data);
		preorder(node->left);
		preorder(node->right);
	}
}

void postorder(TreeNode* node) {
	if (node != NULL) {
		preorder(node->left);
		preorder(node->right);
		printf("%d	|", node->data);
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
	printf("Postorder: ");
	postorder(root);
	printf("\n");

	printf("Postorder_iter: ");
	Postorder_iter(root);
	printf("\n");

	return 0;
}