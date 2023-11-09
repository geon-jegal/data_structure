#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time()함수 포함 라이브러리
#include "heap.h"


void PercolateUp(int a[], int i) {
    int p, temp;
    // 1. insert된 노드의 부모노드 찾기
    // 2. 부모와 insert 노드의 값 비교
    // 3. insert 노드의 값이 크면 swap
    // 4. PercolateUp();
    p = (i - 1) / 2;

    if (p >= 0 && a[p] < a[i]) {
        // 부모 노드의 값이 더 작으면 swap
        temp = a[i];
        a[i] = a[p];
        a[p] = temp;

        // 부모 노드로 올라가서 재귀적으로 PercolateUp 수행
        PercolateUp(a, p);
    }
}

// 메인 함수에서 허프만 코드를 생성하고 출력하는 예제입니다.
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
    srand(time(NULL)); // 매번 다른 시드값 생성
    int a[11] = {}, b[11] = {};
    printf("\n정렬 전\n");
    for (int i = 0; i < 11; i++) {
        a[i] = rand() % 100;
        b[i] = a[i];
        printf("%d  ", a[i]);
    }
    printf("\n정렬 후(heap구조체 사용 x)\n");
    for (n = 10; n >= 0; n--) PercolateUp(a, n);
    for (int i = 0; i < 11; i++) printf("%d  ", a[i]);

    Heap* myheap = CreateHeap(11, 1);

    BuildHeap(myheap, b, 11);
    printf("\n정렬 후(heap구조체 사용 o)\n");
    for (int i = 0; i < myheap->count; i++) printf("%d  ", myheap->array[i]);

    return 0;
}
