#pragma warning(disable:4996)
#include <stdio.h>

int main_5() {
	// ���ڸ� ������ ��ȯ
	int num;// ���ڵ�...

	// �迭 : atoi itoa
	scanf("%d ", /*������ ������ �ּ�*/&num);
	scanf("%d ", /*������ ������ �ּ�*/&num);
	scanf("%d ", /*������ ������ �ּ�*/&num);
	printf("num is %d \n", num);
	//num = getc(stdin);
	//num = getc(stdin);
	//printf("num is %d \n", num - '0');
	//num = getc(stdin);
	//printf("num is %d \n", num - '0');

	return 0;
}

int main_4() {
	// �Է� Ű���忡��
	char in;
	// �Է� ������ ���۸� ����ּ���
	in = getc(stdin);
	rewind(stdin);
	in = getc(stdin);
	rewind(stdin);
	in = getc(stdin);
	rewind(stdin);
	in = getc(stdin);

	printf("%c \n", in);
	return 0;
}