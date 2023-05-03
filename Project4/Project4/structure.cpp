/*
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

typedef struct studentTag {
	int age;		// 나이를 나타내는 정수값
	char name[10];	// 문자배열로 된 이름
	int gpa;		// 평균 평점을 나타내는 실수 값
}studentTag;


int main() {
	studentTag kim = { 21, "김철수", 80};
	studentTag lee = { 20, "이영희", 90};
	studentTag Park = { 24, "박찬호", 95 };

	int sum = 0, avg = 0;
	sum = kim.gpa + lee.gpa + Park.gpa;
	avg = sum / 3;

	printf("sum = %d, avg = %d", sum, avg);

	return 0;
}
*/