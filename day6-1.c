#include "Simple.h"
/* �迭 ó�� 
	�迭 ����, ������.
	�����ϱ�(��ü,�Ϻ�)
	�߰��ϱ�,�����ϱ�
	�����ϱ�(���ӻ�������,����)
*/
int main_insert() {
	// �����ϱ� : ������...
	int list[10] = { 1,2,3,4,5 };
	int ins = 3;
	int value = 7;
	int i;
	// ins�� ����...
	for (i = 9; i > ins;--i) {
		list[i] = list[i-1];
	}
	list[ins] = value;

	return 0;
}
int main_remove() {
	// �����ϱ�....
	// �����... ������ �״�� �ִ�....
	// +1 �� ä���� ����...
	int list[10] = {1,2,3,4,5,6,7,8,9,0};
	int i;
	for (i = 0; i < 10; ++i) {
		printf("%d, ", list[i]);
	}
	printf("\n");
	{// ���� : �Էµ� ������ �������...
		int del = 4;
		int t;
		t = list[del];
		list[del] = list[9];// ��������Ҹ� ���� ��ҿ� �����..
		list[9] = t;
	}
	if(0){// ����: �Էµ� ������ �����Ѵ�....
		int del = 4;
		int k;
		for (k = del; k < 9; ++k) {
			list[k] = list[k + 1];
		}
		list[9] = 0;
	}
	for (i = 0; i < 10; ++i) {
		printf("%d, ", list[i]);
	}
	printf("\n");

	return 0;
}

int main_copy() {
	// �����ϱ�... 2�� �ȴ�...
	int src[20];
	int dest[20];
	int i;
	// ���� ����
	for (i = 0; i < 20; ++i) {
		dest[i] = src[i];
	}
	// ���� 
	for (i = 0; i < 20; ++i) {
		dest[19-i] = src[i];
	}

	// �Ϻ� 3 ~ 10
	for (i = 3; i < 11; ++i) {
		dest[i-3] = src[i];
	}
	// �Ϻ� 3 ~ 5��
	for (i = 0; i < 5; ++i) {
		dest[i - 3] = src[3+i];
	}

	return 0;
}

int main_4() {
	// �߰��ϱ�...
	int value;
	int list[20];
	int i = 0;// 0������...
	while (1) {
		value = rand();
		list[i] = value;
		++i;// ����, ��ȣ ?
		if (i == 20) {
//			break;
		}
	}
	printf("Full \n");
	return 0;
}
int main_3() {
	// �߰��ϱ�....
	int score[20];
	int seq = 0;
	// ������ ��ȣ < ������ ��ȣ
	// ������ ��ȣ < ����
	score[seq] = 1;
	++seq;
	// �ִ� ������ �ѱ��� �ʴ´�..
	if (seq > 20) {
		printf("��ģ��...\n");
	}

	score[seq] = 2;
	++seq;

	score[seq] = 3;
	++seq;
	return 0;
}
int main_2() {
	// ��� ���� �ݺ� : ��ȣ
	int score[20];
	int max_index = 20-1;// 0
	int i;	// ��ҹ�ȣ 
	int value;// ����� ��
	// �����ϱ�
	for (i = 0; i <= max_index;++i) {
		score[i] = rand();
	}
	// ������
	for (i = 0; i <= max_index; ++i) {
		value = score[i];
		printf("[%d] %d \n", i, value);
	}

	return 0;
}
int main_1() {
	// ��� �ڷ��� �迭��[�ִ밳��]
	char list[10];

	printf("size : %d \n", sizeof(list));
	printf("size : %d \n", sizeof(list[0]));

	printf("address : %d \n", list + 0);
	printf("address : %d \n", list + 1);
	printf("address : %d \n", list + 2);
	printf("address : %d \n", list + 3);
	// �迭 ��ҵ��� �����ؼ� ����
	return 0;
}