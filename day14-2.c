#include "Simple.h"

int fa() {
	return 0;
}
int fb(int *param, int size) {
	// 주소를 전달받을때는 .. 1개 or 연속된 여러 개
	// 크기를 전달받은 경우 ~개수 계산
	int length = size / sizeof(*param);
	// 개수를 전달받은 경우 ~크기 계산
	// 주로 배열은 ( 배열명, 길이 )
	return 0;
}
int fc(int *param, int start, int end) {
	// 요소번호 시작, 끝
	param[start];
	param[end];
	return 0;
}
int fd(int **p) {
	// 포인터변수의 주소를 전달받는다....
	free(*p);
	*p = malloc(50);
	// 전달받은 포인터변수가 가리키던 기존의 공간을..... 할것인가?
	return 0;
}


// 구조체 : 포인터멤버 : 자신과 같은 자료형 : 자기참조구조체
typedef struct _selfstruct {
	struct _selfstruct *ptr;
	int testValue;
}T;
int main_self_structure() {
	T t1;
	T t2;
	// 자료형이 같은 다른 변수를 가리킨다....
	t1.testValue = 1;
	t1.ptr = &t2;

	t2.testValue = 2;
	t2.ptr = NULL;	// 없다...
	{
		T *temp;
		temp = &t1;// 시작 첫 변수의 주소
		while (temp != NULL) {
			printf("v : %d \n", temp->testValue);
			temp = temp->ptr;	// 다음 데이터로 옮긴다..
		}
	}

	return 0;
}
