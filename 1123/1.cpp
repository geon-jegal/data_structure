#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

void run() {
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

int main() {

	run();

	return 0;
}