#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

typedef struct AVLTreeNode {
	int data;
	struct AVLTreeNode* left, * right;
	int height;
} AVLTreeNode;

void print_node(AVLTreeNode* node) {
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

int max(int a, int b) {
	return (a > b) ? a : b;
}

int Height(AVLTreeNode* root) {
	if (!root) return -1;
	else return root->height;
}

// 새로운 노드를 생성하고 초기화합니다.
AVLTreeNode* CreateNode(int data) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("메모리 오류");
		exit(1);
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	newNode->height = 0; // 높이 초기화
	return newNode;
}

// 부모 노드와 좌우 자식 노드를 설정합니다.
void MakeTree(AVLTreeNode* parent, AVLTreeNode* lson, AVLTreeNode* rson)
{
	parent->left = lson;
	parent->right = rson;
}

// 새로운 노드를 생성하고 초기화합니다.
AVLTreeNode* newNode(int item) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("메모리 오류");
		exit(1);
	}
	newNode->data = item;
	newNode->height = 0; // 높이 초기화
	newNode->left = newNode->right = NULL;
	return newNode;
}

// 단순회전(LL)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // new root node;
}

// 단순회전(RR)
AVLTreeNode* SingleRotateRight(AVLTreeNode* W)
{
	AVLTreeNode* X = W->right;
	W->right = X->left;
	X->left = W;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	return X; // new root node;
}


AVLTreeNode* insert_node(AVLTreeNode* root, int key) {
	//트리가 공백이면 새로운 노드 삽입하고 반환한다.
	if (root == NULL) return newNode(key);

	if (root->data == key) { // 데이터가 중복일 경우
		printf("중복된 데이터입니다.\n");
		return root;
	}

	// 그렇지 않으면 순환적으로 트리를 내려간다
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// 자기 자신의 높이 갱신
	root->height = max(Height(root->left), Height(root->right)) + 1;
	// 균형 유지(Balance 체크)
	int balance = Height(root->left) - Height(root->right);

	// LL 상황
	if (balance > 1 && root->left != NULL && key < root->left->data) {
		printf("LL상황 발생\n");
		print_node(root);
		printf("\n%d : %d\n", root->data, root->height);
		printf("\n수정 후 ->");
		return SingleRotateLeft(root);
	}

	// RR 상황
	if (balance < -1 && root->right != NULL && key > root->right->data) {
		printf("RR상황 발생\n");
		print_node(root);
		printf("\n%d : %d\n", root->data, root->height);
		printf("\n수정 후 ->");
		return SingleRotateRight(root);
	}

	// 변환된 루트 포인터를 반환
	return root;
}


AVLTreeNode* min_value_node(AVLTreeNode* node) {
	AVLTreeNode* current = node;

	//맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL) current = current->left;

	return current;
}

AVLTreeNode* FindMin(AVLTreeNode* node) {
	while (node->left != NULL)
		node = node->left;
	return node;
}

AVLTreeNode* FindMax(AVLTreeNode* node) {
	while (node->right != NULL)
		node = node->right;
	return node;
}

//이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
// 새로운 루트 노드를 반환한다.
AVLTreeNode* delete_node(AVLTreeNode* root, int key) {
	if (root == NULL) return root;

	if (key < root->data) {
		root->left = delete_node(root->left, key);
	}
	else if (key > root->data) {
		root->right = delete_node(root->right, key);
	}
	else {
		if (root->left == NULL) {
			AVLTreeNode* temp = root->right;
			free(root); // 삭제 후처리
			printf("Case2\n");
			return temp;
		}
		else if (root->right == NULL) {
			AVLTreeNode* temp = root->left;
			free(root); // 삭제 후처리
			return temp;
		}

		// 삭제한 노드 기준 오른쪽에 있는 노드들 중 가장 작은 값을 가진 노드(후임 노드)를 사용
		AVLTreeNode* temp = min_value_node(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}

	return root;
}

AVLTreeNode* Delete(AVLTreeNode* root, int data)
{
	AVLTreeNode* temp;
	//data의 위치 검색
	if (root == NULL)
		printf("Element not there in tree\n");
	else if (data < root->data)
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	//data를 찾은 경우
	else { // case3
		//자식이 2개인 경우 왼쪽 서브트리의 최대값과 교체한다.
		if (root->left && root->right) {
			printf("Case3\n");
			temp = FindMin(root->right); //후임노드 
			root->data = temp->data;
			root->right = Delete(root->right, root->data);
		}
		else { //자식이 하나 또는 없는 경우, case1,2
			if (root->left == NULL && root->right == NULL) {
				printf("Case1\n");
			}
			else {
				printf("Case2\n");
			}
			temp = root;
			if (root->left == NULL)
				root = root->right;
			else if (root->right == NULL)
				root = root->left;
			free(temp);
		}
	}
	return root;
}


//순환적인 탐색 함수
AVLTreeNode* search(AVLTreeNode* node, int key) {
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

int search_count_recursive(AVLTreeNode* node, int key, int count) {
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
AVLTreeNode* search_Iter(AVLTreeNode* node, int key) {
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

void inorder_traversal(AVLTreeNode* node) {
	if (node == NULL) return;

	inorder_traversal(node->left);
	printf("%d ", node->data);
	inorder_traversal(node->right);
}

void preorder_traversal(AVLTreeNode* node) {
	if (node == NULL) return;

	printf("%d ", node->data);
	preorder_traversal(node->left);
	preorder_traversal(node->right);
}


int main(void) {

	// 새로운 노드를 생성, insert할 때 높이를 초기화 하지 않아 각각의 상황이 정상적으로 발생하지 않게 되었습니다.
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
	printf("입력값 : ");
	scanf("%d", &i1);
	AVLTreeNode* AVLNode = NULL;
	AVLNode = CreateNode(i1);
	print_node(AVLNode);
	printf("\n");

	printf("입력값 : ");
	scanf("%d", &i2);
	AVLNode = insert_node(AVLNode, i2);
	print_node(AVLNode);
	printf("\n");

	printf("입력값 : ");
	scanf("%d", &i3);
	AVLNode = insert_node(AVLNode, i3);
	print_node(AVLNode);
	printf("\n");

	printf("입력값 : ");
	scanf("%d", &i4);
	AVLNode = insert_node(AVLNode, i4);
	print_node(AVLNode);
	printf("\n");

	printf("입력값 : ");
	scanf("%d", &i5);
	AVLNode = insert_node(AVLNode, i5);
	print_node(AVLNode);

	return 0;
}