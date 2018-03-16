#include "Simple.h"

struct _data {
	int value;
};
typedef struct _data	DATA;

DATA getData(void) {
	DATA temp;
	temp.value = rand();
	return temp;	// ����
}
void putData(DATA arg) {// ����
	printf("%d \n", arg.value);
}
// ������ ����ü�� ����, ������ ����ü�� ��ȯ
DATA editData(DATA arg) {
	arg.value = rand();
	return arg;
}

int appendData(DATA *list[], DATA arg) {
	// �����ͺ������� ��� �ٸ� ���� ����Ų��...
	static int length = 0;
	DATA *ptr;
	ptr = (DATA*)malloc(sizeof(DATA));
	*ptr = arg;	// ����
	list[length] = ptr;
	++length;
	return length;
}
int viewList(DATA *list[], int length) {// ����� ����
	int i;
	for (i = 0; i < length; ++i) {
		if ( list[i] != NULL) {
			printf("[%2d]: ", i);
			putData(*list[i]);
		}
	}
	// �����ͺ����� ����Ű�� ���� ������ ó�� �Ұ�....
	return i;
}
DATA selectOne(DATA *list[], int length, int key) {
	// �˻��ϱ� : �ִ�, ����..... ������ �ϳ�, ���� ��
	DATA temp = { 0 };
	int i;
	for (i = 0; i < length; ++i) {
		if ( list[i] != NULL && list[i]->value == key) {
			temp = *list[i];// ���� ����....
			break;
		}
	}
	return temp;
	// ��ȯ�ϴ� ������ ���� 0�̶�� ����.....
}
int select(DATA **list, int length, DATA *dest[], int key) {
	// �˻��ϱ� : �ִ�, ����..... ������ ���� ��
	int i, k = 0;
	for (i = 0; i < length; ++i) {
		if (list[i] != NULL && list[i]->value == key) {
			dest[k] = list[i];	// �ּҸ� ����
			++k;
		}
	}
	return k;
	// ��ȯ�ϴ� ������ ���� 0�̶�� ����.....
}

int main() {
	// �����ͺ����� �����͹迭
	DATA *list[10] = { 0 };
	DATA *result[10] = { 0 };
	DATA temp;
	temp = getData();	// ����ü���� �ȿ�... ���� ���� ����� �ִ�...
	appendData(list, temp);
	temp = getData();
	appendData(list, temp);
	temp = getData();
	appendData(list, temp);

	viewList(list, 10);
	printf("�˻��� ���� : %d \n",
		select(list, 10, result, 41));
	viewList(result, 10);

	temp = selectOne(list, 10, 10);
	if (temp.value == 0) {
		printf("ã�� �� ����\n");
	}
	else {
		printf("�˻���� \n");
		putData(temp);
	}

	// �����Ͱ� ����Ű�� ������ ������ ������ �����Ѵ�....
	temp = editData(*list[0]);
	// temp �� ������ ��
	*list[0] = temp;

	return 0;
}
