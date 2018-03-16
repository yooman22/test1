#include "Simple.h"
int sz[15] = { 10,1,2,23,4,5,6,37,8,9,10,11,12,13,14 };

int print(int idx) {
	// 재귀호출 전에 종료 조건 필수
	if ( idx > 14) {
		return 1;
	}
	// 호출 전....
	print(idx + 1);
	// 리턴 후 실행...
	return 0;
}
// sz 요소를 중첩없이 2개씩 출력
int print2(int idx) {
	if ( idx > 14 ) {
		return 0;
	}
	if (idx < 15)	printf("(%d,", sz[idx]);
	if(idx+1 < 15)	printf("%d)\n", sz[idx + 1]);
	print2(idx+2);
	return 0;
}
// sz 요소를 2개식 출력하기 : 시작, 끝 요소만 쌍으로 출력

int minValue(int min, int i) {
	if ( i > 14 ) {
		return min;
	}
	if (min > sz[i])	min = sz[i];
	return minValue(min, i+1);	// 계주
}
// 경로의 문제가 아니라면... 반복법 쓰세요
// 재귀법, 반복법 택일

int main() {
	int min;
	min  = minValue(sz[0],1);
	printf("min : %d \n", min);

	return 0;
}