#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int* px, int* py) {
	int tmp;
	tmp = *px; // px�� ����Ű�� ���� ���� tmp�� �־��
	*px = *py; // py�� ����Ű�� ���� ���� px�� ����Ű�� ���� �־��
	*py = tmp; // tmp���� py�� ����Ű�� ���� �־��

	// int *p : �ּҸ� �����ϴ� ������ ���� ����
	// p : �ּҰ�
	// *p : �����Ͱ� ����Ű�� ��
	// &x : �ּ� ����
}

/*
int main(void) {
	int a = 1, b = 2;
	printf("swap�� ȣ���ϱ� �� : a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap�� ȣ���� ���� : a=%d, b=%d\n", a, b);
	return 0;
}
*/