coedplay@gmail.com

#include <stdio.h>
#include <stdlib.h>

int main() {
	// ������....
	int num;
	int min = -1;
	int max = 2;
	// �ּ� 6�ڸ��� ���� ������ ���


	num = rand()%(max-min+1)+min;
	printf("%d \n", num);

	num = rand() % (max - min + 1) + min;
	printf("%d \n", num);

	// 0 ~ 32767
	num = rand();// ������ ������ ��ȯ
	printf("%d \n", num % 100);
	num = rand();
	printf("%d \n", num % 100);
	num = rand();
	printf("%d \n", num % 100);

	num = 1 + 2 + 3;

	num = 0;
	num = num + 1;
	num = num + 2;
	num = num + 3;

	num = 0;
	num += 1;
	num += 2;
	num += 3;

	return 0;
}