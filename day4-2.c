#include "Simple.h"

int main() {

	return 0;
}

int main_shoot() {
	// ����
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
		// ��ġ�� �����Ѵ�.
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
				printf("��");
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
		// �޸��� ó��.....
	}
	return 0;
}

int main_replace() {
	// �ԷµǴ� ���ڵ��� �ٽ� ���
	// Ư�� ���ڸ� �ٸ� ���ڷ� �ٲپ� ����Ѵ�.
	char ch;
	while ( (ch=getch()) != '0') {
		if (ch == 'k' ) {
			ch = '\n';
		}
		printf("%c", ch);
	}
	return 0;
}

// ���ڿ� ������ �Ϻκ��� �ڸ���... parse
int main_word() {
	char ch;
	int count = 0;
	int isDigit = 0;// ���ڰ� �ƴϴ�...
	while ('\n' != (ch = getc(stdin))) {
		if ('0' <= ch && ch <= '9') {
			if (isDigit == 0) {
				++count;
			}
			isDigit = 1;
		}
		else {
			if ( isDigit == 1) {
				// ���� ����....���ڿ��� ���� ���� �ƴϴ�..
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
	// ~���� ~���� ���ӹ��� ++
	for (i = 1; i <= 25; ++i) {
		printf("%d,", i);
	}
	printf("\n");
	// 5����
	{
		count = 0;
		for (i = 1; i <= 25; ++i) {
			printf("%d\t", i);
			++count;
			if (count == 5) {
				printf("\n");
				count = 0;// �� �ึ�� �ٽ� ����....
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
				// ���ȣ*���� + ����ȣ
			}
			printf("\n");
		}
	}
	// ��� �����غ�����



	return 0;
}