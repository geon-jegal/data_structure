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
	if (newNode == NULL) {
		printf("Memory Error");
		exit(1);
	}
	newNode->data = item;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BSTNode* insert_node(BSTNode* root, int key) {
	//Ʈ���� �����̸� ���ο� ��� �����ϰ� ��ȯ�Ѵ�.
	if (root == NULL) return newNode(key);

	if (root->data == key) { // �����Ͱ� �ߺ��� ���
		printf("�ߺ��� �������Դϴ�.\n");
		return root;
	}

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return root;
}

BSTNode* min_value_node(BSTNode* node) {
	BSTNode* current = node;

	//�� ���� �ܸ� ��带 ã���� ������
	while (current->left != NULL) current = current->left;

	return current;
}


//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
BSTNode* delete_node(BSTNode* root, int key) {
	if (root == NULL) return root;

	// ���� Ű�� ��Ʈ���� ������ ���� ���� Ʈ���� �̵�
	if (key < root->data)
		root->left = delete_node(root->left, key);

	// ���� Ű�� ��Ʈ���� ũ�� ������ ���� Ʈ���� �̵�
	if (key > root->data)
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

//��ȯ���� Ž�� �Լ�
BSTNode* search(BSTNode* node, int key) {
	if (node == NULL) {
		printf("�����͸� �˻����� �� �Ͽ����ϴ�.\n");
		return NULL;
	}
	if (key == node->data) {
		printf("%d", node->data);
		return node; // (1)
	}
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
	printf("�����͸� �˻����� �� �Ͽ����ϴ�.\n");
	return NULL; // Ž���� �������� ��� NULL ��ȯ
}

// �ݺ����� Ž�� �Լ�
int search_Iter_level(BSTNode* node, int key) {
	int level = 0;
	while (node != NULL) {
		if (key == node->data) {
			level++;
			return level;
		}
		else if (key < node->data)
		{
			node = node->left;
			level++;
		}
		else {
			node = node->right;
			level++;
		}
	}
	return level; // Ž���� �������� ��� NULL ��ȯ
}

BSTNode* FindMin(BSTNode* node) {
	while (node->left != NULL)
		node = node->left;
	return node;
}

BSTNode* FindMax(BSTNode* node) {
	while (node->right != NULL)
		node = node->right;
	return node;
}

BSTNode* randomTree_BST(int num) {
	BSTNode* root = NULL;

	for (int i = 0; i < num; i++) {
		int r = rand() % 1000; // ������ ���� ���� (���⼭�� 0���� 99������ �� �߿��� �����ϰ� ����)
		root = insert_node(root, r);
	}

	return root;
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

// Ʈ�� ��� �Լ�(gpt)
void print_tree(BSTNode* node, int level) {
	if (node == NULL) return;

	print_tree(node->right, level + 1); // ������ ����Ʈ�� ���� �湮

	for (int i = 0; i < level; i++) {
		printf("    "); // ������ ���� �鿩����
	}
	printf("%d\n", node->data); // ���� ��� �� ���

	print_tree(node->left, level + 1); // ���� ����Ʈ�� �湮
}

// ����� ���� ���� �Լ�
int count_nodes(BSTNode* node) {
	if (node == NULL) return 0;
	return 1 + count_nodes(node->left) + count_nodes(node->right);
}

// Ʈ�� ���� ��� �Լ�
int tree_depth(BSTNode* node) {
	if (node == NULL) return -1; // �� Ʈ���� -1�� ��ȯ
	int left_depth = 0;
	left_depth = tree_depth(node->left);
	int right_depth = 0;
	right_depth = tree_depth(node->right);
	return 1 + (left_depth > right_depth ? left_depth : right_depth);
}

int main(void) {

	srand((unsigned int)time(NULL)); //seed������ ����ð� �ο�

	BSTNode* root_randBST = NULL;

	root_randBST = randomTree_BST(50);

	printf("level order\n");
	level_order(root_randBST);
	printf("\n");

	int deep = tree_depth(root_randBST);

	printf("Ʈ���� ����: %d\n", deep);

	int key = rand() % 2000;

	BSTNode* search_node = NULL;

	printf("�˻��Ϸ��� �� : %d\n", key);

	search_node = search_Iter(root_randBST, key);
	search_node = search(root_randBST, key);
	int count = 0;
	count = search_Iter_level(root_randBST, key);

	printf("Ʈ���� �˻� Ƚ�� : %d\n", count);

	return 0;
}