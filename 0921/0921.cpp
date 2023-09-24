#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left, * right;
} BSTNode;

BSTNode* CreateNode(int data)
{
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

void MakeTree(BSTNode* parent, BSTNode* lson, BSTNode* rson)
{
	parent->left = lson;
	parent->right = rson;
}

BSTNode* newNode(int item) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	newNode->data = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTNode* insert_node(BSTNode* root, int key) {
	//Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�.
	if (root == NULL) return newNode(key);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return root;
}

//��ȯ���� Ž�� �Լ�
BSTNode* search(BSTNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->data) return node; // (1)
	else if (key < node->data)
		return search(node->left, key); // (2)
	else
		return search(node->right, key); // (3)
}

// �ݺ����� Ž�� �Լ�
BSTNode* search_Iter(BSTNode* node, int key) {
	while (node != NULL) {
		if (key == node->data) return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return NULL; // Ž���� �������� ��� NULL ��ȯ
}

BSTNode* FindMin(BSTNode* node, int key) {
	while (node->left != NULL)
		node = node->left;
	return node;
}

BSTNode* FindMax(BSTNode* node, int key) {
	while (node->right != NULL)
		node = node->right;
	return node;
}

#define MAX_QUEUE_SIZE 100
typedef BSTNode* element;
typedef struct {
	int front, rear;
	element data[MAX_QUEUE_SIZE];
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
}

void init_queue(QueueType* Q) {
	Q->front = Q->rear = 0;
}

int is_empty(QueueType* Q) {
	return (Q->front == Q->rear);
}

int is_full(QueueType* Q) {
	return (Q->rear % MAX_QUEUE_SIZE == Q->front);
}

void enqueue(QueueType* Q, element node) {
	// if (is_full(Q)) printf("ť�� ��ȭ�����Դϴ�");

	Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	Q->data[Q->rear] = node;
}

element dequeue(QueueType* Q) {
	//  (is_empty) printf("ť�� ��������Դϴ�");

	Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;
	return Q->data[Q->front];
}

BSTNode* randomTree_BST(int num) {
	BSTNode* root = NULL;
	int values[100] = { 0 }; // �ִ� 100���� ������ ������ �����մϴ�

	srand((unsigned int)time(NULL));

	for (int i = 0; i < num; i++) {
		int r = rand() % 100;
		if (values[r] == 0) {
			root = insert_node(root, r);
			values[r] = 1;
		}
		else {
			i--; // �̹� ���� ���̶�� i�� ���ҽ��� �ٽ� �õ��մϴ�.
		}
	}

	return root;
}


void level_order(BSTNode* ptr) {
	QueueType q;
	init_queue(&q);

	if (ptr == NULL) return;

	enqueue(&q, ptr);
	while (!is_empty(&q)) {
		ptr = dequeue(&q);
		printf("%d ", ptr->data);
		if (ptr->left) enqueue(&q, ptr->left);
		if (ptr->right) enqueue(&q, ptr->right);
	}
}

void inorder_traversal(BSTNode* node) {
	if (node == NULL) return;

	inorder_traversal(node->left);
	printf("%d ", node->data);
	inorder_traversal(node->right);
}

void preorder_traversal(BSTNode* node) {
	if (node == NULL) return;

	printf("%d ", node->data);
	preorder_traversal(node->left);
	preorder_traversal(node->right);
}


int main(void) {

	BSTNode* root = NULL;

	root = insert_node(root, 18);
	root = insert_node(root, 7);
	root = insert_node(root, 26);
	root = insert_node(root, 3);
	root = insert_node(root, 12);
	root = insert_node(root, 31);
	root = insert_node(root, 27);
	

	printf("level order\n");
	level_order(root);
	printf("\n");

	printf("Inorder Traversal\n");
	inorder_traversal(root); // root�� ���� Ž�� Ʈ���� ��Ʈ ��带 ����ŵ�ϴ�.
	printf("\n");

	printf("Preorder Traversal\n");
	preorder_traversal(root); // root�� ���� Ž�� Ʈ���� ��Ʈ ��带 ����ŵ�ϴ�.
	printf("\n");


	BSTNode* root_randBST = NULL;

	root_randBST = randomTree_BST(7);

	printf("\nlevel order\n");
	level_order(root_randBST);

	printf("\nInorder Traversal\n");
	inorder_traversal(root_randBST);

	printf("\nPreorder Traversal\n");
	preorder_traversal(root_randBST);
	printf("\n");

	return 0;
}