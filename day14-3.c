#include "Simple.h"
int sz[15] = { 10,1,2,23,4,5,6,37,8,9,10,11,12,13,14 };

int print(int idx) {
	// ���ȣ�� ���� ���� ���� �ʼ�
	if ( idx > 14) {
		return 1;
	}
	// ȣ�� ��....
	print(idx + 1);
	// ���� �� ����...
	return 0;
}
// sz ��Ҹ� ��ø���� 2���� ���
int print2(int idx) {
	if ( idx > 14 ) {
		return 0;
	}
	if (idx < 15)	printf("(%d,", sz[idx]);
	if(idx+1 < 15)	printf("%d)\n", sz[idx + 1]);
	print2(idx+2);
	return 0;
}
// sz ��Ҹ� 2���� ����ϱ� : ����, �� ��Ҹ� ������ ���

int minValue(int min, int i) {
	if ( i > 14 ) {
		return min;
	}
	if (min > sz[i])	min = sz[i];
	return minValue(min, i+1);	// ����
}
// ����� ������ �ƴ϶��... �ݺ��� ������
// ��͹�, �ݺ��� ����

int main() {
	int min;
	min  = minValue(sz[0],1);
	printf("min : %d \n", min);

	return 0;
}