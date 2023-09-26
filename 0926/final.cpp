#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct BSTNode {
	int data;
	struct BSTNode* left, * right;
} BSTNode;

// 새로운 노드를 생성하고 초기화합니다.
BSTNode* CreateNode(int data) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (newNode == NULL) {
		printf("메모리 오류");
		exit(1);
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

// 부모 노드와 좌우 자식 노드를 설정합니다.
void MakeTree(BSTNode* parent, BSTNode* lson, BSTNode* rson)
{
	parent->left = lson;
	parent->right = rson;
}

// 새로운 노드를 생성하고 초기화합니다.
BSTNode* newNode(int item) {
	BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
	if (newNode == NULL) {
		printf("메모리 오류");
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

	if (key < root->data) {
		root->left = delete_node(root->left, key);
	}
	else if (key > root->data) {
		root->right = delete_node(root->right, key);
	}
	else {
		if (root->left == NULL) {
			BSTNode* temp = root->right;
			free(root); // 삭제 후처리
			return temp;
		}
		else if (root->right == NULL) {
			BSTNode* temp = root->left;
			free(root); // 삭제 후처리
			return temp;
		}

		BSTNode* temp = min_value_node(root->right);
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

int search_count_recursive(BSTNode* node, int key, int count) {
	if (node == NULL) {
		return count; // 데이터를 찾지 못한 경우 현재까지의 탐색 횟수 반환
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

// 반복적인 탐색 함수
BSTNode* search_Iter(BSTNode* node, int key) {
	int level = 0;
	while (node != NULL) {
		if (key == node->data) {
			level++;
			printf("\n트리의 검색 횟수(iter) : %d\n", level);
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
	printf("데이터를 검색하지 못 하였습니다.\n");
	printf("트리의 검색 횟수(iter) : %d\n", level);
	return NULL; // 탐색에 실패했을 경우 NULL 반환
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

	printf("\nlevel order\n");
	level_order(root_randBST);

	int deep = tree_depth(root_randBST);

	printf("\n트리의 깊이: %d\n", deep + 1);

	int key = rand() % 2000;

	BSTNode* search_node = NULL;

	printf("검색하려는 값 : %d\n", key);

	search_node = search_Iter(root_randBST, key);

	search_node = search(root_randBST, key);
	int count2 = 0;
	count2 = search_count_recursive(root_randBST, key, count2);
	printf("트리의 검색 횟수(recursion) : %d\n", count2);
	return 0;
}