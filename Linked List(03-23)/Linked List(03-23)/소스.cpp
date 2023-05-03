#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>


typedef int element;
typedef struct {
	int max_size, size; // max_size : 리스트의 최대크기, size : 현재 리스트의 개수
	element* pA; // 리스트 포인터

}ArryListType;

void creat(ArryListType* L) { // 리스트 동적 할당 ADT
	printf("어떤 크기의 배열을 만들 것인가요? : ");
	scanf_s("%d", &L->max_size);
	L->pA = (element*)malloc(sizeof(element) * L->max_size);
	L->size = 0;
}

void error(const char* message) { // 에러 출력 ADT
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init(ArryListType* L) {
	L->size = 0;
}

int is_empty(ArryListType* L) { // 리스트가 비었는지를 검사한다.
	return L->size == 0;
}

int is_full(ArryListType* L) { // 리스트가 꽉 찼는지를 검사한다.
	return L->size == L->max_size;
}

element get_entry(ArryListType* L, int pos) { // pos 위치의 요소를 반환한다.
	if (pos < 0 || pos >= L->size) {
		error("error");
	}

	return L->pA[pos];
}

void print_list(ArryListType* L) { //리스트의 모든 요소를 표시한다.
	printf("리스트 출력 : ");
	for (int i = 0; i < L->size; i++) printf("%d->", L->pA[i]);
	printf("null 종료\n");
	printf("\n");
}

void insert_last(ArryListType* L, element item) { // 리스트의 마지막에 item을 추가합니다.
	if (L->size >= L->max_size) error("리스트 오버플로우");
	L->pA[L->size++] = item;
}

void insert(ArryListType* L, int pos, element item) {
	if (!is_full(L) && (pos <= L->size)) {
		for (int i = (L->size - 1); i >= pos; i--) L->pA[i + 1] = L->pA[i];
		L->pA[pos] = item;
		L->size++;//L->pA[L->size++] = a;//pA[size]에 item을 넣고 size++한다.

	}
}

void insert_new(ArryListType* L) { // 사용자의 입력을 받아 리스트의 마지막에 Item을 추가한다.
	int a;
	printf("input an interger number : ");
	scanf_s("%d", &a);
	if (!is_full(L)){
		L->pA[L->size++] = a;//pA[size]에 item을 넣고 size++한다 무조건 마지막에 입력
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

element Delete(ArryListType* L, int pos) { // pos위치의 요소를 제거한다
	element item;

	if (pos < 0 || pos >= L->max_size) error("위치오류");

	item = L->pA[pos];
	for (int i = pos; i < (L->size - 1); i++) L->pA[i] = L->pA[i + 1];

	L->size--;
	return item;
}


int main() {
	ArryListType* list = (ArryListType*)malloc(sizeof(ArryListType)); // 리스트 생성

	creat(list); // 리스트의 크기를 입력받아 생성

	for (int i = 0; i <= list->max_size - 1; i++) { // 순차적으로 데이터 입력
		insert_new(list);
		print_list(list);
	}
	int a = Delete(list, list->max_size - 1);// 리스트의 마지막item을 추가한다.
	print_list(list);

	find(list, 3);

	free(list->pA);
	free(list);

	return 0;
}
