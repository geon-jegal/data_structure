#pragma once
// heap.h

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

struct Heap {
    struct HuffmanNode** array;
    int count;
    int capacity;
    int heap_type;
};

struct Heap* CreateHeap(int capacity, int heap_type);

int Parent(struct Heap* h, int i);
int LeftChild(struct Heap* h, int i);
int RightChild(struct Heap* h, int i);
void PercolateUp(struct Heap* h, int i);
void PercolateDown(struct Heap* h, int i);
void insert(struct Heap* h, struct HuffmanNode* node);
struct HuffmanNode* DeleteMax(struct Heap* h);

void BuildHeap(struct Heap* h, struct HuffmanNode* A[], int n);
struct Heap* HeapSort(struct HuffmanNode* A[], int n);

void GenerateHuffmanCodes(struct HuffmanNode* root, int arr[], int top, char data[], int codes[][100]);
struct HuffmanNode* BuildHuffmanTree(char data[], int freq[], int size);
