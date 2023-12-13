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

// ���� ���� �Լ�
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        // ���� �ε����� �ּҰ����� ����
        minIndex = i;

        // �ּҰ��� ã��
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // �ּҰ��� ���� ��ġ�� ��ȯ
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// ���� ���� �Լ�
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // key���� ū ���Ҹ� ã���� �� ���Ҹ� ���������� �̵�
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        // key�� �ùٸ� ��ġ�� ����
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
        //����
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // insert
            Linear[i] = random;
        }

        // sort �ð�
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
        // sort �ð�
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // sort �ð�
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
        // sort �ð�
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // ���
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
        //����
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // insert
            Linear[i] = random;
        }

        // sort �ð�
        clock_t sort_start = clock();
        selectionSort(Linear, Linear_size);
        // sort �ð�
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // sort �ð�
        clock_t sort_start2 = clock();
        selectionSort(Linear, Linear_size);
        // sort �ð�
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // ���
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
        //����
        for (int i = 0; i < Linear_size; i++) {
            random = (rand() * rand()) % 50000;
            // insert
            Linear[i] = random;
        }

        // sort �ð�
        clock_t sort_start = clock();
        insertionSort(Linear, Linear_size);
        // sort �ð�
        clock_t sort_end = clock();
        double sort = (double)(sort_end - sort_start) / CLOCKS_PER_SEC;

        // sort �ð�
        clock_t sort_start2 = clock();
        insertionSort(Linear, Linear_size);
        // sort �ð�
        clock_t sort_end2 = clock();
        double sort2 = (double)(sort_end2 - sort_start2) / CLOCKS_PER_SEC;

        // ���
        printf("\n%11lf, %11lf", sort, sort2);

        free(Linear);
    }
}

// ���� �Լ�
int main() {

    Linear_s();
    printf("\n");

    Linear_b();
    printf("\n");

    Linear_i();


    return 0;
}