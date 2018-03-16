#include "Simple.h"

int main() {

	return 0;
}

int main_shoot() {
	// 슈팅
	int y, x;
	int tx, tbx, tby;// y==0
	int bx, bbx, bby;// y==19

	tx = rand() % 20;
	tbx = tx;
	tby = 1;

	bx = rand() % 20;
	bbx = bx;
	bby = 18;

	while (1) {
		system("cls");
		for (y = 0; y < 20;++y) {
			for (x = 0; x < 20;++x) {
				if (y == 0) {
					if (tx == x) {
						printf("##");
					}
					else {
						printf("..");
					}
				}
				else if (y==19) {
					if (bx == x) {
						printf("$$");
					}
					else {
						printf("..");
					}
				}
				else {
					if (tby==y && tbx==x) {
						printf("11");
					}
					else if (bby == y && bbx == x) {
						printf("22");
					}
					else {
						printf("  ");
					}
				}
			}
			printf("\n");
		}//end display
		// 위치를 변경한다.
		tx = tx + (rand()%3-1);
		if (tx < 0)	tx = 0;
		if (tx > 19)	tx = 19;
		tby++;
		if (tby > 18) {
			tby = 1;
			tbx = tx;
		}

		bx = bx + (rand() % 3 - 1);
		if (bx < 0)	bx = 0;
		if (bx > 19)	bx = 19;
		bby--;
		if (bby < 1) {
			bby = 18;
			bbx = bx;
		}
	}


	return 0;
}

int main_line() {
	int x, y;
	int a, b;
	a = -1;
	b = 10;
	for (y = 0; y < 20; ++y) {
		for (x = 0; x < 20; ++x) {
			if ( y == (a*x)+b  || y==10 || x == 10 ) {
				printf("○");
			}
			else {
				printf("  ");
			}
		}
		printf("\n");
	}


	return 0;
}

int main_eof() {
	char ch;
	while ((ch = getc(stdin)) != EOF) {
		// EOF = -1 ( Ctrl + Z )
		// 메모장 처럼.....
	}
	return 0;
}

int main_replace() {
	// 입력되는 문자들을 다시 출력
	// 특정 문자를 다른 문자로 바꾸어 출력한다.
	char ch;
	while ( (ch=getch()) != '0') {
		if (ch == 'k' ) {
			ch = '\n';
		}
		printf("%c", ch);
	}
	return 0;
}

// 문자열 내에서 일부분을 자른다... parse
int main_word() {
	char ch;
	int count = 0;
	int isDigit = 0;// 숫자가 아니다...
	while ('\n' != (ch = getc(stdin))) {
		if ('0' <= ch && ch <= '9') {
			if (isDigit == 0) {
				++count;
			}
			isDigit = 1;
		}
		else {
			if ( isDigit == 1) {
				// 직전 문자....숫자였고 지금 숫자 아니다..
//				++count;
			}
			isDigit = 0;
		}
	}//end while
	printf("Count : %d\n", count);
	return 0;
}

int main_for() {
	int i,k,m;
	int count;
	// ~에서 ~까지 연속범위 ++
	for (i = 1; i <= 25; ++i) {
		printf("%d,", i);
	}
	printf("\n");
	// 5개씩
	{
		count = 0;
		for (i = 1; i <= 25; ++i) {
			printf("%d\t", i);
			++count;
			if (count == 5) {
				printf("\n");
				count = 0;// 각 행마다 다시 센다....
			}
		}
		printf("\n");
	}

	{
		m = 1;
		for (i = 0; i < 5; ++i) {
			for (k = 0; k < 5; ++k) {
//				printf("%d\t", m++);
				printf("%d\t", (i*5)+k);
				// 행번호*길이 + 열번호
			}
			printf("\n");
		}
	}
	// 방법 연구해보세요



	return 0;
}