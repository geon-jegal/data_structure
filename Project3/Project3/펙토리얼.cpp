#include<stdio.h>
#include<time.h>

int factorial_recur(int n) { // Recursion�Լ�
	if (n <= 1) return(1);
	else return (n * factorial_recur(n - 1));
	int k = 0;
	for (int i = 1; i <= 1000; i++) {
		k++;
	} // �����ڵ�
}

void factorial_iter(int n) {
	clock_t start = clock(); // �Լ��� ���� �ð� ����
	int result = 1, i, k = 0;
	for (i = 1; i <= n; i++) { // ���丮�� ����
		result = result * i;
	}
	for (i = 1; i <= 1000; i++) {
		k++;
	}// �����ڵ�
	clock_t finish = clock(); // �Լ��� ����ð� ����

	double duration = (double)(finish - start) / CLOCKS_PER_SEC; // Iteration�Լ��� �ҿ�ð� ���

	printf("factorial_iter : %d , time : % lf", result, duration);
}

int main() {
	clock_t start = clock(); // Recursion�Լ��� ���� �ð� ����
	int result = factorial_recur(3220); // �Լ� ����
	clock_t finish = clock();// Recursion�Լ��� ���� �ð� ����

	double duration = (double)(finish - start) / CLOCKS_PER_SEC; // Recursion�Լ��� �ҿ�ð� ���

	printf("factorial_recur : %d ,time : % f\n", result, duration); // Recursion�Լ��� ������� �ҿ�ð� ���

	// factorial_iter(3220); // Iteration�Լ�
	
	

	return 0;
}