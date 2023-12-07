#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
* int swapped = 1;
* for (int i = 0; i < Linear_size - 1 && swapped; i++) {
* swapped = 0;
            for (int j = 0; j < Linear_size - i - 1; j++) {
                if (Linear[j] > Linear[j + 1]) {
                    // swap
                    int temp = Linear[j];
                    Linear[j] = Linear[j + 1];
                    Linear[j + 1] = temp;
                    swapped = 1;
                }
            }
        }
*/

// 선택 정렬 함수
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        // 현재 인덱스를 최소값으로 가정
        minIndex = i;

        // 최소값을 찾음
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // 최소값을 현재 위치와 교환
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 삽입 정렬 함수
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // key보다 큰 원소를 찾으면 그 원소를 오른쪽으로 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // key를 올바른 위치에 삽입
        arr[j + 1] = key;
    }
}

void Linear_b() {
    srand(time(NULL));
    //Linear Insert and Search
    int Linear_size = 5000, random;
    printf("Linear Sort(Bubble) :   ");
    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);
        //삽입
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // insert
            Linear[i] = random;
        }

        // sort 시간
        clock_t sort_start = clock();
        for (int i = 0; i < Linear_size - 1; i++) {
            for (int j = 0; j < Linear_size - i - 1; j++) {
                if (Linear[j] > Linear[j + 1]) {
                    // swap
                    int temp = Linear[j];
                    Linear[j] = Linear[j + 1];
                    Linear[j + 1] = temp;
                }
            }
        }
        // sort 시간
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // sort 시간
        clock_t sort_start2 = clock();
        for (int i = 0; i < Linear_size - 1; i++) {
            for (int j = 0; j < Linear_size - i - 1; j++) {
                if (Linear[j] > Linear[j + 1]) {
                    // swap
                    int temp = Linear[j];
                    Linear[j] = Linear[j + 1];
                    Linear[j + 1] = temp;
                }
            }
        }
        // sort 시간
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // 출력
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);
    }
}

void Linear_s() {
    srand(time(NULL));
    //Linear Insert and Search
    int Linear_size = 5000, random;
    printf("Linear Sort(Selection) :    ");
    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);
        //삽입
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // insert
            Linear[i] = random;
        }

        // sort 시간
        clock_t sort_start = clock();
        selectionSort(Linear, Linear_size);
        // sort 시간
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // sort 시간
        clock_t sort_start2 = clock();
        selectionSort(Linear, Linear_size);
        // sort 시간
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // 출력
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);

        Linear_size += 10000;
    }
}

void Linear_i() {
    srand(time(NULL));
    //Linear Insert and Search
    int Linear_size = 5000, random;
    printf("Linear Sort(Insert) :   ");
    while (Linear_size <= 100000) {
        int* Linear = (int*)malloc(sizeof(int) * Linear_size);
        //삽입
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // insert
            Linear[i] = random;
        }

        // sort 시간
        clock_t sort_start = clock();
        insertionSort(Linear, Linear_size);
        // sort 시간
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // sort 시간
        clock_t sort_start2 = clock();
        insertionSort(Linear, Linear_size);
        // sort 시간
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // 출력
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);
    }
}

// 메인 함수
int main() {

    Linear_s();
    printf("\n");

    Linear_b();
    printf("\n");

    Linear_i();


    return 0;
}