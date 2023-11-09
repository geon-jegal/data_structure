#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#ifndef heap_h
#define heap_h

struct Heap {
	int* array;
	int count; // �� ���� �׸� ����
	int capacity; // ���� �뷮
	int heap_type; //���� ����
};

Heap* CreateHeap(int capacity, int heap_type) {
	Heap* h = (Heap*)malloc(sizeof(Heap));
	if (h == NULL) {
		printf("Memory Error");
	}
	h->heap_type = heap_type;
	h->count = 0;
	h->capacity = capacity;
	h->array = (int*)malloc(sizeof(int) * h->capacity);
	if (h->array == NULL) {
		printf("Memory Error");
	}
	return h;
}

int Parent(Heap* h, int i) {
	if (i <= 0 || i >= h->count)
		return -1;
	return (i - 1) / 2;
}

int LeftChild(Heap* h, int i) {
	int left = 2 * i + 1;
	if (left >= h->count)
		return -1;
	return left;
}
int RightChild(Heap* h, int i) {
	int right = 2 * i + 2;
	if (right >= h->count)
		return -1;
	return right;
}

void PercolateUp(struct Heap* h, int i) {
	int p, temp;
	// 1. insert�� ����� �θ��� ã��
	// 2. �θ�� insert ����� �� ��
	// 3. insert ����� ���� ũ�� swap
	// 4. PercolateUp();
	p = Parent(h, i);

	if (p >= 0 && h->array[p] < h->array[i]) {
		// �θ� ����� ���� �� ������ swap
		temp = h->array[i];
		h->array[i] = h->array[p];
		h->array[p] = temp;

		// �θ� ���� �ö󰡼� ��������� PercolateUp ����
		PercolateUp(h, p);
	}
}

void PercolateDown(struct Heap* h, int i) {
	int l, r, max, temp;
	l = LeftChild(h, i);
	r = RightChild(h, i);
	if (l != -1 && h->array[l] > h->array[i]) max = l;
	else max = i;
	if (r != -1 && h->array[r] > h->array[max]) max = r;
	if (max != i) {
		temp = h->array[i];
		h->array[i] = h->array[max];
		h->array[max] = temp;
		PercolateDown(h, max);
	}
}

void insert(Heap* h, int item) {
	// 1. ���� �迭 ���� ���ο� ��Ҹ� �߰��մϴ�.
	if (h->count < h->capacity) {
		h->array[h->count] = item;
		h->count++;
	}
	else {
		// ���� ���� á�� ���, �� ū �뷮���� �޸𸮸� �ٽ� �Ҵ��մϴ�.
		h->capacity *= 2;
		h->array = (int*)realloc(h->array, sizeof(int) * h->capacity);
		if (h->array == NULL) {
			printf("Memory Error");
			return;
		}
		h->array[h->count] = item;
		h->count++;
	}

	// 2. ��Ҹ� ������ ��ġ�� �̵����� ���� ������ �����մϴ�.
	PercolateUp(h, h->count - 1);
}

int DeleteMax(Heap* h) {
	int data;
	if (h->count == 0) return -1;

	data = h->array[0];
	h->array[0] = h->array[h->count - 1]; // �ִ밪�� �� �� ������ ��ü
	h->count--;
	PercolateDown(h, 0); // PercolateDown�� ȣ���Ͽ� ���� ������ ����

	return data;
}


void BuildHeap(Heap* h, int A[], int n) {
	for (int i = 0; i < n; i++) h->array[i] = A[i];

	h->count = n;
	for (int i = (n - 2) / 2; i >= 0; i--)
		PercolateDown(h, i);
}

Heap* HeapSort(int A[], int n) {
	Heap* h = CreateHeap(n, 1);
	int old_size, i, temp;
	BuildHeap(h, A, n);

	old_size = h->count;
	for (i = n - 1; i > 0; i--) {
		temp = h->array[0];
		h->array[0] = h->array[h->count - 1];
		h->array[h->count - 1] = temp;
		h->count--;
		PercolateDown(h, 0);
	}

	h->count = old_size;
	return h;
}

#endif