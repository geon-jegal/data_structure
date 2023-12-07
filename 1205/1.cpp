#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "mergeSort.h"

// 두 정수의 위치를 바꾸는 함수
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 퀵 정렬을 위한 파티션 함수
int partition(int arr[], int low, int high) {
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

// 퀵 정렬 함수
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 퀵 정렬 함수
void Linear_q() {
    srand(time(NULL));
    int Linear_size = 5000, random;

    printf("Linear Sort(Quick) :   ");
    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);

        // 데이터 삽입
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // 삽입
            Linear[i] = random;
        }

        // 정렬 시간 측정
        clock_t sort_start = clock();
        quickSort(Linear, 0, Linear_size - 1);
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // 정렬 시간 측정 (두 번째 실행)
        clock_t sort_start2 = clock();
        quickSort(Linear, 0, Linear_size - 1);
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // 결과 출력
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);

        Linear_size += 10000;
    }
}

// 힙 정렬을 위한 힙화 함수
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// 힙 정렬 함수
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// 힙 정렬 함수
void Linear_h() {
    srand(time(NULL));
    int Linear_size = 5000, random;

    printf("Linear Sort(Heap) :   ");
    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);

        // 데이터 삽입
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // 삽입
            Linear[i] = random;
        }

        // 정렬 시간 측정
        clock_t sort_start = clock();
        heapSort(Linear, Linear_size);
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // 정렬 시간 측정 (두 번째 실행)
        clock_t sort_start2 = clock();
        heapSort(Linear, Linear_size);
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // 결과 출력
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);

        Linear_size += 10000;
    }
}

// 메인 함수
int main() {
    int i = 0;
    int a[10] = { 14, 12, 5, 1, 17, 7, 20, 30, 19, 88 };

    printf("병합 정렬 전\n");
    while (i <= 9) {
        printf("%d ", a[i]);
        i++;
    }
    printf("\n병합 졍렬 시작\n");
    mergeSort_i(a, 0, 9);
    //Linear_m();  // 병합 정렬
    //printf("\n");

    return 0;
}