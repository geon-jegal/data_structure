#pragma once
#include <stdio.h>
#include <stdlib.h>

// �ؽ� ���̺��� �� ��带 ��Ÿ���� ����ü
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// �ؽ� ���̺��� ��Ÿ���� ����ü
typedef struct HashTable {
    int size;
    Node** table;
} HashTable;

// �ؽ� ���̺��� ũ��
#define TABLE_SIZE 10

// �ؽ� �Լ�
int HashFunction(int key, int size) {
    return key % size;
}

// ���ο� ��带 �����ϴ� �Լ�
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

// �ؽ� ���̺��� �ʱ�ȭ�ϴ� �Լ�
HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    if (hashTable == NULL) {
        printf("Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    hashTable->size = TABLE_SIZE;

    // �� ��Ŷ�� NULL�� �ʱ�ȭ
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

// �ؽ� ���̺� ���ο� Ű�� �����ϴ� �Լ�
void insert(HashTable* hashTable, int key) {
    int index = HashFunction(key, hashTable->size);

    // �ش� �ε����� ��尡 ������ ���ο� ��带 �߰�
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = createNode(key);
    }
    else {
        // ���� ����Ʈ�� �� �տ� ���ο� ��带 �߰�
        Node* newNode = createNode(key);
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

// �ؽ� ���̺��� Ư�� Ű�� �˻��ϴ� �Լ�
void search(HashTable* hashTable, int key) {
    int count = 0;
    int index = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[index];

    // ���� ����Ʈ�� ��ȸ�ϸ� Ű �˻�
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

// �ؽ� ���̺��� Ư�� Ű�� �����ϴ� �Լ�
void Delete(HashTable* hashTable, int key) {
    int index = hashFunction(key, hashTable->size);
    Node* current = hashTable->table[index];
    Node* prev = NULL;

    // ���� ����Ʈ�� ��ȸ�ϸ� Ű �˻� �� ����
    while (current != NULL) {
        if (current->key == key) {
            // ������ ��带 ã���� ��
            if (prev == NULL) {
                // �� �� ��带 �����ϴ� ���
                hashTable->table[index] = current->next;
            }
            else {
                // �߰��̳� �� �� ��带 �����ϴ� ���
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

// �ؽ� ���̺��� ����ϴ� �Լ�
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

// �ؽ� ���̺��� �����ϴ� �Լ�
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
    // 0~30���� �ߺ����� �ʴ� ����� ������ hash
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