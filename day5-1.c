
#include "Simple.h"

int main() {

	return 0;
}

int main_baseball() {
	// 3�ڸ��� ���� ���� 10���� ����ϼ���
	int num;
	int ran;// 0 ~ 9
	int i, k;
	int flag;	// 0�� 9�� ��Ʈ��
	int digits = 12;// �ڸ� ���� ����

	for (i = 0; i < 10; ++i) {
		num = rand()%9+1;
		flag = 0;
		flag = flag | (1 << num);// ǥ���Ѵ�.
		for (k = 1; k < digits; ++k) {
			do {
				ran = rand() % 10;
			} while (flag & (1 << ran));// ���������
			num = num * 10 + ran;	// ����ߴ�.
			flag = flag | (1 << ran);// ǥ���Ѵ�.
		}
		printf("num is : %d \n", num);
	}

	return 0;
}

int main_bb_1() {
	// �ߺ� ���� : ���� ���� : ��뿩�� ǥ���ؼ�
	//			: �˻� : ��� ���ؼ� ���� �� Ȯ��
	// 16��Ʈ ¥�� ������ �����....
	short flag;
	int r;
	// ��� ��Ʈ�� 0 ���� �����....
	flag = 0;
	// 0���� 9���� ���� ���� �����Ѵ�....
	do{
		r = rand() % 10;
		// ���� ���� Ȯ��, r �� ��Ʈ�� ���� 1���� Ȯ��
	}while(flag & (1 << r));
	// 1�̸� �ٽ� ���� ���� �����Ѵ�...
	// 0�̸� 1�� ���� �� ó���Ѵ�...
	flag = flag | (1 << r);

	return 0;
}

int main_checkin() {
	// ���� ��Ʈ�� ���� 1�� �����...
	{
		int n = 0;

		//[4]�� ��Ʈ�� 1�� �����...
		n = n | (1<<4);// �������� �״�� �ΰ�....
		n = n | (1 << 3);// �������� �״�� �ΰ�....
		printf("%x \n", n);

	}
	// ���� ��Ʈ�� ���� 1���� Ȯ�� : 0�� �ƴϴ�....
	{
		int n = 4;	// 0100

		if ( n & (1<<3) ) {// 0�̸� ����
			printf("1�̴�...");
		}
		else {
			printf("0�̴�...");
			// ��Ʈ ���·� ����.. �� �ƴϰ�...
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
	// 1��Ʈ�� ����Ѵ�...
	printf("%x \n", n);
	for (i = length-1; i >= 0; --i) {
		// ��Ʈ ������ �ݺ��Ѵ�.... [0] ~ [31]
		printf("%d", (n>>i) & 0x1 );// [0]�� ��Ʈ�� ���
	}
	printf("\n");

	//// 3��, 12�� ��Ʈ�� 1�� ��
	//n = (1<<3) | (1<<12);
	//printf("%d \n", n);
	//printf("%x \n", n);

	//// ���� ������ ��Ʈ���� 0������ ������....
	//printf("%x \n", n >> 3);
	//printf("%x \n", n >> 12);

	//printf("%x \n", 1 << 31 );// �ִ� ��ȣ ���� ����
	//printf("%x \n", 1 << 33);//[2]
	//printf("%x \n", 1 << 34);//[3]

	return 0;
}

int main_bitop() {
	int n = 0x12345678;	// 16���� 2�ڸ� 1byte ( 8bits )
	// ��Ʈ ������ ����� ����-> ��Ʈ�� ����

//	printf("%d", n&0x1);// 0����, ������ 0�����...
//	printf("%d", n & 0x8);// 0��,1����, ������ 0�����...

						//	~(1);
	//printf("%d \n", n);
	//printf("%X \n", n);
	//printf("%p \n", n);// �ּ� ǥ��

	//printf("%X \n", n & 0xFFFF0000);
	//printf("%X \n", n | 0x00000000);
	//printf("%X \n", n | 0xFFFFFFFF);
	//printf("%X \n", ~0xFFFF0000);
	//printf("%X \n", n ^ 0xFFFF0000);// ����
	//printf("%X \n", n << 1);
	//printf("%X \n", n >> 1);
	
	return 0;
}

int main_99dan() {
	int a, b, c;
	int k;
	int column;//	�� �� ��
	int s, e;
	printf("�� �� : ");
	scanf("%d", &column);
	// ����, ���� ���� ó�� �ٸ���....
	// ���踦 �ľ�����....
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
	// ������ 
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

// ��� ���� : 4�� �������� �𼭸��� �׸�����..
int main_edge() {
	// �� ����, �� ���� �� ���� ����
	// ����, ���� �Է¹޾Ƽ�...
	int row, col;
	int i, k;
	do {
		// �ܺο��� ��������: ����....
		rewind(stdin);
		printf("����, ���� : ");
	}while( 2 != scanf("%d %d", &col, &row));
	// 2���� �ԷµǾ�� ����ϱ�
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