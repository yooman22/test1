#include "Simple.h"
// �Լ��� �����Ѵ�... �Լ��� �ּҸ� �����Ѵ�... �Լ���
// �����ͺ����� �Լ��� ����Ų��....
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
//��ȯ�� (*�����ͺ�����)(�Ű�������(Ÿ�Ը�))
int sort(int psz[], int(*pf)(const void *, const void *)) {
	return pf(psz+1, psz+2);
}
//////////////////////////

int main() {

	return 0;
}
