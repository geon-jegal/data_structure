#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

int static arry[7];

typedef struct BSTNode {
	int data;
	struct BSTNode* left, * right;
} BSTNode;

BSTNode* CreateBSTNode(int data) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

BSTNode* InsertBSTNode(BSTNode* root, int data) {
	// Ʈ���� �����̸� ���ο� ��� �����ϰ� ��ȯ�Ѵ�.
	if (root == NULL) return CreateBSTNode(data);

	// �׷��� ������ ��ȯ������ Ʈ���� ��������.
	if (root->left == NULL)
		root->left = CreateBSTNode(data);
	else if (root->right == NULL)
		root->right = CreateBSTNode(data);
	else if (root->left != NULL && root->right != NULL) {
		// ���� �ڽ� ��尡 �̹� �����ϸ� ���� �ڽĺ��� Ȯ���Ѵ�.
		root->left = InsertBSTNode(root->left, data);
	}

	return root;
}

BSTNode* randomTree_BST(int num, int size) {
	//srand((unsigned int)time(NULL)); //seed������ ����ð� �ο�
	BSTNode* root = NULL;

	for (int i = 0; i < num; i++) {
		int r = rand() % 10; // ������ ���� ���� (���⼭�� 0���� 9������ �� �߿��� �����ϰ� ����)
		arry[i] = r;
		root = InsertBSTNode(root, r);
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
	Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	Q->data[Q->rear] = node;
}

element dequeue(QueueType* Q) {
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

void print_node(BSTNode* node) {
	if (node == NULL) return;

	printf("%d ", node->data);

	if (node->left != NULL || node->right != NULL) {
		printf("(");
		if (node->left != NULL) print_node(node->left);
		else printf("NULL");

		printf(", ");

		if (node->right != NULL) print_node(node->right);
		else printf("NULL");

		printf(")");
	}
}

bool checkHeap() {
	bool t = false;
	for (int i = 0; i < 7; i++) {
		if (arry[i] <= arry[(i - 1) / 2]) t = false;
		else return true;
	}
	return t;
}


int main(void) {

	BSTNode* root_randBST = NULL;
	bool t = true;
	int i = 0;
	int size = 7; //root�� ������ Ʈ�� ����� ����

	while (t) {
		i++;
		root_randBST = randomTree_BST(size, size);

		t = checkHeap();
	}
	level_order(root_randBST);
	printf("\ntry: %d\n", i);
	print_node(root_randBST);
	printf("\n\n");

	return 0;
}