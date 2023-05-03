#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
#include<time.h>
#include<cstdlib>

typedef int element;
// 이중 연결리스트 노드 타입
typedef struct DoubleListNode {
	element data;
	struct DoubleListNode* Leftlink; //앞 노드를 가리키는 포인터
	struct DoubleListNode* Rightlink; // 뒷 노드를 가리키는 포인터
}DoubleListNode;

// 이중 연결리스트의 노드 출력
void print_dlist(DoubleListNode* phead) {
	DoubleListNode* p;
	printf("head->");
	for (p = phead->Rightlink; p != phead; p = p->Rightlink) {
		printf("|%d|<->", p->data);
	}
	printf("NULL\n");
}

DoubleListNode* dinsert_first(DoubleListNode* head, element data) {
	DoubleListNode* newnode = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	newnode->data = data;

	if (head == NULL) {
		newnode->Leftlink = newnode;
		newnode->Rightlink = newnode;
	}
	else {
		newnode->Leftlink = head->Leftlink;
		newnode->Rightlink = head;
		head->Leftlink->Rightlink = newnode;
		head->Leftlink = newnode;
	}
	head = newnode; // head 포인터 변경

	return head;
}

void dinsert_pos2(DoubleListNode* head, element data, int count) {
	DoubleListNode* before = head;
	for (int i = 0; i < count && before->Rightlink != head; i++) { // before->Rightlink != head 노드의 끝에서 멈추는 코드
		before = before->Rightlink; // Leftlink를 사용하면 반대 방향으로 이동
	}
	before->data += data;
}

// 이중 포인터를 이용하여 리스트의 앞에 노드를 삭제하는 함수
void ddelete_p(DoubleListNode** h, int position) {
	int k = 1;
	DoubleListNode* removed, * temp;
	removed = (DoubleListNode*)malloc(sizeof(DoubleListNode));
	if (position == 0) { // insertion at beginning
		removed = (*h)->Rightlink;
		if (removed == *h) return;
		(*h)->Rightlink = removed->Rightlink;
		(*h)->Leftlink = removed->Leftlink;
		free(removed);
		return;
	}
	temp = *h;
	do {
		temp = temp->Rightlink;
		k++;
	} while ((k <= position - 1) && temp->Rightlink->Rightlink != *h);
		
	if (temp->Rightlink->Rightlink == *h) {// delete at the end
		removed = temp->Rightlink;
		temp->Rightlink = *h;
		(*h)->Leftlink = removed->Leftlink;
		free(removed);
	}
	else {// insert in the middle
		removed = temp->Rightlink;

		temp->Rightlink = removed->Rightlink;
		removed->Rightlink->Leftlink = removed->Leftlink;
		free(removed);
	}
}

// 메인
int main() {
	int arry[10000];
	//////////////////////////////////////////////////////////
	clock_t array_start = clock(); // 함수의 시작 시간 저장
	for (int i = 0; i < 10000; i++) arry[i] = i;
	clock_t array_finish = clock();   // 함수의 종료시간 저장

	double array_duration = (double)(array_finish - array_start) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산

	printf("arry에서 10000개를 넣는 시간 : %lf\n", array_duration);

	DoubleListNode* head = NULL;
	clock_t list_start = clock(); // 함수의 시작 시간 저장
	for (int i = 0; i < 10000; i++) {
		head = dinsert_first(head, i);
	}
	clock_t list_finish = clock();   // 함수의 종료시간 저장

	double list_duration = (double)(list_finish - list_start) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산

	printf("list에서 10000개를 넣는 시간 : %lf\n", list_duration);

/////////////////////////////////////////////////////////////////////
	///// array 1로 변경
	double arry_sum[10000];
	clock_t array_start2 = clock(); // 함수의 시작 시간 저장
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		arry[j] += 1;
		arry_sum[i] = j;//rand값 저장
	}
	clock_t array_finish2 = clock();   // 함수의 종료시간 저장

	double array_duration2 = (double)(array_finish2 - array_start2) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산

	printf("arry에서 random 더하는 시간 : %lf\n", array_duration2);


	/////// list변경
	double list_sum[10000];
	clock_t list_start2 = clock(); // 함수의 시작 시간 저장
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		dinsert_pos2(head, j, 1);
		list_sum[i] = j;
	}
	clock_t list_finish2 = clock();   // 함수의 종료시간 저장

	double list_duration2 = (double)(list_finish2 - list_start2) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산

	printf("list에서 random 더하는 시간 : %lf\n", list_duration2);
	//////////////////////////////////////////////////////////////////////////////
		/////// arry삭제
	double arry_sum2[10000];
	clock_t array_start3 = clock(); // 함수의 시작 시간 저장
	for (int i = 0; i < 1000; i++) {
		int j = rand() % 10000;
		arry[j] = -1;
		arry_sum2[i] = j;//rand값 저장
	}
	clock_t array_finish3 = clock();   // 함수의 종료시간 저장

	double array_duration3 = (double)(array_finish3 - array_start3) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산

	printf("arry에서 random 삭제 시간 : %lf\n", array_duration3);


	///////// list삭제
	double list_sum2[1000];
	clock_t list_start3 = clock(); // 함수의 시작 시간 저장
	for (int i = 0; i < 1000; i++) {
		int j = rand() % (1000 - i);
		ddelete_p(&head, j);
		list_sum2[i] = j; // 랜덤 값 저장
	}
	clock_t list_finish3 = clock();   // 함수의 종료시간 저장

	double list_duration3 = (double)(list_finish3 - list_start3) / CLOCKS_PER_SEC;  // Iteration함수의 소요시간 계산

	printf("list에서 random 삭제 시간 : %lf\n", list_duration3);

	return 0;
}
