#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<malloc.h>

#include<stdio.h>
#include<malloc.h>

typedef struct studentTag {
	int age;		// ���̸� ��Ÿ���� ������
	char name[10];	// ���ڹ迭�� �� �̸�
	int gpa;		// ��� ������ ��Ÿ���� �Ǽ� ��
}studentTag;


int main() {

	int num;
	printf("�л� ���� �Է��Ͻÿ� : ");
	scanf("%d", &num); // �л��� ���� �Է¹޽��ϴ�.

	struct studentTag* p = (studentTag*)malloc(num * sizeof(studentTag)); // �Է¹��� �л��� ����ŭ ���� �޸𸮸� �Ҵ��մϴ�.

	if (p == NULL) { // ���� �޸��� ����ó��
		printf("�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");
		return(1);
	}
		
	for (int i = 0; i < num; i++) { // �� �л��� ������ �Է� �޽��ϴ�.
		printf("�л��� �̸��� �Է��Ͻÿ�:");
		scanf("%s", p[i].name);
		printf("%s�� ���̸� �Է��Ͻÿ�:", p[i].name);
		scanf("%d", &p[i].age);
		printf("%s�� ������ �Է��Ͻÿ�:", p[i].name);
		scanf("%d", &p[i].gpa);

	}
	
	// �� �л��� ���� �հ� ����� ���մϴ�.
	int sum = 0, avg = 0;
	for (int i = 0; i < num; i++) sum += p[i].gpa;
	avg = sum / num;

	printf("\nsum = %d, avg = %d", sum, avg);

	free(p);

	return 0;
}
