/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int arry[3][3] = { { 1, 2, 3 }, {4, 5, 6}, {7, 8, 9} }; // ���ο����� ���ϰ�, ���ο����� ���Ѱ��� �ٽ� �� ��ġ��
	int sum[9] = {};

	for (int i = 0; i <= 2; i++) { // ���ο����� ���� ��,  ���� for �� �̿�
		sum[0] += arry[i][0];
		sum[1] += arry[i][1];
		sum[2] += arry[i][2];
	}

	for (int j = 0; j <= 2; j++) { // ���ο����� ���� ��
		sum[3] += arry[0][j];
		sum[4] += arry[1][j];
		sum[5] += arry[2][j];
	}

	for (int i = 0; i <= 2; i++) {
		for (int t = 0; t <= 2; t++) {
			sum[6] += arry[i][t];
		}
	}

	for (int i = 0; i < 6; i++) {
		printf(" % d\n", sum[i]);
	}
	printf(" % d\n", sum[6]);


	return 0;
}*/
