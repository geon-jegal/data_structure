#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

void Unsorted_Linear() {
    srand(time(NULL));
    // Linear Insert and Search
    int Linear_size = 1000, random, i = 0;
    printf("Unsorted Linear Search\n");
    int Linear[1000] = {};

    // insert
    while (i < Linear_size) {
        random = rand() % 2000;
        bool duplicate = false;

        // Check for duplicates
        for (int j = 0; j < i; j++) {
            if (Linear[j] == random) {
                duplicate = true;
                break;
            }
        }

        // Ensure that the random number is not divisible by 2
        if (!duplicate && (random % 2 != 0)) {
            Linear[i] = random;
            i++;
        }
    }
    //printf("\n%d\n", sizeof(Linear) / sizeof(int));

    // search
    int sum = 0;
    for (int j = 0; j < 10000; j++) {
        bool found = false;
        int searchNum = rand() % 2000;

        // Search for the value
        for (int i = 0; i < Linear_size; i++) {
            if (Linear[i] == searchNum) {
                //printf("%d: searchNum = %d\n", i, Linear[i]);
                found = true;
                sum += i;
                break;
            }
        }

        if (!found) {
            //printf("no data\n");
            sum += 1000;
        }
    }
    printf("avg search = %d\n", (sum / 10000));
}

void sorted_Linear() {
    srand(time(NULL));
    // Linear Insert and Search
    int Linear_size = 1000, random, i = 0;
    printf("\nsorted Linear Search\n");
    int Linear[1000] = {};

    // insert
    while (i < Linear_size) {
        random = rand() % 2000;
        bool duplicate = false;

        // Check for duplicates
        for (int j = 0; j < i; j++) {
            if (Linear[j] == random) {
                //printf("%d: searchNum = %d\n", i, Linear[i]);
                duplicate = true;
                break;
            }
        }

        // Ensure that the random number is not divisible by 2
        if (!duplicate && (random % 2 != 0)) {
            Linear[i] = random;
            i++;
        }
    }

    //printf("\n%d\n", sizeof(Linear) / sizeof(int));

    // sort
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

    // search 시간
    int sum = 0;
    for (int j = 0; j < 10000; j++) {
        int searchNum = rand() % 2000;

        // Search for the value
        for (int i = 0; i < Linear_size; i++) {
            if (Linear[i] >= searchNum) {
                //printf("%d: searchNum = %d\n", i, Linear[i]);
                sum += i;
                break;
            }
        }
        /*
        if (!found) {
            //printf("no data\n");
            sum += 1000;
        }
        */
    }
    printf("avg search = %d\n", (sum / 10000));
}

void sorted_Linear_b() {
    srand(time(NULL));
    // Linear Insert and Search
    int Linear_size = 1000, random, i = 0;
    printf("\nsorted Linear Binary Search\n");
    int Linear[1000] = {};

    // insert
    while (i < Linear_size) {
        random = rand() % 2000;
        bool duplicate = false;

        // Check for duplicates
        for (int j = 0; j < i; j++) {
            if (Linear[j] == random) {
                duplicate = true;
                break;
            }
        }

        // Ensure that the random number is not divisible by 2
        if (!duplicate && (random % 2 != 0)) {
            Linear[i] = random;
            i++;
        }
    }

    //printf("\n%d\n", sizeof(Linear) / sizeof(int));

    // sort
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

    // search 시간 (binary search)
    int sum = 0;
    for (int j = 0; j < 10000; j++) {
        bool found = false;
        int searchNum = rand() % 2000;

        int low = 0, high = Linear_size - 1;

        // Binary search
        int count = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            count++;

            if (Linear[mid] == searchNum) {
                //printf("%d: searchNum = %d\n", mid, Linear[mid]);
                found = true;
                sum += count;
                break;
            }
            else if (Linear[mid] < searchNum) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (!found) {
            //printf("no data\n");
            sum += 10;
        }
    }
    printf("avg search = %d\n", (sum / 10000));
}

int main(void) {

    Unsorted_Linear();

    sorted_Linear();

    sorted_Linear_b();

    return 0;
}