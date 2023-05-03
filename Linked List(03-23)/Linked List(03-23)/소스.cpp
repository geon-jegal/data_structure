#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>


typedef int element;
typedef struct {
	int max_size, size; // max_size : ����Ʈ�� �ִ�ũ��, size : ���� ����Ʈ�� ����
	element* pA; // ����Ʈ ������

}ArryListType;

void creat(ArryListType* L) { // ����Ʈ ���� �Ҵ� ADT
	printf("� ũ���� �迭�� ���� ���ΰ���? : ");
	scanf_s("%d", &L->max_size);
	L->pA = (element*)malloc(sizeof(element) * L->max_size);
	L->size = 0;
}

void error(const char* message) { // ���� ��� ADT
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArryListType* L) {
	L->size = 0;
}

int is_empty(ArryListType* L) { // ����Ʈ�� ��������� �˻��Ѵ�.
	return L->size == 0;
}

int is_full(ArryListType* L) { // ����Ʈ�� �� á������ �˻��Ѵ�.
	return L->size == L->max_size;
}

element get_entry(ArryListType* L, int pos) { // pos ��ġ�� ��Ҹ� ��ȯ�Ѵ�.
	if (pos < 0 || pos >= L->size) {
		error("error");
	}

	return L->pA[pos];
}

void print_list(ArryListType* L) { //����Ʈ�� ��� ��Ҹ� ǥ���Ѵ�.
	printf("����Ʈ ��� : ");
	for (int i = 0; i < L->size; i++) printf("%d->", L->pA[i]);
	printf("null ����\n");
	printf("\n");
}

void insert_last(ArryListType* L, element item) { // ����Ʈ�� �������� item�� �߰��մϴ�.
	if (L->size >= L->max_size) error("����Ʈ �����÷ο�");
	L->pA[L->size++] = item;
}

void insert(ArryListType* L, int pos, element item) {
	if (!is_full(L) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) L->pA[i + 1] = L->pA[i];
		L->pA[pos] = item;
		L->size++;//L->pA[L->size++] = a;//pA[size]�� item�� �ְ� size++�Ѵ�.

	}
}

void insert_new(ArryListType* L) { // ������� �Է��� �޾� ����Ʈ�� �������� Item�� �߰��Ѵ�.
	int a;
	printf("input an interger number : ");
	scanf_s("%d", &a);
	if (!is_full(L)){
		L->pA[L->size++] = a;//pA[size]�� item�� �ְ� size++�Ѵ� ������ �������� �Է�
	}
}

void find(ArryListType* L, int item) {
	for (int i = (L->size - 1); i >= 0; i--) {
		if (L->pA[i] == item) {
			printf("find %d the position %d\n", L->pA[i], i);
			system("pause");
			exit(0);
		}
	}
	printf("not find");
}

element Delete(ArryListType* L, int pos) { // pos��ġ�� ��Ҹ� �����Ѵ�
	element item;

	if (pos < 0 || pos >= L->max_size) error("��ġ����");

	item = L->pA[pos];
	for (int i = pos; i < (L->size - 1); i++) L->pA[i] = L->pA[i + 1];

	L->size--;
	return item;
}


int main() {
	ArryListType* list = (ArryListType*)malloc(sizeof(ArryListType)); // ����Ʈ ����

	creat(list); // ����Ʈ�� ũ�⸦ �Է¹޾� ����

	for (int i = 0; i <= list->max_size - 1; i++) { // ���������� ������ �Է�
		insert_new(list);
		print_list(list);
	}
	int a = Delete(list, list->max_size - 1);// ����Ʈ�� ������item�� �߰��Ѵ�.
	print_list(list);

	find(list, 3);

	free(list->pA);
	free(list);

	return 0;
}
