#include "Simple.h"
/*	�ݺ�
		���� ����ȴ�...
		1�� �� ��, ��Ģ�� ã�´�....
		���Ѵ�... ����....
		����� ����,��
*/

int main_word() {
	// test : 6�ڸ��� ���ڵ��� ���
	// ���� : �ҹ���, # , 9 �� ���
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
	// �����ؼ�, ����, �� ���Ѵ�....
	// �� ���� ����
	for (num=0;num < 10; ++num) {
		printf("[%d] \n", num);
	}
	// ���� ������.... ������++, ������--
	printf("[%d] \n", num);



	//do {
	//	scanf("%d", &num);
	//	rewind(stdin);
	////} while ( !( num < 20 ) );
	//} while ( num >= 20 );
	//// �˻��ϱ�....

	return 0;
}

int main_while() {
	// �ݺ��ϱ�
	char ch;
	while( (ch = getc(stdin)) != '\n' ){
		// ���� �� ����ؼ� �Է�, 9 �����Ѵ�...
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