#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Hash.h"
#include "HashList.h"

void run() {
	int b = 0, s = 0;
	word* key = (word*)malloc(sizeof(word));
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
			scanf("%s %s", key->a, key->k);
			insert(myHash, key);
			printf("\n");
			break;
		case 's':
			printf("search data: ");
			scanf("%s", key->a);
			search(myHash, key->a);
			printf("\n");
			break;
		case 'd':
			printf("delete data: ");
			scanf("%s", key);
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


int main() {
	Hash* myHash = creatHash(5, 2);
	word* a = (word*)malloc(sizeof(word));
	a->a = "apple";
	a->k = "»ç°ú";

	insert(myHash, a);
	//insert(myHash, "banana");
	//insert(myHash, "cnady");
	//insert(myHash, "department");
	//insert(myHash, "error");
	//insert(myHash, "fire");
	//insert(myHash, "bus");
	//insert(myHash, "birthday");
	//insert(myHash, "cloth");

	print(myHash);


	search(myHash, "cloth");

	/*
	const char* key = "aa";
	printf("insert data: ");
	scanf("%s", key);
	insert(myHash, key);


	run();
	*/
	return 0;
}