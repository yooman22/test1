#include "Simple.h"

struct _tagname {
	// ������� ����
	char type;
	int value;
	char title[80];
	char *pbuf;	// ����ų �ּ�
//	struct _tagname member;	// ��ȯ ����
};
// ��������� �� �޸� �ּҸ� �������� �ʴ´�...

typedef struct _tagname	T;
typedef struct _tagname	*PT;

int main_struct_2() {
	T temp = { 0 };
	T *ptr = 1000;
	temp = *ptr;	// ���� : ����ü������ �� ����...
	// ->
	temp.type = 'A';
	temp.value = 100;
	*temp.title = 'C';
	temp.pbuf = temp.title + 40;
	*temp.pbuf = 'D';
	*ptr = temp;
//	fread(&temp, sizeof(temp), 1, fp);
	return 0;
}

int main_struct_base() {
	T *ptr;
	ptr = (T*)calloc(1, sizeof(T));
	ptr[0].type;
	ptr->type;
	(*ptr).title;
	*ptr->title;
	*ptr->pbuf = 'A';
	*(*ptr).pbuf = 'B';	// ����� �����ʹ�....

	{
		PT *p;	// **p
		T temp = { 'A', 100, "Hello", NULL };
		// ����� ����, �ڷ����� ���߾� �ʱⰪ �ֱ�

		temp.title;
		(&temp)->title;
	}

	
	return 0;
}

int main_constpointer() {
	//const int *p = 1000;
	//// �����ͺ����� ����Ű�� ���� �������� �ʴ´�.
	//*p = 10;
	//p = 2000;	// �ּҴ� ������ �� �ִ�..

	//int * const cp = 1000;	// �ּҸ� �����Ѵ�...
	//*cp = 20;
	//cp = 3000;	// �ּҴ� ������ �� ����...

	//// ����ȯ�� ���� ������....
	//*((int*)p) = 20;
	return 0;
}

int main_pointer() {
	{
		int *ptr;	// �����ͺ��� ptr. int�� ������ �ּҸ� ����
		// �ּҸ� ������ �Ŀ� ����Ѵ�...
		int num;
		ptr = &num;	// �ּҸ� ���޹޴´�...
		printf("%d \n", &ptr);	// ptr �� �ּ�
		printf("%d \n",  ptr);	// ptr �� ��(int�� �ּ�)
		printf("%d \n", *ptr);	// ptr �� ����Ű�� ��
	}
	{
		int *ptr;	// ���� �߿� int�� ������ ����(�����Ҵ�)

		// ���⿡�� ������ �ʿ��ϴ�...
		ptr = (int*)malloc( sizeof(int) );// 4
		*ptr = 10;// ����Ű�� ���� ���� ����
		printf("%d \n", &ptr);	// ptr �� �ּ�
		printf("%d \n", ptr);	// ptr �� ��(int�� �ּ�)
		printf("%d \n", *ptr);	// ptr �� ����Ű�� ��
	}
	{
		int *iptr;
		char *cptr;
		// �ּ� ���� . �����ϴ� �����͵�.... �迭�� ����....
		// �ּ� + 1, - 1 ( �ּ��� �ڷ��� ũ�⸸ŭ 1�� �̵� )
		iptr = 100;
		printf("%d \n", iptr + 1);
		printf("%d \n", iptr + 2);// �ڷ��� ũ��
		printf("%d \n", iptr + 3);
		cptr = 100;
		printf("%d \n", cptr + 1);
		printf("%d \n", cptr + 2);// �ڷ��� ũ��
		printf("%d \n", *(cptr + 3) );
		printf("%d \n", *cptr + 3);
	}
	{
		int *ptr;
		int **pop = &ptr;// �����ͺ����� �ּҸ� �����Ѵ�..

		&pop;	// �ּ� : pop�� �ּ� : int*�� �ּҸ� ����Ű�� �����ʹ�...
		pop;	// �ּ� : int*�� �ּ�
		*pop;	// �ּ� : int*�� �̸� : int�� �ּ�
		**pop;	// �� : ���� : int������ ����� ��
	}
	// �ּҸ� ���� �����͵��� �����Ѵ�. ( Ž���Ѵ� )

	return 0;
}