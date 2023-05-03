#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

#include<stdio.h>
#include<malloc.h>

typedef struct studentTag {
	int age;		// 나이를 나타내는 정수값
	char name[10];	// 문자배열로 된 이름
	int gpa;		// 평균 평점을 나타내는 실수 값
}studentTag;


int main() {

	int num;
	printf("학생 수를 입력하시오 : ");
	scanf("%d", &num); // 학생의 수를 입력받습니다.

	struct studentTag* p = (studentTag*)malloc(num * sizeof(studentTag)); // 입력받은 학생의 수만큼 동적 메모리를 할당합니다.

	if (p == NULL) { // 동적 메모리의 예외처리
		printf("메모리가 부족해서 할당할 수 없습니다.\n");
		return(1);
	}
		
	for (int i = 0; i < num; i++) { // 각 학생의 정보를 입력 받습니다.
		printf("학생의 이름을 입력하시오:");
		scanf("%s", p[i].name);
		printf("%s의 나이를 입력하시오:", p[i].name);
		scanf("%d", &p[i].age);
		printf("%s의 성적을 입력하시오:", p[i].name);
		scanf("%d", &p[i].gpa);

	}
	
	// 각 학생의 점수 합과 평균을 구합니다.
	int sum = 0, avg = 0;
	for (int i = 0; i < num; i++) sum += p[i].gpa;
	avg = sum / num;

	printf("\nsum = %d, avg = %d", sum, avg);

	free(p);

	return 0;
}
