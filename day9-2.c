#include "Simple.h"
// ��ȯ�� ������ ����....
int global;
void getInteger_1(void) {
	global = 10;
}
int getInteger_2(void) {
	// 1 ~ 20
	int v = 0;
	scanf("%d", &v);
	return v;
}
void getInteger_3(int *param) {
	// ������ �ּҸ� �޾Ƽ�
	if (param != NULL){
		*param = 30;
	}
}
int *getInteger_4(void) {
	// �ּҸ� ��ȯ�ϴ� �Լ� : ���������� �ּҴ� ��ȯ�ϸ� �ȵȴ�...
	int value;
	value = 40;
	if( value < 40)
		return &value;
	
	return NULL;
	// ����(��������)�� �ּҸ� ��ȯ�ϸ� ��������...
	// ���� ���, ���� �ƴ� �����ؼ�
}

// ����Լ�: �ڽ��� ȣ���Ѵ�... �ݺ�
int r1() {
	r1();	// ��� ȣ�� : ���ѹݺ� : �޸� ��ģ��...
	return 0;
}
int r2() {
	static int count = 0;
	if (++count == 10) {
		return 0;
	}
	r2();
	return 0;
}
int r3() {
	static int count = 0;
	if (++count == 10) {
		return 0;
	}
	printf("[%p] count %d \n", &count, count);
	r3();
	printf("[%p] count %d \n", &count, count);
	return 0;
}

int r4(int i) {
	if (i == 0) {
		return 1;// �ּ� �󸶱���
	}
	return i*r4(i-1);
}
// Ž�� : ������ �ݺ��� ó���Ѵ�...
int r5(int arg) {
	if (arg == 0) {
		return 0;
	}
	printf("%d\n", arg);
	r5(arg - 1);
	return 0;
	// �ִ� ȣ�Ⱑ���� Ƚ��
}

// ���ڿ��� �Է¹޴´�.. �������� ����ض�..
int reverse( char *param) {// = buf
	if ( *param == '\0') {
		return 0;
	}
	// �������
	reverse(param+1);
	// ����
//	reverse(param + 1);
	printf("%c", *param);
	return 0;
}
int main() {
	char buf[80] = { 0 };
	int i, last;
	fgets(buf, 80, stdin);
	// [0]->��������ȣ --
	last = strlen(buf)-1;
	for (i = last; i >= 0; --i) {
		printf("%c", buf[i]);
	}
	printf("\n");

	reverse(buf);// �� ���� ������ �ݺ��Ѵ�....

	return 0;
}

int main_3() {

	int i;
	int value = 0;
	//  �ݺ� �ʸ� 
	for (i = 0; i < 100000; ++i) {
		value += i;
	}
	printf("v : %d \n", value);
	// ������ ��� �����....
	r5(100000);


	return 0;
}

int main_2() {
	int value;
	value = r4( 10 );
	printf(" value %d \n", value);
	return 0;
}

int main_1() {
	int result;
	int *ptr;

	getInteger_1();
	printf("global : %d \n", global);

	result = getInteger_2();
	printf("result : %d \n", result);

	getInteger_3( &result);
	printf("result : %d \n", result);

	ptr = getInteger_4();// �ּҸ� ��ȯ�ϴ� �Լ��� ���� �˻��ض�....
	if (ptr == NULL) {
		printf("error \n");
	}
	printf("result : %d \n", *ptr);
	printf("result : %d \n", *ptr);

	return 0;
}
