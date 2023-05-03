#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void swap(int* px, int* py) {
	int tmp;
	tmp = *px; // px가 가르키는 곳의 값을 tmp에 넣어라
	*px = *py; // py가 가르키는 곳의 값을 px가 가르키는 곳에 넣어라
	*py = tmp; // tmp값을 py가 가르키는 곳에 넣어라

	// int *p : 주소를 저장하는 포인터 변수 생성
	// p : 주소값
	// *p : 포인터가 가르키는 값
	// &x : 주소 리턴
}

/*
int main(void) {
	int a = 1, b = 2;
	printf("swap을 호출하기 전 : a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap을 호출한 다음 : a=%d, b=%d\n", a, b);
	return 0;
}
*/