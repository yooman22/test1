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

int appendData(DATA list[], DATA arg) {
	static int length = 0;
	list[length] = arg;
	++length;
	return length;
}
int viewList(DATA *list, int length) {// 저장된 개수
	int i;
	for (i = 0; i < length; ++i) {
		printf("[%2d]: ", i);
		putData( list[i] );
	}
	return i;
}
DATA selectOne(DATA list[], int length, int key) {
	// 검색하기 : 있다, 없다..... 있을때 하나, 여러 개
	DATA temp = { 0 };
	int i;
	for (i = 0; i < length; ++i) {
		if (list[i].value == key) {
			temp = list[i];
			break;
		}
	}
	return temp;
	// 반환하는 변수의 값이 0이라면 없음.....
}
int select(DATA list[], int length, DATA *dest, int key) {
	// 검색하기 : 있다, 없다..... 있을때 여러 개
	int i, k = 0;
	for (i = 0; i < length; ++i) {
		if (list[i].value == key) {
			dest[k] = list[i];
			++k;
		}
	}
	return k;
	// 반환하는 변수의 값이 0이라면 없음.....
}

int main() {
	DATA list[10] = { 0 };
	DATA result[10] = { 0 };
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

	return 0;
}

int main_dynamic_array() {
	// 정수 입력한 만큼 모두 저장한다...
	int *list = NULL;// 배열 없다...
	int i=0,k;
	int value;
	while( scanf("%d", &value) ){
		list = (int*)realloc(list, sizeof(int)*(i+1));
		list[i] = value;
		++i;
	}
	printf("\n입력종료\n");
	for (k = 0; k < i ; ++k) {
		printf("%d-%d \n", k, list[k]);
	}

	return 0;
}

int main_1() {
	// 동적할당.... 실행 중에 메모리를 확보
	int *ptr;

	// 크기 4바이트 공간 1개를 생성한다...
	ptr = malloc(10*sizeof(int));
	ptr = calloc(1,sizeof(int));// 배열
	ptr = NULL;
	ptr = realloc(ptr, sizeof(int)*(10+3));// 전체 크기 
	if (ptr == NULL) {
		printf("failed malloc \n");
	}
	else {
		printf("%d %d\n", &ptr, ptr);
	}
	free(ptr);// 해제 없앤다...
	ptr = NULL;
	return 0;
}
