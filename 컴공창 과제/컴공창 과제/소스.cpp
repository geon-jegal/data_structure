#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(int arg, char* argv[]) { // ���� ��ȯ ���α׷� ����
	float input = 0, a;
	int menu = 0;

	printf("------------------------------------������ȯ------------------------------------\n");
	printf("[����]\n");
	printf("	01. inch -> cm				02. cm -> inch\n");
	printf("[�µ�]\n");
	printf("	03. ���� -> ȭ��			04. ȭ�� -> ����\n");
	printf("[����]\n");
	printf("	05. ��������(m^2) -> ��			06. �� -> ��������(m^2)\n");
	printf("[����]\n");
	printf("	07. ų�α׷�(kg) -> �Ŀ��(lb)		08. �Ŀ��(lb) -> ų�α׷�(kg)\n");
	printf("------------------------------------������ȯ------------------------------------\n");

	printf("��ȯ�� case�� �Է��Ͻÿ�: ");
	scanf_s("%d", &menu);

	if (menu >= 1 && menu <= 8) {
		printf("��ȯ�� ���� �Է��Ͻÿ� : ");
		scanf_s("%f", &input);
	}
	else {
		printf("���� case�Դϴ�.\n");
		return 0;
	}

	switch (menu) {
		case 1:
			printf("%.2f inch = %.2f cm\n", input, input * 2.54);
			break;
		case 2:
			printf("%.2f cm = %.2f inch\n", input, input / 2.54);
			break;
		case 3:
			a = (input * 1.8) + 32;
			printf("���� %.2f�� = ȭ�� %.2f�� \n", input, a);
			break;
		case 4:
			a = (input - 32) / 1.8;
			printf("ȭ�� %.2f��= ���� %.2f��\n", input, a);
			break;
		case 5:
			printf("%.2f ��������(m^2) = %.2f ��\n", input, input * 3.3);
			break;
		case 6:
			printf("%.2f �� = %.2f ��������(m^2)\n", input, input / 3.3);
			break;
		case 7:
			printf("%.2f ų�α׷�(kg) = %.2f �Ŀ��(lb)\n", input, input / 0.45);
			break;
		case 8:
			printf("%.2f �Ŀ��(lb) = %.2f ų�α׷�(kg)\n", input, input * 0.45);
			break;
		default:
			break;
	}
	return 0;
}