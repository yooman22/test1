#include "Simple.h"

struct _tagname {
	// 멤버들의 선언
	char type;
	int value;
	char title[80];
	char *pbuf;	// 가리킬 주소
//	struct _tagname member;	// 순환 오류
};
// 파일입출력 시 메모리 주소를 저장하지 않는다...

typedef struct _tagname	T;
typedef struct _tagname	*PT;

int main_struct_2() {
	T temp = { 0 };
	T *ptr = 1000;
	temp = *ptr;	// 복사 : 구조체변수가 두 개다...
	// ->
	temp.type = 'A';
	temp.value = 100;
	*temp.title = 'C';
	temp.pbuf = temp.title + 40;
	*temp.pbuf = 'D';
	*ptr = temp;
//	fread(&temp, sizeof(temp), 1, fp);
	return 0;
}

int main_struct_base() {
	T *ptr;
	ptr = (T*)calloc(1, sizeof(T));
	ptr[0].type;
	ptr->type;
	(*ptr).title;
	*ptr->title;
	*ptr->pbuf = 'A';
	*(*ptr).pbuf = 'B';	// 멤버가 포인터다....

	{
		PT *p;	// **p
		T temp = { 'A', 100, "Hello", NULL };
		// 멤버의 순서, 자료형에 맞추어 초기값 주기

		temp.title;
		(&temp)->title;
	}

	
	return 0;
}

int main_constpointer() {
	//const int *p = 1000;
	//// 포인터변수가 가리키는 곳을 변경하지 않는다.
	//*p = 10;
	//p = 2000;	// 주소는 수정할 수 있다..

	//int * const cp = 1000;	// 주소를 저장한다...
	//*cp = 20;
	//cp = 3000;	// 주소는 수정할 수 없다...

	//// 형변환을 하지 마세요....
	//*((int*)p) = 20;
	return 0;
}

int main_pointer() {
	{
		int *ptr;	// 포인터변수 ptr. int형 변수의 주소를 저장
		// 주소를 저장한 후에 사용한다...
		int num;
		ptr = &num;	// 주소를 전달받는다...
		printf("%d \n", &ptr);	// ptr 의 주소
		printf("%d \n",  ptr);	// ptr 의 값(int형 주소)
		printf("%d \n", *ptr);	// ptr 이 가리키는 값
	}
	{
		int *ptr;	// 실행 중에 int형 변수를 생성(동적할당)

		// 여기에서 변수가 필요하다...
		ptr = (int*)malloc( sizeof(int) );// 4
		*ptr = 10;// 가리키는 곳에 값을 저장
		printf("%d \n", &ptr);	// ptr 의 주소
		printf("%d \n", ptr);	// ptr 의 값(int형 주소)
		printf("%d \n", *ptr);	// ptr 이 가리키는 값
	}
	{
		int *iptr;
		char *cptr;
		// 주소 연산 . 연속하는 데이터들.... 배열과 같다....
		// 주소 + 1, - 1 ( 주소의 자료형 크기만큼 1번 이동 )
		iptr = 100;
		printf("%d \n", iptr + 1);
		printf("%d \n", iptr + 2);// 자료형 크기
		printf("%d \n", iptr + 3);
		cptr = 100;
		printf("%d \n", cptr + 1);
		printf("%d \n", cptr + 2);// 자료형 크기
		printf("%d \n", *(cptr + 3) );
		printf("%d \n", *cptr + 3);
	}
	{
		int *ptr;
		int **pop = &ptr;// 포인터변수의 주소를 전달한다..

		&pop;	// 주소 : pop의 주소 : int*의 주소를 가리키는 포인터다...
		pop;	// 주소 : int*의 주소
		*pop;	// 주소 : int*의 이름 : int의 주소
		**pop;	// 값 : 정수 : int변수에 저장된 값
	}
	// 주소를 보고 데이터들을 추적한다. ( 탐색한다 )

	return 0;
}