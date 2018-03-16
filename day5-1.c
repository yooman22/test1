
#include "Simple.h"

int main() {

	return 0;
}

int main_baseball() {
	// 3자리의 임의 정수 10개를 출력하세요
	int num;
	int ran;// 0 ~ 9
	int i, k;
	int flag;	// 0번 9번 비트만
	int digits = 12;// 자리 수를 변경

	for (i = 0; i < 10; ++i) {
		num = rand()%9+1;
		flag = 0;
		flag = flag | (1 << num);// 표시한다.
		for (k = 1; k < digits; ++k) {
			do {
				ran = rand() % 10;
			} while (flag & (1 << ran));// 사용했으면
			num = num * 10 + ran;	// 사용했다.
			flag = flag | (1 << ran);// 표시한다.
		}
		printf("num is : %d \n", num);
	}

	return 0;
}

int main_bb_1() {
	// 중복 제거 : 새로 생성 : 사용여부 표시해서
	//			: 검사 : 모두 비교해서 같은 값 확인
	// 16비트 짜리 변수를 만든다....
	short flag;
	int r;
	// 모든 비트를 0 으로 만든다....
	flag = 0;
	// 0부터 9사이 임의 수를 저장한다....
	do{
		r = rand() % 10;
		// 임의 수를 확인, r 번 비트의 값이 1인지 확인
	}while(flag & (1 << r));
	// 1이면 다시 임의 수를 저장한다...
	// 0이면 1로 만든 후 처리한다...
	flag = flag | (1 << r);

	return 0;
}

int main_checkin() {
	// 임의 비트의 값을 1로 만든다...
	{
		int n = 0;

		//[4]번 비트를 1로 만든다...
		n = n | (1<<4);// 나머지는 그대로 두고....
		n = n | (1 << 3);// 나머지는 그대로 두고....
		printf("%x \n", n);

	}
	// 임의 비트의 값이 1인지 확인 : 0이 아니다....
	{
		int n = 4;	// 0100

		if ( n & (1<<3) ) {// 0이면 거짓
			printf("1이다...");
		}
		else {
			printf("0이다...");
			// 비트 상태로 본다.. 값 아니고...
		}

	}
	return 0;
}

int main_bitwise() {
	// itoa(): radix 2
	int n = 0x12345678;
	int length;
	int i;
	length = sizeof(n) * 8;	// bits
	// 1비트씩 출력한다...
	printf("%x \n", n);
	for (i = length-1; i >= 0; --i) {
		// 비트 단위로 반복한다.... [0] ~ [31]
		printf("%d", (n>>i) & 0x1 );// [0]번 비트만 출력
	}
	printf("\n");

	//// 3번, 12번 비트가 1인 값
	//n = (1<<3) | (1<<12);
	//printf("%d \n", n);
	//printf("%x \n", n);

	//// 임의 변수의 비트들을 0번으로 내려서....
	//printf("%x \n", n >> 3);
	//printf("%x \n", n >> 12);

	//printf("%x \n", 1 << 31 );// 최대 번호 넘지 못함
	//printf("%x \n", 1 << 33);//[2]
	//printf("%x \n", 1 << 34);//[3]

	return 0;
}

int main_bitop() {
	int n = 0x12345678;	// 16진수 2자리 1byte ( 8bits )
	// 비트 연산의 결과는 정수-> 비트로 생각

//	printf("%d", n&0x1);// 0번만, 나머지 0만든다...
//	printf("%d", n & 0x8);// 0번,1번만, 나머지 0만든다...

						//	~(1);
	//printf("%d \n", n);
	//printf("%X \n", n);
	//printf("%p \n", n);// 주소 표기

	//printf("%X \n", n & 0xFFFF0000);
	//printf("%X \n", n | 0x00000000);
	//printf("%X \n", n | 0xFFFFFFFF);
	//printf("%X \n", ~0xFFFF0000);
	//printf("%X \n", n ^ 0xFFFF0000);// 보수
	//printf("%X \n", n << 1);
	//printf("%X \n", n >> 1);
	
	return 0;
}

int main_99dan() {
	int a, b, c;
	int k;
	int column;//	행 단 수
	int s, e;
	printf("단 수 : ");
	scanf("%d", &column);
	// 변수, 값에 따라서 처리 다르다....
	// 관계를 파악하자....
	for (a = 2; a <= 9; a+=column) {
		for (b = 1; b <= 9; ++b)
		{
			for (k = 0; k < column; ++k) {
				c = (a + k) * b;
				printf("%d x %d = %d\t", a + k, b, c);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}

int main_gugudan() {
	// 구구단 
	int a, b, c;

	for (a = 2; a <= 9; ++a) {
		for (b = 1; b <= 9; ++b)
		{
			c = a * b;
			printf("%d x %d = %d", a, b, c);
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}

// 향상 과제 : 4개 직선으로 모서리를 그리세요..
int main_edge() {
	// 행 단위, 열 단위 에 대한 조건
	// 가로, 세로 입력받아서...
	int row, col;
	int i, k;
	do {
		// 외부에서 가져오기: 비운다....
		rewind(stdin);
		printf("가로, 세로 : ");
	}while( 2 != scanf("%d %d", &col, &row));
	// 2개가 입력되어야 출력하기
	for (i = 0; i < row; ++i) {
		if (i == 0 || i == row-1) {
			for (k = 0; k < col; ++k) {
				printf("*");
			}
		}
		else {
			printf("*");
			for (k = 2; k < col; ++k) {
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
	return 0;
}