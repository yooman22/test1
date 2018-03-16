coedplay@gmail.com

#include <stdio.h>
#include <stdlib.h>

int main() {
	// 연산자....
	int num;
	int min = -1;
	int max = 2;
	// 최소 6자리의 임의 정수를 출력


	num = rand()%(max-min+1)+min;
	printf("%d \n", num);

	num = rand() % (max - min + 1) + min;
	printf("%d \n", num);

	// 0 ~ 32767
	num = rand();// 임의의 정수를 반환
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