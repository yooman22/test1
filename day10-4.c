#include "Simple.h"


int main_1011() {
	int value = 100;
	int *p1;
	int *p2;
	int *temp;
	// �����ϴ� ���� �����ΰ�??
	p1 = (int*)malloc(4);
	p2 = (int*)malloc(4);
	*p1 = 10;
	*p2 = 20;

	// ��ȯ�϶�...
	temp = p1;
	p1 = p2;
	p2 = temp;

	value = *p1;
	*p1 = *p2;
	*p2 = value;

	printf("%d, %d \n", *p1, *p2);

	return 0;
}

int main_1010() {
	// �ڷ���* ������;	�����ͺ��� : �ּҸ� ����
	// �ڷ��� �迭[];	�Ϲݺ�����....
	// �ڷ���* �迭��[];	�����ͺ�����.... �ּ� ���� ���� ����
	int* list[10];	// ��ҵ��� �����ͺ�����....
	int a, b, c;
	list[0] = &a;	// �ּ� 1000������ ����Ų��....
	list[1] = &b;
	list[2] = (int*)malloc(sizeof(int));	// ����Ű�� ���� ����....
	// �����ͺ����� �ݵ�� ����ų �ٸ� ������ �־�� �Ѵ�....

	// �ּҰ� ������
	list[0] == list[1];	// �����ʹ� 1��
	list[0] != list[1]; // �����Ͱ� 2��

	// ��(������)
	*list[0] == *list[1];
	*list[0] != *list[1];


	return 0;
}


int main(int argc, char *argv[], char **env) {
	// ** -> �����͹迭
	while (*env) {
		printf("%s\n", *env);	// env �� ����Ű�� ���ڿ�
		++env;
	}

	return 0;
}
