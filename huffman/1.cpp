// heap.c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

struct Heap* CreateHeap(int capacity, int heap_type) {
    struct Heap* h = (struct Heap*)malloc(sizeof(struct Heap));
    if (h == NULL) {
        printf("Memory Error");
        return NULL;
    }
    h->heap_type = heap_type;
    h->count = 0;
    h->capacity = capacity;
    h->array = (struct HuffmanNode**)malloc(sizeof(struct HuffmanNode*) * h->capacity);
    if (h->array == NULL) {
        printf("Memory Error");
        free(h);
        return NULL;
    }
    return h;
}

int Parent(struct Heap* h, int i) {
    if (i <= 0 || i >= h->count)
        return -1;
    return (i - 1) / 2;
}

int LeftChild(struct Heap* h, int i) {
    int left = 2 * i + 1;
    if (left >= h->count)
        return -1;
    return left;
}

int RightChild(struct Heap* h, int i) {
    int right = 2 * i + 2;
    if (right >= h->count)
        return -1;
    return right;
}

void PercolateUp(struct Heap* h, int i) {
    int p;
    struct HuffmanNode* temp;
    p = Parent(h, i);

    if (p >= 0 && h->array[p]->freq < h->array[i]->freq) {
        temp = h->array[i];
        h->array[i] = h->array[p];
        h->array[p] = temp;
        PercolateUp(h, p);
    }
}

void PercolateDown(struct Heap* h, int i) {
    int l, r, max;
    struct HuffmanNode* temp;
    l = LeftChild(h, i);
    r = RightChild(h, i);

    if (l != -1 && h->array[l]->freq > h->array[i]->freq)
        max = l;
    else
        max = i;

    if (r != -1 && h->array[r]->freq > h->array[max]->freq)
        max = r;

    if (max != i) {
        temp = h->array[i];
        h->array[i] = h->array[max];
        h->array[max] = temp;
        PercolateDown(h, max);
    }
}

void insert(struct Heap* h, struct HuffmanNode* node) {
    if (h->count < h->capacity) {
        h->array[h->count] = node;
        h->count++;
    }
    else {
        h->capacity *= 2;
        h->array = (struct HuffmanNode**)realloc(h->array, sizeof(struct HuffmanNode*) * h->capacity);
        if (h->array == NULL) {
            printf("Memory Error");
            return;
        }
        h->array[h->count] = node;
        h->count++;
    }

    PercolateUp(h, h->count - 1);
}

struct HuffmanNode* DeleteMax(struct Heap* h) {
    struct HuffmanNode* data;
    if (h->count == 0)
        return NULL;

    data = h->array[0];
    h->count--;
    PercolateDown(h, 0);
    return data;
}

void BuildHeap(struct Heap* h, struct HuffmanNode* A[], int n) {
    for (int i = 0; i < n; i++)
        h->array[i] = A[i];

    h->count = n;
    for (int i = (n - 2) / 2; i >= 0; i--)
        PercolateDown(h, i);
}

struct Heap* HeapSort(struct HuffmanNode* A[], int n) {
    struct Heap* h = CreateHeap(n, 1);
    int old_size, i;
    struct HuffmanNode* temp;
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

void GenerateHuffmanCodes(struct HuffmanNode* root, int arr[], int top, char data[], int codes[][100]) {
    if (root->left) {
        arr[top] = 0;
        GenerateHuffmanCodes(root->left, arr, top + 1, data, codes);
    }

    if (root->right) {
        arr[top] = 1;
        GenerateHuffmanCodes(root->right, arr, top + 1, data, codes);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            codes[root->data][i] = arr[i];
            printf("%d", arr[i]);
        }
        codes[root->data][top] = -1;
        printf("\n");
    }
}

struct HuffmanNode* BuildHuffmanTree(char data[], int freq[], int size) {
    struct Heap* minHeap = CreateHeap(size, 0);

    for (int i = 0; i < size; ++i) {
        struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
        node->data = data[i];
        node->freq = freq[i];
        node->left = NULL;
        node->right = NULL;
        insert(minHeap, node);
    }

    while (minHeap->count > 1) {
        struct HuffmanNode* left = DeleteMax(minHeap);
        struct HuffmanNode* right = DeleteMax(minHeap);

        struct HuffmanNode* newNode = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
        newNode->data = '$';
        newNode->freq = left->freq + right->freq;
        newNode->left = left;
        newNode->right = right;

        insert(minHeap, newNode);
    }

    return DeleteMax(minHeap);
}

int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode* root = BuildHuffmanTree(data, freq, size);

    int arr[100];
    char codes[256][100];

    GenerateHuffmanCodes(root, arr, 0, data, codes);

    return 0;
}
