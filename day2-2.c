#pragma warning(disable:4996)
#include <stdio.h>

int main_5() {
	// 문자를 정수로 변환
	int num;// 숫자들...

	// 배열 : atoi itoa
	scanf("%d ", /*저장할 변수의 주소*/&num);
	scanf("%d ", /*저장할 변수의 주소*/&num);
	scanf("%d ", /*저장할 변수의 주소*/&num);
	printf("num is %d \n", num);
	//num = getc(stdin);
	//num = getc(stdin);
	//printf("num is %d \n", num - '0');
	//num = getc(stdin);
	//printf("num is %d \n", num - '0');

	return 0;
}

int main_4() {
	// 입력 키보드에서
	char in;
	// 입력 받을때 버퍼를 비워주세요
	in = getc(stdin);
	rewind(stdin);
	in = getc(stdin);
	rewind(stdin);
	in = getc(stdin);
	rewind(stdin);
	in = getc(stdin);

	printf("%c \n", in);
	return 0;
}