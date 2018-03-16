#include "Simple.h"
// 함수를 전달한다... 함수의 주소를 전달한다... 함수명
// 포인터변수가 함수를 가리킨다....
int compareNumber(const void *a, const void *b) {
	const int *ia = (const int*)a;
	const int *ib = (const int*)b;
	return (*ia)-(*ib);
}
int compareString(const void *a, const void *b) {
	const char *ia = (const char*)a;
	const char *ib = (const char*)b;
	return strcmp(ia,ib);
}
//반환형 (*포인터변수명)(매개변수들(타입만))
int sort(int psz[], int(*pf)(const void *, const void *)) {
	return pf(psz+1, psz+2);
}
//////////////////////////

int main() {

	return 0;
}
