/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main() {
	int arry[3][3] = { { 1, 2, 3 }, {4, 5, 6}, {7, 8, 9} }; // 2���� �迭�� �����Ѵ�
	int sum[9] = {}; // ������ ���ο��� ���ο��� ���� ������ �����ϱ� ���� �迭

	for (int t = 0; t <= 2; t++) { // ���� for �� �̿��Ͽ� ���ο��� ���ο��� ���� ���Ѵ�
		for (int i = 0; i <= 2; i++) {
			sum[i] += arry[i][t]; // ���ο� ����� ����
			sum[i + 3] += arry[t][i]; // ���ο� ����� ����
		}
	}

	for (int i = 0; i <= 2; i++) {
		printf("���� %d���� ��: %d\n", i + 1, sum[i]); // ���ο� �� ���
	}
	
	printf("\n");

	for (int i = 0; i <= 2; i++) {
		printf("���� %d���� ��: %d\n", i + 1, sum[i + 3]); // ���ο� �� ���
	}

	for (int i = 0; i <= 2; i++) { // ��ü�� ���� ��
		for (int t = 0; t <= 2; t++) {
			sum[6] += arry[i][t];
		}
	}

	printf("\n��ü�� ��: %d\n", sum[6]); // ��ü �� ���

	return 0;
}*/