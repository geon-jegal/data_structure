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
	//트리가 공백이면 새로운 노드 삽입하고 반환한다.
	if (root == NULL) return newNode(key);

	if (root->data == key) { // 데이터가 중복일 경우
		printf("중복된 데이터입니다.\n");
		return root;
	}

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// 변환된 루트 포인터를 반환
	return root;
}

BSTNode* min_value_node(BSTNode* node) {
	BSTNode* current = node;

	//맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL) current = current->left;

	return current;
}


//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
// 새로운 루트 노드를 반환한다.
BSTNode* delete_node(BSTNode* root, int key) {
	if (root == NULL) return root;

	// 만약 키가 루트보다 작으면 왼쪽 서브 트리로 이동
	if (key < root->data)
		root->left = delete_node(root->left, key);

	// 만약 키가 루트보다 크면 오른쪽 서브 트리로 이동
	if (key > root->data)
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

//순환적인 탐색 함수
BSTNode* search(BSTNode* node, int key) {
	if (node == NULL) {
		printf("데이터를 검색하지 못 하였습니다.\n");
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

// 반복적인 탐색 함수
BSTNode* search_Iter(BSTNode* node, int key) {
	while (node != NULL) {
		if (key == node->data) return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	printf("데이터를 검색하지 못 하였습니다.\n");
	return NULL; // 탐색에 실패했을 경우 NULL 반환
}

// 반복적인 탐색 함수
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
	return level; // 탐색에 실패했을 경우 NULL 반환
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
		int r = rand() % 1000; // 랜덤한 값을 생성 (여기서는 0부터 99까지의 값 중에서 랜덤하게 선택)
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
	// if (is_full(Q)) printf("큐가 포화상태입니다");

	Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;
	Q->data[Q->rear] = node;
}

element dequeue(QueueType* Q) {
	//  (is_empty) printf("큐가 공백상태입니다");

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

// 트리 출력 함수(gpt)
void print_tree(BSTNode* node, int level) {
	if (node == NULL) return;

	print_tree(node->right, level + 1); // 오른쪽 서브트리 먼저 방문

	for (int i = 0; i < level; i++) {
		printf("    "); // 레벨에 따라 들여쓰기
	}
	printf("%d\n", node->data); // 현재 노드 값 출력

	print_tree(node->left, level + 1); // 왼쪽 서브트리 방문
}

// 노드의 수를 세는 함수
int count_nodes(BSTNode* node) {
	if (node == NULL) return 0;
	return 1 + count_nodes(node->left) + count_nodes(node->right);
}

// 트리 깊이 계산 함수
int tree_depth(BSTNode* node) {
	if (node == NULL) return -1; // 빈 트리는 -1을 반환
	int left_depth = 0;
	left_depth = tree_depth(node->left);
	int right_depth = 0;
	right_depth = tree_depth(node->right);
	return 1 + (left_depth > right_depth ? left_depth : right_depth);
}

int main(void) {

	srand((unsigned int)time(NULL)); //seed값으로 현재시간 부여

	BSTNode* root_randBST = NULL;

	root_randBST = randomTree_BST(50);

	printf("level order\n");
	level_order(root_randBST);
	printf("\n");

	int deep = tree_depth(root_randBST);

	printf("트리의 깊이: %d\n", deep);

	int key = rand() % 2000;

	BSTNode* search_node = NULL;

	printf("검색하려는 값 : %d\n", key);

	search_node = search_Iter(root_randBST, key);
	search_node = search(root_randBST, key);
	int count = 0;
	count = search_Iter_level(root_randBST, key);

	printf("트리의 검색 횟수 : %d\n", count);

	return 0;
}