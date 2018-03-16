#include "Simple.h"
#include <conio.h>	// 키 처리 대부분

int main_kb() {
	int key;
	// 인터럽트 : 이벤트 방식
	while (1) {
		if (kbhit()) {
			key = getch();
			printf("........");
		}
		printf("00000000");
	}



	//key = getch();
	//if (key == 0 || key == 224) {
	//	key = getch();
	//	printf("%d \n", key);
	//}
	//else {
	//	printf("%d \n", key);
	//}


	return 0;
}

int main_switch2() {
	// 사용자가 선택한 번호에 따라서 가격이 다르다...
	int no;
	int price;
	printf("no : ");
	scanf("%d", &no);// scanf_s 
	if (no == 1) {
		price = 600;
	}
	if (no == 2) {
		price = 300;
	}
	switch (no) {
	case 3:
		price = 1000;
		break;
	case 4:
	case 5:
		price = 800;
		break;
	}
	printf("no[%d], price[%d]\n", no, price);
	return 0;
}

int main_switch() {
	// 정수 상수;
	int value;
	value = 40;
	// 이벤터 번호에 따라서, 정수값을 다른 값으로
	switch ( value / 10) {
	case 4:
		printf("4\n");
		break;
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	case 3:
		printf("3\n");
		break;
	case 5:
		printf("5\n");
		break;
	}
	return 0;
}

int main_if() {
	// 제어문
	char ch;
	ch = getc(stdin);
	// 논리 연산자 : 조건식이 여러 개일때 합친다....
	if ( '0'<=ch && ch<='9' ) {	// isdigit()
		printf("숫자\n");
	}
	else  {
		printf("숫자는 아니네요\n");
		if ('A' <= ch && ch <= 'Z') {// upper
			printf("up case\n");
		}
		else if ('a' <= ch && ch <= 'z') {// lower
			printf("low case\n");
		}
		else{
			printf("etc....\n");
		}
	}
	return 0;
}

int main_2() {
	// 도형(특수문자)
	printf("┌┬┬┬○┬┬┬┬┬┬┐\n");
	printf("┌┬┬┬○┬┬┬┬┬┬┐\n");
	printf("┌┬┬┬○┬┬┬┬┬┬┐\n");
	printf("┌┬┬┬○┬┬┬┬┬┬┐\n");

	// 3행, 4열 @ 출력
	printf("0\n");
	printf("1\n");
	printf("2\n");
	printf("30 1 2 3 @\n");

	// 사각형 4 x 4
	printf("0 0 0 0\n");
	printf("0 0 0 0\n");
	printf("0 0 0 0\n");
	printf("0 0 0 0\n");

	return 0;
}

int main_1() {
	int b;
//	(3 < 5) && (b = getchar());
	b = (3 < 5) || (printf("22222"));

	// 조건 연산자, (식) ? 참 : 거짓;
	printf("%s \n", (b==0)?"false":"true" );
	// 중첩 : 안에 
	printf("%s \n", 
		(b == 0) ? "false" :
		(b == 1) ? "true"  : "else" );
	
	// if -else if

	printf("%d \n", !1);
	printf("%d \n", 1 && 0);
	printf("%d \n", 0 && 1);
	printf("%d \n", 1 || 0);
	printf("%d \n", 0 || 1);
	//printf("%d \n", 10 < 3);
	//printf("%d \n", 10 > 3);
	//printf("%d \n", 10 == 3);
	//printf("%d \n", 10 != 3);

	return 0;
}
