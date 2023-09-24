#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* CreateNode(int data) {
	TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	return newNode;
}

void MakeBinaryTree(TreeNode* parent, TreeNode* lson, TreeNode* rson) {
	parent->left = lson;
	parent->right = rson;
}

#define MAX_STACK_SIZE 2 //임시로 최대 크기 2로 수정

typedef struct {
	int top;// top이자 현재 스택의 크기
	TreeNode* array; // array는 실질적인 스택을 구현한다.
	int capacity; //스택의 전체 크기, size
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

void printStack(ArrayStack* s) {
	for (int i = s->top; i >= 0; i--) {
		printf("%d	|", s->array[i].data);
	}
	printf("\n");
}

void push(ArrayStack* s, TreeNode item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->array = (TreeNode*)realloc(s->array, s->capacity * sizeof(TreeNode));
	}
	s->array[++(s->top)] = item;
}


TreeNode* pop(ArrayStack* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return &s->array[(s->top)--]; // top의 위치만 이동 한 것이고 배열 안의 데이터는 그대로 남아있음
}

// 피크함수
TreeNode* peek(ArrayStack* S)
{
	if (is_empty(S)) {
		fprintf(stderr, "Stack is Empty\n");
		exit(1);
	}
	else return &S->array[S->top]; //top에 있는 값 출력
}

void deleteStack(ArrayStack* S) {
	if (S) {
		if (S->array) free(S->array);
		free(S);
	}
}

int Stacksize(ArrayStack* S) {
	if (is_empty(S)) {
		fprintf(stderr, "스택 공백 에러\n");
		return -1;
	}
	return S->top + 1;
}

void Postorder_iter(TreeNode* root)
{
	ArrayStack* top, * temp;
	top = createStack();
	temp = createStack();
	while (1) {
		while (root) {
			printf("%2d	|", root->data);
			push(temp, *root);
			push(top, *root);
			root = root->right;
		}
		if (is_empty(top)) break;
		root = pop(top);
		root = root->left;
	}
	printf("\n후위 순회 결과값과 완전히 정반대로 나온다는 것을 알 수 있다.\n");
	printf("Postorder_iter\n");
	printStack(temp);
	deleteStack(top);
	deleteStack(temp);
}

void postorder(TreeNode* node) {
	if (node != NULL) {
		postorder(node->left);
		postorder(node->right);
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
	TreeNode* node6 = CreateNode(60);

	MakeBinaryTree(root, node1, node2);
	MakeBinaryTree(node1, node3, node4);
	MakeBinaryTree(node2, node5, node6);

	printf("Postorder\n");
	postorder(root);
	printf("\n");

	printf("Preorder_iter을 수정한 버전\n");
	Postorder_iter(root);
	printf("\n");

	return 0;
}