#include "Simple.h"
/* 배열 처리 
	배열 저장, 꺼낸다.
	복사하기(전체,일부)
	추가하기,삽입하기
	삭제하기(연속상태유지,순서)
*/
int main_insert() {
	// 삽입하기 : 벌린다...
	int list[10] = { 1,2,3,4,5 };
	int ins = 3;
	int value = 7;
	int i;
	// ins번 비운다...
	for (i = 9; i > ins;--i) {
		list[i] = list[i-1];
	}
	list[ins] = value;

	return 0;
}
int main_remove() {
	// 삭제하기....
	// 지운다... 공간은 그대로 있다....
	// +1 로 채워서 당긴다...
	int list[10] = {1,2,3,4,5,6,7,8,9,0};
	int i;
	for (i = 0; i < 10; ++i) {
		printf("%d, ", list[i]);
	}
	printf("\n");
	{// 삭제 : 입력된 순서를 상관없다...
		int del = 4;
		int t;
		t = list[del];
		list[del] = list[9];// 마지막요소를 삭제 요소에 덮어쓴다..
		list[9] = t;
	}
	if(0){// 삭제: 입력된 순서를 유지한다....
		int del = 4;
		int k;
		for (k = del; k < 9; ++k) {
			list[k] = list[k + 1];
		}
		list[9] = 0;
	}
	for (i = 0; i < 10; ++i) {
		printf("%d, ", list[i]);
	}
	printf("\n");

	return 0;
}

int main_copy() {
	// 복사하기... 2개 된다...
	int src[20];
	int dest[20];
	int i;
	// 순서 같이
	for (i = 0; i < 20; ++i) {
		dest[i] = src[i];
	}
	// 역순 
	for (i = 0; i < 20; ++i) {
		dest[19-i] = src[i];
	}

	// 일부 3 ~ 10
	for (i = 3; i < 11; ++i) {
		dest[i-3] = src[i];
	}
	// 일부 3 ~ 5개
	for (i = 0; i < 5; ++i) {
		dest[i - 3] = src[3+i];
	}

	return 0;
}

int main_4() {
	// 추가하기...
	int value;
	int list[20];
	int i = 0;// 0번부터...
	while (1) {
		value = rand();
		list[i] = value;
		++i;// 개수, 번호 ?
		if (i == 20) {
//			break;
		}
	}
	printf("Full \n");
	return 0;
}
int main_3() {
	// 추가하기....
	int score[20];
	int seq = 0;
	// 저장한 번호 < 마지막 번호
	// 저장할 번호 < 개수
	score[seq] = 1;
	++seq;
	// 최대 개수를 넘기지 않는다..
	if (seq > 20) {
		printf("넘친다...\n");
	}

	score[seq] = 2;
	++seq;

	score[seq] = 3;
	++seq;
	return 0;
}
int main_2() {
	// 요소 단위 반복 : 번호
	int score[20];
	int max_index = 20-1;// 0
	int i;	// 요소번호 
	int value;// 요소의 값
	// 저장하기
	for (i = 0; i <= max_index;++i) {
		score[i] = rand();
	}
	// 꺼내기
	for (i = 0; i <= max_index; ++i) {
		value = score[i];
		printf("[%d] %d \n", i, value);
	}

	return 0;
}
int main_1() {
	// 요소 자료형 배열명[최대개수]
	char list[10];

	printf("size : %d \n", sizeof(list));
	printf("size : %d \n", sizeof(list[0]));

	printf("address : %d \n", list + 0);
	printf("address : %d \n", list + 1);
	printf("address : %d \n", list + 2);
	printf("address : %d \n", list + 3);
	// 배열 요소들은 연속해서 저장
	return 0;
}