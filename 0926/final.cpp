#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left, * right;
} BSTNode;

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
BSTNode* CreateNode(int data) {
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

// �θ� ���� �¿� �ڽ� ��带 �����մϴ�.
void MakeTree(BSTNode* parent, BSTNode* lson, BSTNode* rson)
{
	parent->left = lson;
	parent->right = rson;
}

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
BSTNode* newNode(int item) {
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

	if (key < root->data) {
		root->left = delete_node(root->left, key);
	}
	else if (key > root->data) {
		root->right = delete_node(root->right, key);
	}
	else {
		if (root->left == NULL) {
			BSTNode* temp = root->right;
			free(root); // ���� ��ó��
			return temp;
		}
		else if (root->right == NULL) {
			BSTNode* temp = root->left;
			free(root); // ���� ��ó��
			return temp;
		}

		BSTNode* temp = min_value_node(root->right);
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

int search_count_recursive(BSTNode* node, int key, int count) {
	if (node == NULL) {
		return count; // �����͸� ã�� ���� ��� ��������� Ž�� Ƚ�� ��ȯ
	}

	count++;

	if (key == node->data) {
		return count;
	}
	else if (key < node->data) {
		return search_count_recursive(node->left, key, count);
	}
	else {
		return search_count_recursive(node->right, key, count);
	}
}

// �ݺ����� Ž�� �Լ�
BSTNode* search_Iter(BSTNode* node, int key) {
	int level = 0;
	while (node != NULL) {
		if (key == node->data) {
			level++;
			printf("\nƮ���� �˻� Ƚ��(iter) : %d\n", level);
			return node;
		}
		else if (key < node->data) {
			node = node->left;
			level++;
		}
		else {
			node = node->right;
			level++;
		}
	}
	printf("�����͸� �˻����� �� �Ͽ����ϴ�.\n");
	printf("Ʈ���� �˻� Ƚ��(iter) : %d\n", level);
	return NULL; // Ž���� �������� ��� NULL ��ȯ
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

	printf("\nlevel order\n");
	level_order(root_randBST);

	int deep = tree_depth(root_randBST);

	printf("\nƮ���� ����: %d\n", deep + 1);

	int key = rand() % 2000;

	BSTNode* search_node = NULL;

	printf("�˻��Ϸ��� �� : %d\n", key);

	search_node = search_Iter(root_randBST, key);

	search_node = search(root_randBST, key);
	int count2 = 0;
	count2 = search_count_recursive(root_randBST, key, count2);
	printf("Ʈ���� �˻� Ƚ��(recursion) : %d\n", count2);
	return 0;
}