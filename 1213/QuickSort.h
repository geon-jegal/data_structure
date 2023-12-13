#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#ifndef QuickSort_H
#define QuickSort_H

// 두 정수의 위치를 바꾸는 함수
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 퀵 정렬을 위한 파티션 함수
int partition(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    // 왼쪽, 중간, 오른쪽 값 중에서 2번째로 큰 값을 찾아 피봇으로 선택
    int pivotIndex;
    if ((arr[low] <= arr[mid] && arr[mid] <= arr[high]) || (arr[high] <= arr[mid] && arr[mid] <= arr[low]))
        pivotIndex = mid;
    else if ((arr[mid] <= arr[low] && arr[low] <= arr[high]) || (arr[high] <= arr[low] && arr[low] <= arr[mid]))
        pivotIndex = low;
    else
        pivotIndex = high;

    // 피봇을 배열의 마지막 값과 교환
    swap(&arr[pivotIndex], &arr[high]);

    // 피봇(이제 'high'에 위치)을 사용하여 파티션 진행
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

void Linear_q() {
    srand(time(NULL));
    int Linear_size = 5000, random;

    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);

        // 데이터 삽입
        for (int i = 0; i < Linear_size; i++) {
            random = rand() % 50000;
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

#endif