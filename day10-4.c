#include "Simple.h"


int main_1011() {
	int value = 100;
	int *p1;
	int *p2;
	int *temp;
	// 저장하는 것이 무엇인가??
	p1 = (int*)malloc(4);
	p2 = (int*)malloc(4);
	*p1 = 10;
	*p2 = 20;

	// 교환하라...
	temp = p1;
	p1 = p2;
	p2 = temp;

	value = *p1;
	*p1 = *p2;
	*p2 = value;

	printf("%d, %d \n", *p1, *p2);

	return 0;
}

int main_1010() {
	// 자료형* 변수명;	포인터변수 : 주소를 저장
	// 자료형 배열[];	일반변수들....
	// 자료형* 배열명[];	포인터변수들.... 주소 여러 개를 저장
	int* list[10];	// 요소들은 포인터변수들....
	int a, b, c;
	list[0] = &a;	// 주소 1000번지를 가리킨다....
	list[1] = &b;
	list[2] = (int*)malloc(sizeof(int));	// 가리키는 곳이 없다....
	// 포인터변수는 반드시 가리킬 다른 변수가 있어야 한다....

	// 주소가 같으면
	list[0] == list[1];	// 데이터는 1개
	list[0] != list[1]; // 데이터가 2개

	// 값(데이터)
	*list[0] == *list[1];
	*list[0] != *list[1];


	return 0;
}


int main(int argc, char *argv[], char **env) {
	// ** -> 포인터배열
	while (*env) {
		printf("%s\n", *env);	// env 가 가리키는 문자열
		++env;
	}

	return 0;
}
