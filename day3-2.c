#include "Simple.h"
/*	반복
		언제 종료된다...
		1번 할 때, 규칙성 찾는다....
		변한다... 영향....
		종료시 상태,값
*/

int main_word() {
	// test : 6자리의 문자들을 출력
	// 조건 : 소문자, # , 9 만 사용
	char ch;
	int i;
	int r;

	while (1) {
		for (i = 0; i < 6; ++i) {
			r = rand() % 28;
			if (r == 26) { ch = '#'; }
			else if (r == 27) { ch = '9'; }
			else {
				ch = 'a' + r;
			}
			printf("%c", ch);
		}
		printf("\n");
		getchar();
	}//end while
	return 0;
}

int main_for() {

	int num;
	// 시작해서, 까지, 씩 변한다....
	// 식 생략 가능
	for (num=0;num < 10; ++num) {
		printf("[%d] \n", num);
	}
	// 증감 연산자.... 변수명++, 변수명--
	printf("[%d] \n", num);



	//do {
	//	scanf("%d", &num);
	//	rewind(stdin);
	////} while ( !( num < 20 ) );
	//} while ( num >= 20 );
	//// 검사하기....

	return 0;
}

int main_while() {
	// 반복하기
	char ch;
	while( (ch = getc(stdin)) != '\n' ){
		// 여러 번 계속해서 입력, 9 종료한다...
		if ('0'<=ch && ch<='9') {
			printf("0");
		}
		else {
			printf("1");
		}
	}
//	getc(stdin);


	return 0;
}