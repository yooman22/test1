#include "Simple.h"
#include <conio.h>	// Ű ó�� ��κ�

int main_kb() {
	int key;
	// ���ͷ�Ʈ : �̺�Ʈ ���
	while (1) {
		if (kbhit()) {
			key = getch();
			printf("........");
		}
		printf("00000000");
	}



	//key = getch();
	//if (key == 0 || key == 224) {
	//	key = getch();
	//	printf("%d \n", key);
	//}
	//else {
	//	printf("%d \n", key);
	//}


	return 0;
}

int main_switch2() {
	// ����ڰ� ������ ��ȣ�� ���� ������ �ٸ���...
	int no;
	int price;
	printf("no : ");
	scanf("%d", &no);// scanf_s 
	if (no == 1) {
		price = 600;
	}
	if (no == 2) {
		price = 300;
	}
	switch (no) {
	case 3:
		price = 1000;
		break;
	case 4:
	case 5:
		price = 800;
		break;
	}
	printf("no[%d], price[%d]\n", no, price);
	return 0;
}

int main_switch() {
	// ���� ���;
	int value;
	value = 40;
	// �̺��� ��ȣ�� ����, �������� �ٸ� ������
	switch ( value / 10) {
	case 4:
		printf("4\n");
		break;
	case 1:
		printf("1\n");
		break;
	case 2:
		printf("2\n");
		break;
	case 3:
		printf("3\n");
		break;
	case 5:
		printf("5\n");
		break;
	}
	return 0;
}

int main_if() {
	// ���
	char ch;
	ch = getc(stdin);
	// �� ������ : ���ǽ��� ���� ���϶� ��ģ��....
	if ( '0'<=ch && ch<='9' ) {	// isdigit()
		printf("����\n");
	}
	else  {
		printf("���ڴ� �ƴϳ׿�\n");
		if ('A' <= ch && ch <= 'Z') {// upper
			printf("up case\n");
		}
		else if ('a' <= ch && ch <= 'z') {// lower
			printf("low case\n");
		}
		else{
			printf("etc....\n");
		}
	}
	return 0;
}

int main_2() {
	// ����(Ư������)
	printf("���������ۦ�������������\n");
	printf("���������ۦ�������������\n");
	printf("���������ۦ�������������\n");
	printf("���������ۦ�������������\n");

	// 3��, 4�� @ ���
	printf("0\n");
	printf("1\n");
	printf("2\n");
	printf("30 1 2 3 @\n");

	// �簢�� 4 x 4
	printf("0 0 0 0\n");
	printf("0 0 0 0\n");
	printf("0 0 0 0\n");
	printf("0 0 0 0\n");

	return 0;
}

int main_1() {
	int b;
//	(3 < 5) && (b = getchar());
	b = (3 < 5) || (printf("22222"));

	// ���� ������, (��) ? �� : ����;
	printf("%s \n", (b==0)?"false":"true" );
	// ��ø : �ȿ� 
	printf("%s \n", 
		(b == 0) ? "false" :
		(b == 1) ? "true"  : "else" );
	
	// if -else if

	printf("%d \n", !1);
	printf("%d \n", 1 && 0);
	printf("%d \n", 0 && 1);
	printf("%d \n", 1 || 0);
	printf("%d \n", 0 || 1);
	//printf("%d \n", 10 < 3);
	//printf("%d \n", 10 > 3);
	//printf("%d \n", 10 == 3);
	//printf("%d \n", 10 != 3);

	return 0;
}
