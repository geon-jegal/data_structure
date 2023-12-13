#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef QuickSort_H
#define QuickSort_H

// �� ������ ��ġ�� �ٲٴ� �Լ�
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// �� ������ ���� ��Ƽ�� �Լ�
int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // ����, �߰�, ������ �� �߿��� 2��°�� ū ���� ã�� �Ǻ����� ����
    int pivotIndex;
    if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low]))
        pivotIndex = mid;
    else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid]))
        pivotIndex = low;
    else
        pivotIndex = high;

    // �Ǻ��� �迭�� ������ ���� ��ȯ
    swap(&arr[pivotIndex], &arr[high]);

    // �Ǻ�(���� 'high'�� ��ġ)�� ����Ͽ� ��Ƽ�� ����
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}


// �� ���� �Լ�
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void Linear_q() {
    srand(time(NULL));
    int Linear_size = 5000, random;

    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);

        // ������ ����
        for (int i = 0; i < Linear_size; i++) {
            random = rand() % 50000;
            // ����
            Linear[i] = random;
        }

        // ���� �ð� ����
        clock_t sort_start = clock();
        quickSort(Linear, 0, Linear_size - 1);
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // ���� �ð� ���� (�� ��° ����)
        clock_t sort_start2 = clock();
        quickSort(Linear, 0, Linear_size - 1);
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // ��� ���
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);

        Linear_size += 10000;
    }
}

#endif