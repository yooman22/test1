/* pointer */
#include "Simple.h"

struct _data {
	int value;
	char type;
};

int main_96() {
	unsigned int value = 0;
	// �����ͺ����� �ɰ���.... 
	// ����Ű�� ���� �ڷ��� x ����� ũ�⸸ŭ ó��
	char *byte;
	byte = (char*)&value;
	// ù �����ϴ� ��ġ... �̾����� ������ ����
	*byte = 0xAB;
	++byte;// byte = byte  + 1;
	*byte = 0xCD;
	++byte;
	*byte = 0xEF;
	printf("%x \n", value);
	// �����ͺ����� ���� ����Ǿ� �ִ�....
	// �ٽ� ù ��ġ �ǵ��� ����....

	return 0;
}
// �ý��� ���α׷��� : �޸� ����, �������(IPC)
int main_95() {
	int value;// �մ�, ���� �б�, ���⸦ �����Ӱ� ���� �ʿ�
	int *in;
	int *out;
	in = &value;
	out = &value;
	// ����
	*in = 100;	// �����Ͱ� ����Ű�� ���� - ����, �о����
	// ������
	printf("%d \n", *out);

	return 0;
}

int main_94() {
	// const : ���� �������� ���� ���̴�.......
	// �˷��ش�... �Լ�....
	const char *str = "Hello progrmming";
	// ���ڿ� ����� �̸� ���������� �����صд�
	// �޸𸮴� ���� ���еǾ� �־��.... �б�, ���� 
	char *p = (char*)str;
//	str[0] = '1';
	printf("%d, %s \n", str, str);

	return 0;
}

int main_93() {
	int a, b;
	int *pa, *pb;
	// ���ϱ�....
	a = b = 10;
	if (a == b) {
		printf("a==b\n");
	}
	// �ּ�, ���� ���� ����
	pa = &a;
	pb = &b;
	if (pa == pb) {
		printf("pa==pb\n");
	}
	else {
		printf("pa!=pb\n");
	}
	if (*pa == *pb) {
		printf("*pa==*pb\n");
	}
	else {
		printf("*pa!=*pb\n");
	}
	return 0;
}

int main_92() {
	// ������ ������ ���� : �ڷ��� * ������;
	int *pc;	// char�� ������ �ּҸ� �����ϴ� �����ͺ���
	char* cp;	// * �� ������ �����ʹ�...

	// + - �ּ� ���� : �ּ� , ���� ����� ũ�⸸ŭ
	pc = 0;	// 0������ ���ٺҰ�...
	printf("%d \n", pc + 1);	// 1�� �̵��� �ּ�
	printf("%d \n", pc + 2);	// 2�� �̵��� �ּ�
	printf("%d \n", pc + 3);	// 3�� �̵��� �ּ�
	printf("%d \n", &pc - &cp); // �Ÿ�
	printf("%d %d\n", &pc, &cp); // �Ÿ�

	//printf("�����ͺ����� �ּ� : %d \n", &pc);
	//printf("����Ű�� �ּ� : %d \n",  pc);
	//printf("����Ű�� �ּҿ�(����) %d \n", *pc);

	return 0;
}

int main_91() {
	{
		// ������ �ּ�
		int num;
		printf("%d \n", &num);	 // num ������ �ּ�
		num = 10;	// ������ = ���� �����ض�..
		printf("%d \n", num);	// num ������ ����� ��
	}

	{
		// �迭 �ּ�
		char ar[80];// �迭�� ũ��: 80bytes, ����� ũ��: 1byte
		printf("ar : %d \n", ar);	// �迭�� �ּ��̴�...
		printf("&ar : %d \n", &ar);	// �迭�� �ּ��̴�...
		printf("&ar[0] : %d \n", &ar[0]);	// [0]���� �ּ��̴�...
		// ����� �ּ��� ũ��
		printf("%d \n", sizeof(ar));
		printf("*ar : %d \n", sizeof(*ar));
		printf("*(&ar) : %d \n", sizeof(*(&ar)));
	}

	{
		// ����ü �ּ�
		struct _data	temp;
		printf("%d \n", sizeof(temp));
		printf("%d \n", &temp);			// ����ü������ �ּ�
		printf("value : %d \n", &temp.value);	// ����� �ּ�
		printf("type : %d \n", &temp.type);	// ����� �ּ�
		printf("%d \n", (&temp)->value);	// ����ü������ �ּҿ��� ���

	}

	return 0;
}
