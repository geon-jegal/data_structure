#include<stdio.h>
#include<time.h>

int factorial_recur(int n) { // Recursion함수
	if (n <= 1) return(1);
	else return (n * factorial_recur(n - 1));
	int k = 0;
	for (int i = 1; i <= 1000; i++) {
		k++;
	} // 더미코드
}

void factorial_iter(int n) {
	clock_t start = clock(); // 함수의 시작 시간 저장
	int result = 1, i, k = 0;
	for (i = 1; i <= n; i++) { // 펙토리얼 실행
		result = result * i;
	}
	for (i = 1; i <= 1000; i++) {
		k++;
	}// 더미코드
	clock_t finish = clock(); // 함수의 종료시간 저장

	double duration = (double)(finish - start) / CLOCKS_PER_SEC; // Iteration함수의 소요시간 계산

	printf("factorial_iter : %d , time : % lf", result, duration);
}

int main() {
	clock_t start = clock(); // Recursion함수의 시작 시간 저장
	int result = factorial_recur(3220); // 함수 실행
	clock_t finish = clock();// Recursion함수의 종료 시간 저장

	double duration = (double)(finish - start) / CLOCKS_PER_SEC; // Recursion함수의 소요시간 계산

	printf("factorial_recur : %d ,time : % f\n", result, duration); // Recursion함수의 결과값과 소요시간 출력

	// factorial_iter(3220); // Iteration함수
	
	

	return 0;
}