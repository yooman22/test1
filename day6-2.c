#include "Simple.h"


int main_histo() {
	int histo[10] = { 0 };
	int value;
	int i,idx;
	{// �迭�� ���� �����Ѵ�...
		for (i = 0; i < 1000; ++i) {
			value = rand();
			idx = value / 10;
			if (idx >= 9)	idx = 9;// ��ҹ�ȣ ���� ??
			histo[idx]++;
		}
	}

	{// �迭�� ���� �̿��ؼ� ����Ѵ�....
		int k;
		for (i = 0; i < 10; ++i) {
			printf("[%d]:", i);
			for (k = 0; k < histo[i]; ++k) {
				printf("#");
			}
			printf("\n");
		}
	}
	return 0;
}

int main_score() {
	int score[10];
	int total = 0;
	int avg = 0;
	int length;	// ����� ����
	int i, k, m;
	char menu;// ������ ��ȣ
	length = 0;
	k = 0;	// �߰��Ҷ� ��ȣ
	while (1) {
		// ����� �������� ����Ѵ�... ��Ϻ���
		total = 0;
		avg = 0;
		for (i = 0; i < length; ++i) {
			printf("[%d] %d \n", i, score[i]);
			total += score[i];
		}
		if (length) {
			avg = total / length;
		}
		// ����, ���
		printf("����:%d, ���:%d\n", total, avg);
		// ����� ����(�߰�[1]����[0])
		printf("[1]add,[0]exit\nmenu : ");
		menu = getc(stdin);//scanf("%d");
		rewind(stdin);
		if (menu == '0') {
			break;
		}
		// �߰��ϱ�:�迭 ���� ���� �ʰ�
		if ( length < 10 ) {
			printf("���� : ");
			scanf("%d", &m);	rewind(stdin);
			score[k] = m;//0
			++k;
			++length;
		}
		else {
			printf("Memory Full \n");
		}
	}//end while

	return 0;
}