/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int arry[3][3] = { { 1, 2, 3 }, {4, 5, 6}, {7, 8, 9} }; // 2차원 배열을 생성한다
	int sum[9] = {}; // 각각의 가로열과 세로열을 더한 값들을 저장하기 위한 배열

	for (int t = 0; t <= 2; t++) { // 이중 for 문 이용하여 가로열과 세로열을 각각 더한다
		for (int i = 0; i <= 2; i++) {
			sum[i] += arry[i][t]; // 가로열 계산을 수행
			sum[i + 3] += arry[t][i]; // 세로열 계산을 수행
		}
	}

	for (int i = 0; i <= 2; i++) {
		printf("가로 %d열의 값: %d\n", i + 1, sum[i]); // 가로열 값 출력
	}
	
	printf("\n");

	for (int i = 0; i <= 2; i++) {
		printf("세로 %d열의 값: %d\n", i + 1, sum[i + 3]); // 세로열 값 출력
	}

	for (int i = 0; i <= 2; i++) { // 전체를 더한 것
		for (int t = 0; t <= 2; t++) {
			sum[6] += arry[i][t];
		}
	}

	printf("\n전체의 합: %d\n", sum[6]); // 전체 값 출력

	return 0;
}*/