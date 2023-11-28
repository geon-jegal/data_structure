#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#ifndef HASH_H
#define HASH_H

#define MAX_SIZE 50

typedef struct Hash {
	int bucket;
	int slot;
	int** array;
}Hash;

int overflow = 0;

Hash* creatHash(int b, int s);
void insert(Hash* h, int key);
void search(Hash* h, int key);
void Delete(Hash* h, int key);
void print(Hash* h);

Hash* creatHash(int b, int s) {
	Hash* h = (Hash*)malloc(sizeof(Hash));
	if (h == NULL) {
		printf("Memory Error");
		//exit;
	}
	h->bucket = b;
	h->slot = s;
	// 이차원 배열을 동적으로 할당하고 초기화
	h->array = (int**)malloc(sizeof(int*) * h->bucket);
	for (int i = 0; i < h->bucket; i++) {
		h->array[i] = (int*)malloc(sizeof(int) * h->slot);
		h->array[i][0] = NULL;
		h->array[i][1] = NULL;
	}

	return h;
}

// 해시 함수
int hashFunction(int key, int b) {
	return key % b; // b = bucket
}

void insert(Hash* h, int key) {
	int index = hashFunction(key, h->bucket);
	int collision = 0;

	// 충돌이 발생한 경우 선형 탐사 수행
	int i = 0;
	while (i < h->slot) {
		if (h->array[index][i] == NULL) {
			h->array[index][i] = key;
			return;
		}
		i++;
	}

	// 슬롯이 가득 찼을 경우 overflow 처리
	printf("Overflow. Cannot insert %d.\n", key);
	overflow = 1;
}

void search(Hash* h, int key) {
	int index = hashFunction(key, h->bucket);

	// 슬롯을 순회하면서 키 검색
	for (int i = 0; i < h->slot; i++) {
		if (h->array[index][i] == key) {
			printf("Key %d found at index [%d][%d].\n", key, index, i);
			return;
		}
	}

	// 키를 찾지 못한 경우
	printf("Key %d not found in the hash table.\n", key);
}

void Delete(Hash* h, int key) {
	int index = hashFunction(key, h->bucket);

	// 슬롯을 순회하면서 키 검색 및 삭제
	for (int i = 0; i < h->slot; i++) {
		if (h->array[index][i] == key) {
			h->array[index][i] = NULL; // 키를 삭제하고 슬롯을 비움
			printf("Key %d deleted from the hash table.\n", key);
			return;
		}
	}
	print(h);

	// 키를 찾지 못한 경우
	printf("Key %d not found in the hash table. Cannot delete.\n", key);
}

void print(Hash* h) {
	printf("Hash Table:\n=========================\n");
	for (int i = 0; i < h->bucket; i++) {
		printf("[%d] -> ", i);
		for (int j = 0; j < h->slot; j++) {
			if (h->array[i][j] == NULL) {
				printf("0	");
			}
			else {
				printf("%d	", h->array[i][j]);
			}
		}
		printf("\n");
	}
	printf("=========================\n");
}

#endif