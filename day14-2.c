#include "Simple.h"

int fa() {
	return 0;
}
int fb(int *param, int size) {
	// �ּҸ� ���޹������� .. 1�� or ���ӵ� ���� ��
	// ũ�⸦ ���޹��� ��� ~���� ���
	int length = size / sizeof(*param);
	// ������ ���޹��� ��� ~ũ�� ���
	// �ַ� �迭�� ( �迭��, ���� )
	return 0;
}
int fc(int *param, int start, int end) {
	// ��ҹ�ȣ ����, ��
	param[start];
	param[end];
	return 0;
}
int fd(int **p) {
	// �����ͺ����� �ּҸ� ���޹޴´�....
	free(*p);
	*p = malloc(50);
	// ���޹��� �����ͺ����� ����Ű�� ������ ������..... �Ұ��ΰ�?
	return 0;
}


// ����ü : �����͸�� : �ڽŰ� ���� �ڷ��� : �ڱ���������ü
typedef struct _selfstruct {
	struct _selfstruct *ptr;
	int testValue;
}T;
int main_self_structure() {
	T t1;
	T t2;
	// �ڷ����� ���� �ٸ� ������ ����Ų��....
	t1.testValue = 1;
	t1.ptr = &t2;

	t2.testValue = 2;
	t2.ptr = NULL;	// ����...
	{
		T *temp;
		temp = &t1;// ���� ù ������ �ּ�
		while (temp != NULL) {
			printf("v : %d \n", temp->testValue);
			temp = temp->ptr;	// ���� �����ͷ� �ű��..
		}
	}

	return 0;
}
