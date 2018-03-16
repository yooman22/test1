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

int appendData(DATA list[], DATA arg) {
	static int length = 0;
	list[length] = arg;
	++length;
	return length;
}
int viewList(DATA *list, int length) {// ����� ����
	int i;
	for (i = 0; i < length; ++i) {
		printf("[%2d]: ", i);
		putData( list[i] );
	}
	return i;
}
DATA selectOne(DATA list[], int length, int key) {
	// �˻��ϱ� : �ִ�, ����..... ������ �ϳ�, ���� ��
	DATA temp = { 0 };
	int i;
	for (i = 0; i < length; ++i) {
		if (list[i].value == key) {
			temp = list[i];
			break;
		}
	}
	return temp;
	// ��ȯ�ϴ� ������ ���� 0�̶�� ����.....
}
int select(DATA list[], int length, DATA *dest, int key) {
	// �˻��ϱ� : �ִ�, ����..... ������ ���� ��
	int i, k = 0;
	for (i = 0; i < length; ++i) {
		if (list[i].value == key) {
			dest[k] = list[i];
			++k;
		}
	}
	return k;
	// ��ȯ�ϴ� ������ ���� 0�̶�� ����.....
}

int main() {
	DATA list[10] = { 0 };
	DATA result[10] = { 0 };
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

	return 0;
}

int main_dynamic_array() {
	// ���� �Է��� ��ŭ ��� �����Ѵ�...
	int *list = NULL;// �迭 ����...
	int i=0,k;
	int value;
	while( scanf("%d", &value) ){
		list = (int*)realloc(list, sizeof(int)*(i+1));
		list[i] = value;
		++i;
	}
	printf("\n�Է�����\n");
	for (k = 0; k < i ; ++k) {
		printf("%d-%d \n", k, list[k]);
	}

	return 0;
}

int main_1() {
	// �����Ҵ�.... ���� �߿� �޸𸮸� Ȯ��
	int *ptr;

	// ũ�� 4����Ʈ ���� 1���� �����Ѵ�...
	ptr = malloc(10*sizeof(int));
	ptr = calloc(1,sizeof(int));// �迭
	ptr = NULL;
	ptr = realloc(ptr, sizeof(int)*(10+3));// ��ü ũ�� 
	if (ptr == NULL) {
		printf("failed malloc \n");
	}
	else {
		printf("%d %d\n", &ptr, ptr);
	}
	free(ptr);// ���� ���ش�...
	ptr = NULL;
	return 0;
}
