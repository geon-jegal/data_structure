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

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
AVLTreeNode* CreateNode(int data) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	newNode->height = 0; // ���� �ʱ�ȭ
	return newNode;
}

// �θ� ���� �¿� �ڽ� ��带 �����մϴ�.
void MakeTree(AVLTreeNode* parent, AVLTreeNode* lson, AVLTreeNode* rson)
{
	parent->left = lson;
	parent->right = rson;
}

// ���ο� ��带 �����ϰ� �ʱ�ȭ�մϴ�.
AVLTreeNode* newNode(int item) {
	AVLTreeNode* newNode = (AVLTreeNode*)malloc(sizeof(AVLTreeNode));
	if (newNode == NULL) {
		printf("�޸� ����");
		exit(1);
	}
	newNode->data = item;
	newNode->height = 0; // ���� �ʱ�ȭ
	newNode->left = newNode->right = NULL;
	return newNode;
}

// �ܼ�ȸ��(LL)
AVLTreeNode* SingleRotateLeft(AVLTreeNode* X)
{
	AVLTreeNode* W = X->left;
	X->left = W->right;
	W->right = X;
	X->height = max(Height(X->left), Height(X->right)) + 1;
	W->height = max(Height(W->left), Height(W->right)) + 1;
	return W; // new root node;
}

// �ܼ�ȸ��(RR)
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
	//Ʈ���� �����̸� ���ο� ��� �����ϰ� ��ȯ�Ѵ�.
	if (root == NULL) return newNode(key);

	if (root->data == key) { // �����Ͱ� �ߺ��� ���
		printf("�ߺ��� �������Դϴ�.\n");
		return root;
	}

	// �׷��� ������ ��ȯ������ Ʈ���� ��������
	if (key < root->data) root->left = insert_node(root->left, key);
	else if (key > root->data) root->right = insert_node(root->right, key);

	// �ڱ� �ڽ��� ���� ����
	root->height = max(Height(root->left), Height(root->right)) + 1;
	// ���� ����(Balance üũ)
	int balance = Height(root->left) - Height(root->right);

	// LL ��Ȳ
	if (balance > 1 && root->left != NULL && key < root->left->data) {
		printf("LL��Ȳ �߻�\n");
		print_node(root);
		printf("\n%d : %d\n", root->data, root->height);
		printf("\n���� �� ->");
		return SingleRotateLeft(root);
	}

	// RR ��Ȳ
	if (balance < -1 && root->right != NULL && key > root->right->data) {
		printf("RR��Ȳ �߻�\n");
		print_node(root);
		printf("\n%d : %d\n", root->data, root->height);
		printf("\n���� �� ->");
		return SingleRotateRight(root);
	}

	// ��ȯ�� ��Ʈ �����͸� ��ȯ
	return root;
}


AVLTreeNode* min_value_node(AVLTreeNode* node) {
	AVLTreeNode* current = node;

	//�� ���� �ܸ� ��带 ã���� ������
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

//���� Ž�� Ʈ���� Ű�� �־����� Ű�� ����� ��带 �����ϰ�
// ���ο� ��Ʈ ��带 ��ȯ�Ѵ�.
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
			free(root); // ���� ��ó��
			printf("Case2\n");
			return temp;
		}
		else if (root->right == NULL) {
			AVLTreeNode* temp = root->left;
			free(root); // ���� ��ó��
			return temp;
		}

		// ������ ��� ���� �����ʿ� �ִ� ���� �� ���� ���� ���� ���� ���(���� ���)�� ���
		AVLTreeNode* temp = min_value_node(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}

	return root;
}

AVLTreeNode* Delete(AVLTreeNode* root, int data)
{
	AVLTreeNode* temp;
	//data�� ��ġ �˻�
	if (root == NULL)
		printf("Element not there in tree\n");
	else if (data < root->data)
		root->left = Delete(root->left, data);
	else if (data > root->data)
		root->right = Delete(root->right, data);
	//data�� ã�� ���
	else { // case3
		//�ڽ��� 2���� ��� ���� ����Ʈ���� �ִ밪�� ��ü�Ѵ�.
		if (root->left && root->right) {
			printf("Case3\n");
			temp = FindMin(root->right); //���ӳ�� 
			root->data = temp->data;
			root->right = Delete(root->right, root->data);
		}
		else { //�ڽ��� �ϳ� �Ǵ� ���� ���, case1,2
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


//��ȯ���� Ž�� �Լ�
AVLTreeNode* search(AVLTreeNode* node, int key) {
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

int search_count_recursive(AVLTreeNode* node, int key, int count) {
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
AVLTreeNode* search_Iter(AVLTreeNode* node, int key) {
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

	// ���ο� ��带 ����, insert�� �� ���̸� �ʱ�ȭ ���� �ʾ� ������ ��Ȳ�� ���������� �߻����� �ʰ� �Ǿ����ϴ�.
	int i1 = 0, i2 = 0, i3 = 0, i4 = 0, i5 = 0;
	printf("�Է°� : ");
	scanf("%d", &i1);
	AVLTreeNode* AVLNode = NULL;
	AVLNode = CreateNode(i1);
	print_node(AVLNode);
	printf("\n");

	printf("�Է°� : ");
	scanf("%d", &i2);
	AVLNode = insert_node(AVLNode, i2);
	print_node(AVLNode);
	printf("\n");

	printf("�Է°� : ");
	scanf("%d", &i3);
	AVLNode = insert_node(AVLNode, i3);
	print_node(AVLNode);
	printf("\n");

	printf("�Է°� : ");
	scanf("%d", &i4);
	AVLNode = insert_node(AVLNode, i4);
	print_node(AVLNode);
	printf("\n");

	printf("�Է°� : ");
	scanf("%d", &i5);
	AVLNode = insert_node(AVLNode, i5);
	print_node(AVLNode);

	return 0;
}