#pragma once
#include <stdio.h>
#include <stdlib.h>

// 해시 테이블의 각 노드를 나타내는 구조체
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// 해시 테이블을 나타내는 구조체
typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

// 해시 테이블의 크기
#define TABLE_SIZE 10

// 해시 함수
int HashFunction(int key, int size) {
    return key % size;
}

// 새로운 노드를 생성하는 함수
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// 해시 테이블을 초기화하는 함수
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    hashTable->size = TABLE_SIZE;

    // 각 버킷을 NULL로 초기화
    hashTable->table = (Node**)malloc(sizeof(Node*) * hashTable->size);
    if (hashTable->table == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < hashTable->size; i++) {
        hashTable->table[i] = NULL;
    }

    return hashTable;
}

// 해시 테이블에 새로운 키를 삽입하는 함수
void insert(HashTable* hashTable, int key) {
    int index = HashFunction(key, hashTable->size);

    // 해당 인덱스에 노드가 없으면 새로운 노드를 추가
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = createNode(key);
    }
    else {
        // 연결 리스트의 맨 앞에 새로운 노드를 추가
        Node* newNode = createNode(key);
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

// 해시 테이블에서 특정 키를 검색하는 함수
void search(HashTable* hashTable, int key) {
    int count = 0;
    int index = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[index];

    // 연결 리스트를 순회하며 키 검색
    while (current != NULL) {
        count++;
        if (current->key == key) {
            printf("Key %d found in the hash table, count = %d.\n", key, count);
            return;
        }
        current = current->next;
    }

    printf("Key %d not found in the hash table. count = %d.\n", key, count);
}

// 해시 테이블에서 특정 키를 삭제하는 함수
void Delete(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[index];
    Node* prev = NULL;

    // 연결 리스트를 순회하며 키 검색 및 삭제
    while (current != NULL) {
        if (current->key == key) {
            // 삭제할 노드를 찾았을 때
            if (prev == NULL) {
                // 맨 앞 노드를 삭제하는 경우
                hashTable->table[index] = current->next;
            }
            else {
                // 중간이나 맨 뒤 노드를 삭제하는 경우
                prev->next = current->next;
            }

            free(current);
            printf("Key %d deleted from the hash table.\n", key);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Key %d not found in the hash table. Cannot delete.\n", key);
}

// 해시 테이블을 출력하는 함수
void print(HashTable* hashTable) {
    printf("Hash Table:\n");
    for (int i = 0; i < hashTable->size; i++) {
        printf("[%d] -> ", i);
        Node* current = hashTable->table[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// 해시 테이블을 해제하는 함수
void destroyHashTable(HashTable* hashTable) {
    for (int i = 0; i < hashTable->size; i++) {
        Node* current = hashTable->table[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    free(hashTable->table);
    free(hashTable);
}

HashTable* RandomHash() {
    // 0~30까지 중복되지 않는 값들로 구성된 hash
    // bucket = 10, slot = 2
    srand((unsigned int)time(NULL));  // Seed for random number generation
    int bucket = 10;  // You can adjust the number of buckets as needed
    int slot = 2;    // You can adjust the number of slots as needed

    HashTable* h = createHashTable();

    bool r[30] = { false, };

    /*
    for (int i = 0; i < 31; i++) {
        int k = rand() % 31;
        if (r[k]) break;
        r[k] = true;
        //h->array[i][j] = k;  // Generate random values from 0 to 30
        insert(h, k);
    }
    */

    for (int i = 0; i < 30; i++) {
        int k;
        do {
            k = rand() % 30;
        } while (r[k]);

        r[k] = true;
        insert(h, k);
    }

    return h;
}