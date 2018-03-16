#include "Simple.h"

struct _data {
	int value;
};
typedef struct _data	DATA;

DATA getData(void) {
	DATA temp;
	temp.value = rand();
	return temp;	// 변수
}
void putData(DATA arg) {// 복사
	printf("%d \n", arg.value);
}
// 수정할 구조체를 전달, 수정된 구조체를 반환
DATA editData(DATA arg) {
	arg.value = rand();
	return arg;
}

int appendData(DATA *list[], DATA arg) {
	// 포인터변수들이 모두 다른 곳을 가리킨다...
	static int length = 0;
	DATA *ptr;
	ptr = (DATA*)malloc(sizeof(DATA));
	*ptr = arg;	// 복사
	list[length] = ptr;
	++length;
	return length;
}
int viewList(DATA *list[], int length) {// 저장된 개수
	int i;
	for (i = 0; i < length; ++i) {
		if ( list[i] != NULL) {
			printf("[%2d]: ", i);
			putData(*list[i]);
		}
	}
	// 포인터변수가 가리키는 곳이 없으면 처리 불가....
	return i;
}
DATA selectOne(DATA *list[], int length, int key) {
	// 검색하기 : 있다, 없다..... 있을때 하나, 여러 개
	DATA temp = { 0 };
	int i;
	for (i = 0; i < length; ++i) {
		if ( list[i] != NULL && list[i]->value == key) {
			temp = *list[i];// 값의 복사....
			break;
		}
	}
	return temp;
	// 반환하는 변수의 값이 0이라면 없음.....
}
int select(DATA **list, int length, DATA *dest[], int key) {
	// 검색하기 : 있다, 없다..... 있을때 여러 개
	int i, k = 0;
	for (i = 0; i < length; ++i) {
		if (list[i] != NULL && list[i]->value == key) {
			dest[k] = list[i];	// 주소를 복사
			++k;
		}
	}
	return k;
	// 반환하는 변수의 값이 0이라면 없음.....
}

int main() {
	// 포인터변수들 포인터배열
	DATA *list[10] = { 0 };
	DATA *result[10] = { 0 };
	DATA temp;
	temp = getData();	// 구조체변수 안에... 여러 개의 멤버가 있다...
	appendData(list, temp);
	temp = getData();
	appendData(list, temp);
	temp = getData();
	appendData(list, temp);

	viewList(list, 10);
	printf("검색된 개수 : %d \n",
		select(list, 10, result, 41));
	viewList(result, 10);

	temp = selectOne(list, 10, 10);
	if (temp.value == 0) {
		printf("찾을 수 없음\n");
	}
	else {
		printf("검색결과 \n");
		putData(temp);
	}

	// 포인터가 가리키는 변수와 복사한 변수를 구분한다....
	temp = editData(*list[0]);
	// temp 는 수정된 값
	*list[0] = temp;

	return 0;
}
