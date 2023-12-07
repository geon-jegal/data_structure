#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);

    // �迭 ���
    printf("Merged Array: ");
    printArray(arr + l, r - l + 1);
}

// ���� ���� �Լ�
void mergeSort_s(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort_s(arr, l, m);
        mergeSort_s(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// ���� ���� �Լ� (��ȯ ����)
void mergeSort_i(int arr[], int l, int r) {
    int i = 0;
    int current_size; // ���� �κ� �迭�� ũ��

    // ���� ũ�⸦ 1���� �����Ͽ� �� �辿 ����
    for (current_size = 1; current_size <= r - l; current_size = 2 * current_size) {
        // �κ� �迭�� ��ȸ�ϸ鼭 ���� ����
        for (int left_start = l; left_start < r; left_start += 2 * current_size) {
            // �߰� ���� �� �� ���� ���
            int mid = left_start + current_size - 1;
            int right_end = (left_start + 2 * current_size - 1 < r) ? (left_start + 2 * current_size - 1) : r;

            // �� �κ� �迭 ����
            merge(arr, left_start, mid, right_end);
        }
        while (i <= 9) {
            printf("%d ", arr[i]);
            i++;
        }
        printf("\n");
        i = 0;
    }
}

void Linear_m() {
    srand(time(NULL));
    // ���� ���� (���� ����)
    int Linear_size = 5000, random;
    printf("Linear Sort(Merge) :   ");
    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);
        // ������ ����
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // ����
            Linear[i] = random;
        }

        // ���� �ð� ����
        clock_t sort_start = clock();
        mergeSort_i(Linear, 0, Linear_size - 1);
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // ���� �ð� ���� (�� ��° ����)
        clock_t sort_start2 = clock();
        mergeSort_i(Linear, 0, Linear_size - 1);
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // ��� ���
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);

        Linear_size += 10000;
    }
}