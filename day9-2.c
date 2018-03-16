#include "Simple.h"
// 반환과 전달의 결정....
int global;
void getInteger_1(void) {
	global = 10;
}
int getInteger_2(void) {
	// 1 ~ 20
	int v = 0;
	scanf("%d", &v);
	return v;
}
void getInteger_3(int *param) {
	// 저장할 주소를 받아서
	if (param != NULL){
		*param = 30;
	}
}
int *getInteger_4(void) {
	// 주소를 반환하는 함수 : 지역변수의 주소는 반환하면 안된다...
	int value;
	value = 40;
	if( value < 40)
		return &value;
	
	return NULL;
	// 내부(지역변수)의 주소를 반환하면 없어진다...
	// 널인 경우, 널이 아닌 구분해서
}

// 재귀함수: 자신을 호출한다... 반복
int r1() {
	r1();	// 계속 호출 : 무한반복 : 메모리 넘친다...
	return 0;
}
int r2() {
	static int count = 0;
	if (++count == 10) {
		return 0;
	}
	r2();
	return 0;
}
int r3() {
	static int count = 0;
	if (++count == 10) {
		return 0;
	}
	printf("[%p] count %d \n", &count, count);
	r3();
	printf("[%p] count %d \n", &count, count);
	return 0;
}

int r4(int i) {
	if (i == 0) {
		return 1;// 최소 얼마까지
	}
	return i*r4(i-1);
}
// 탐색 : 가급적 반복법 처리한다...
int r5(int arg) {
	if (arg == 0) {
		return 0;
	}
	printf("%d\n", arg);
	r5(arg - 1);
	return 0;
	// 최대 호출가능한 횟수
}

// 문자열을 입력받는다.. 역순으로 출력해라..
int reverse( char *param) {// = buf
	if ( *param == '\0') {
		return 0;
	}
	// 순서대로
	reverse(param+1);
	// 역순
//	reverse(param + 1);
	printf("%c", *param);
	return 0;
}
int main() {
	char buf[80] = { 0 };
	int i, last;
	fgets(buf, 80, stdin);
	// [0]->마지막번호 --
	last = strlen(buf)-1;
	for (i = last; i >= 0; --i) {
		printf("%c", buf[i]);
	}
	printf("\n");

	reverse(buf);// 한 글자 단위로 반복한다....

	return 0;
}

int main_3() {

	int i;
	int value = 0;
	//  반복 십만 
	for (i = 0; i < 100000; ++i) {
		value += i;
	}
	printf("v : %d \n", value);
	// 공간이 계속 생긴다....
	r5(100000);


	return 0;
}

int main_2() {
	int value;
	value = r4( 10 );
	printf(" value %d \n", value);
	return 0;
}

int main_1() {
	int result;
	int *ptr;

	getInteger_1();
	printf("global : %d \n", global);

	result = getInteger_2();
	printf("result : %d \n", result);

	getInteger_3( &result);
	printf("result : %d \n", result);

	ptr = getInteger_4();// 주소를 반환하는 함수는 필히 검사해라....
	if (ptr == NULL) {
		printf("error \n");
	}
	printf("result : %d \n", *ptr);
	printf("result : %d \n", *ptr);

	return 0;
}
