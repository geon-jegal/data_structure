#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(int arg, char* argv[]) { // 단위 변환 프로그램 제작
	float input = 0, a;
	int menu = 0;

	printf("------------------------------------단위변환------------------------------------\n");
	printf("[길이]\n");
	printf("	01. inch -> cm				02. cm -> inch\n");
	printf("[온도]\n");
	printf("	03. 섭씨 -> 화씨			04. 화씨 -> 섭씨\n");
	printf("[넓이]\n");
	printf("	05. 제곱미터(m^2) -> 평			06. 평 -> 제곱미터(m^2)\n");
	printf("[무게]\n");
	printf("	07. 킬로그램(kg) -> 파운드(lb)		08. 파운드(lb) -> 킬로그램(kg)\n");
	printf("------------------------------------단위변환------------------------------------\n");

	printf("변환할 case를 입력하시오: ");
	scanf_s("%d", &menu);

	if (menu >= 1 && menu <= 8) {
		printf("변환할 값을 입력하시요 : ");
		scanf_s("%f", &input);
	}
	else {
		printf("없는 case입니다.\n");
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
			printf("섭씨 %.2f도 = 화씨 %.2f도 \n", input, a);
			break;
		case 4:
			a = (input - 32) / 1.8;
			printf("화씨 %.2f도= 섭씨 %.2f도\n", input, a);
			break;
		case 5:
			printf("%.2f 제곱미터(m^2) = %.2f 평\n", input, input * 3.3);
			break;
		case 6:
			printf("%.2f 평 = %.2f 제곱미터(m^2)\n", input, input / 3.3);
			break;
		case 7:
			printf("%.2f 킬로그램(kg) = %.2f 파운드(lb)\n", input, input / 0.45);
			break;
		case 8:
			printf("%.2f 파운드(lb) = %.2f 킬로그램(kg)\n", input, input * 0.45);
			break;
		default:
			break;
	}
	return 0;
}