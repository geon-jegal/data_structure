#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"
#include "AVL.h"
#include "heap.h"
#include "Graph.h"
#include "Hash.h"

int main() {
	return 0;
}

/*
* void Linear() {
	srand(time(NULL));
	//Linear Insert and Search
	int Linear_size = 500000, random;
	printf("Linear Insert and Search(100번 반복) : \n");
	printf("		    [Insert]	   [Search]\n");
	while (Linear_size <= 10000000) {
		int* Linear = (int*)malloc(sizeof(int) * Linear_size);
		// insert 시작
		clock_t insert_start = clock();
		for (int i = 0; i < Linear_size; i++) {
			random = (rand() * rand()) % Linear_size;
			// insert
			Linear[i] = random;
		}
		// insert 종료
		clock_t insert_end = clock();
		// insert 시간
		double insert = (double)(insert_end - insert_start) / CLOCKS_PER_SEC;

		// search 시간
		double t = 0;
		for (int i = 0; i < 100; i++) {
			int searchNum = rand() * rand() % Linear_size;
			clock_t search_start = clock();
			for (int i = 0; i < Linear_size; i++) {
				if (Linear[i] == searchNum) {
					clock_t search_end = clock();
					t += (double)(search_end - search_start) / CLOCKS_PER_SEC;
					break;
				}
			}
			clock_t search_end = clock();
			t += (double)(search_end - search_start) / CLOCKS_PER_SEC;
		}
		// search 시간 평균
		double search = t / 100;

		// 출력
		printf("%8d\t%11lf\t%11lf\n", Linear_size, insert, search);

		free(Linear);

		Linear_size += 500000;
	}
}

void BST() {
	srand(time(NULL));
	//BST Insert and Search
	int BST_size = 500000, random;
	printf("BST Insert and Search(100000번 반복) : \n");
	printf("		    [Insert]	   [Search]\n");
	random = (rand() * rand()) % BST_size;
	BSTNode* root = NewNode(random);
	while (BST_size <= 10000000) {
		// insert 시작
		clock_t insert_start = clock();
		for (int i = 1; i < BST_size; i++) {
			random = (rand() * rand()) % BST_size;
			// insert
			root = insert_node(root, random);
		}
		// insert 종료
		clock_t insert_end = clock();
		// insert 시간
		double insert = (double)(insert_end - insert_start) / CLOCKS_PER_SEC;

		BSTNode* node;

		// search 시간
		double t = 0;
		for (int i = 0; i < 100000; i++) {
			// search 시작
			clock_t search_start = clock();

			int searchNum = rand() * rand() % BST_size;

			node = search(root, searchNum);
			// search 완료
			clock_t search_end = clock();
			t += (double)(search_end - search_start) / CLOCKS_PER_SEC;
		}

		// search 시간 평균
		double search = t / 100000;

		// 출력
		printf("%8d\t%12.8lf\t%12.8lf\n", BST_size, insert, search);

		//free
		DeleteTree(root);
		root = NULL;

		BST_size += 500000;
	}
}


void AVL() {
	srand(time(NULL));
	//AVL Insert and Search
	int AVL_size = 500000, random;
	printf("AVL Insert and Search(100000번 반복) : \n");
	printf("	   	    [Insert]	   [Search]\n");
	random = (rand() * rand()) % AVL_size;
	AVLTreeNode* root = newNode(random);
	while (AVL_size <= 10000000) {
		// insert 시작
		clock_t insert_start = clock();
		for (int i = 1; i < AVL_size; i++) {
			random = (rand() * rand()) % AVL_size;
			// insert
			root = insert_node(root, random);
		}
		// insert 종료
		clock_t insert_end = clock();
		// insert 시간
		double insert = (double)(insert_end - insert_start) / CLOCKS_PER_SEC;

		AVLTreeNode* node;

		// search 시간
		double t = 0;
		for (int i = 0; i < 100000; i++) {
			// search 시작
			clock_t search_start = clock();

			int searchNum = rand() * rand() % AVL_size;

			node = search(root, searchNum);
			// search 완료
			clock_t search_end = clock();
			t += (double)(search_end - search_start) / CLOCKS_PER_SEC;
		}

		// search 시간 평균
		double search = t / 100000;

		// 출력
		printf("%8d\t%12.8lf\t%12.8lf\n", AVL_size, insert, search);

		//free
		DeleteTree(root);
		root = NULL;

		AVL_size += 500000;
	}
}
*/

/*
* void run() {
	int b = 0, s = 0, key = 0;
	char c;

	printf("input a nummber of the bucket and the slot:");
	scanf("%d %d", &b, &s);
	Hash* myHash = creatHash(b, s);

	printf("<Menu>\n");
	printf("i: insert\n");
	printf("s: search\n");
	printf("d: delete\n");
	printf("p: print\n");
	printf("x: exit\n");

	while (true) {
		printf("Input a menu (i, s, d, p, x): ");
		scanf("%c", &c);
		switch (c) {
		case 'i':
			printf("insert data: ");
			scanf("%d", &key);
			insert(myHash, key);
			printf("\n");
			break;
		case 's':
			printf("search data: ");
			scanf("%d", &key);
			search(myHash, key);
			printf("\n");
			break;
		case 'd':
			printf("delete data: ");
			scanf("%d", &key);
			Delete(myHash, key);
			printf("\n");
		case 'p':
			print(myHash);
			printf("\n");
			break;
		case 'x':
			return;
		default:
			continue;
		}
	}
}
*/