/* pointer */
#include "Simple.h"

struct _data {
	int value;
	char type;
};

int main_96() {
	unsigned int value = 0;
	// 포인터변수로 쪼개기.... 
	// 가리키는 곳의 자료형 x 대상의 크기만큼 처리
	char *byte;
	byte = (char*)&value;
	// 첫 시작하는 위치... 이어지는 나머지 공간
	*byte = 0xAB;
	++byte;// byte = byte  + 1;
	*byte = 0xCD;
	++byte;
	*byte = 0xEF;
	printf("%x \n", value);
	// 포인터변수의 값이 변경되어 있다....
	// 다시 첫 위치 되돌아 간다....

	return 0;
}
// 시스템 프로그래밍 : 메모리 관리, 내부통신(IPC)
int main_95() {
	int value;// 합당, 내가 읽기, 쓰기를 자유롭게 공간 필요
	int *in;
	int *out;
	in = &value;
	out = &value;
	// 저장
	*in = 100;	// 포인터가 가리키는 곳에 - 저장, 읽어오기
	// 꺼내기
	printf("%d \n", *out);

	return 0;
}

int main_94() {
	// const : 값을 변경하지 않을 것이다.......
	// 알려준다... 함수....
	const char *str = "Hello progrmming";
	// 문자열 상수는 미리 전역공간에 저장해둔다
	// 메모리는 영역 구분되어 있어요.... 읽기, 쓰기 
	char *p = (char*)str;
//	str[0] = '1';
	printf("%d, %s \n", str, str);

	return 0;
}

int main_93() {
	int a, b;
	int *pa, *pb;
	// 비교하기....
	a = b = 10;
	if (a == b) {
		printf("a==b\n");
	}
	// 주소, 값을 각각 따로
	pa = &a;
	pb = &b;
	if (pa == pb) {
		printf("pa==pb\n");
	}
	else {
		printf("pa!=pb\n");
	}
	if (*pa == *pb) {
		printf("*pa==*pb\n");
	}
	else {
		printf("*pa!=*pb\n");
	}
	return 0;
}

int main_92() {
	// 포인터 변수의 선언 : 자료형 * 변수명;
	int *pc;	// char형 변수의 주소를 저장하는 포인터변수
	char* cp;	// * 이 있으면 포인터다...

	// + - 주소 연산 : 주소 , 정수 대상의 크기만큼
	pc = 0;	// 0번지는 접근불가...
	printf("%d \n", pc + 1);	// 1번 이동된 주소
	printf("%d \n", pc + 2);	// 2번 이동된 주소
	printf("%d \n", pc + 3);	// 3번 이동된 주소
	printf("%d \n", &pc - &cp); // 거리
	printf("%d %d\n", &pc, &cp); // 거리

	//printf("포인터변수의 주소 : %d \n", &pc);
	//printf("가리키는 주소 : %d \n",  pc);
	//printf("가리키는 주소에(곳에) %d \n", *pc);

	return 0;
}

int main_91() {
	{
		// 변수의 주소
		int num;
		printf("%d \n", &num);	 // num 변수의 주소
		num = 10;	// 변수명 = 값을 저장해라..
		printf("%d \n", num);	// num 변수에 저장된 값
	}

	{
		// 배열 주소
		char ar[80];// 배열의 크기: 80bytes, 요소의 크기: 1byte
		printf("ar : %d \n", ar);	// 배열명 주소이다...
		printf("&ar : %d \n", &ar);	// 배열의 주소이다...
		printf("&ar[0] : %d \n", &ar[0]);	// [0]번의 주소이다...
		// 선언된 주소의 크기
		printf("%d \n", sizeof(ar));
		printf("*ar : %d \n", sizeof(*ar));
		printf("*(&ar) : %d \n", sizeof(*(&ar)));
	}

	{
		// 구조체 주소
		struct _data	temp;
		printf("%d \n", sizeof(temp));
		printf("%d \n", &temp);			// 구조체변수의 주소
		printf("value : %d \n", &temp.value);	// 멤버의 주소
		printf("type : %d \n", &temp.type);	// 멤버의 주소
		printf("%d \n", (&temp)->value);	// 구조체변수의 주소에서 멤버

	}

	return 0;
}
