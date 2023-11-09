#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time()�Լ� ���� ���̺귯��
#include "heap.h"


void PercolateUp(int a[], int i) {
    int p, temp;
    // 1. insert�� ����� �θ��� ã��
    // 2. �θ�� insert ����� �� ��
    // 3. insert ����� ���� ũ�� swap
    // 4. PercolateUp();
    p = (i - 1) / 2;

    if (p >= 0 && a[p] < a[i]) {
        // �θ� ����� ���� �� ������ swap
        temp = a[i];
        a[i] = a[p];
        a[p] = temp;

        // �θ� ���� �ö󰡼� ��������� PercolateUp ����
        PercolateUp(a, p);
    }
}

// ���� �Լ����� ������ �ڵ带 �����ϰ� ����ϴ� �����Դϴ�.
int main() {

    int n, max, item;

    Heap* h = CreateHeap(7, 1);
    insert(h, 10);
    insert(h, 96);
    insert(h, 45);
    insert(h, 19);
    insert(h, 11);

    printf("heap: ");
    for (int i = 0; i < h->count; i++) {
        printf("%d  ", h->array[i]);
    }

    printf("\n");
    for (int i = 0; i < 5; i++) {
        max = DeleteMax(h);
        printf("MaxNumber : [%d]\n", max);
    }

    //int a[] = {7, 10, 5, 20, 15, 30};
    srand(time(NULL)); // �Ź� �ٸ� �õ尪 ����
    int a[11] = {}, b[11] = {};
    printf("\n���� ��\n");
    for (int i = 0; i < 11; i++) {
        a[i] = rand() % 100;
        b[i] = a[i];
        printf("%d  ", a[i]);
    }
    printf("\n���� ��(heap����ü ��� x)\n");
    for (n = 10; n >= 0; n--) PercolateUp(a, n);
    for (int i = 0; i < 11; i++) printf("%d  ", a[i]);

    Heap* myheap = CreateHeap(11, 1);

    BuildHeap(myheap, b, 11);
    printf("\n���� ��(heap����ü ��� o)\n");
    for (int i = 0; i < myheap->count; i++) printf("%d  ", myheap->array[i]);

    return 0;
}
