#define _CRT_SECURE_NO_WARNINGS

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

        Linear_size += 10000;
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

        Linear_size += 10000;
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// �� ����
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// �� ����
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

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// ���� ����
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // ���� �Ҵ�
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));


    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
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

    // ���� �Ҵ� ����
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// ���� �Լ�
int main() {

    return 0;
}
