#include "Simple.h"
#include <Windows.h>

/*Q1. 10 ���� ����(�Էµ�) ���� �� �ּ�, �ִ� ��� */
int minmax() {
	int i;
	int r;
	int min,max;// ���� ���� ���� ����� ���¸� �����Ѵ�...
//	min = rand();
	for (i = 0; i < 10; ++i) {
		r = rand();
		if(i==0)	max = min = r;
		if ( min > r) {
			min = r;
		}
		if (max < r) {
			max = r;
		}
		printf("%d ", r);
	}
	printf("\nmin : %d \n", min);
	printf("max : %d \n", max);
	return 0;
}
/*Q2. �ּ�(min) �� �ִ�(max) �� �Է¹��� ��
	min ~ max ���� ��� ������ ���� ���
*/
int pivot() {
	int mid;
	int min, max;

	printf("�ּ�, �ִ� ������ �Է��Ͻÿ� :");
	scanf("%d %d", &min, &max);	

	mid = (min+max)/2;
	printf("mid : %d \n", mid);	// �߰���
	// ���ĵ� �����͵��� ������ ����� Ž�� : ����Ž��
	return 0;
}

int main_swap() {
	// �� ������ ���� �ٲټ��� : ��ȯ
	int t, a, b;

	a = 10;
	b = 20;

	printf("a: %d, b: %d \n", a, b);
	t = a;
	a = b;
	b = t;
	printf("a: %d, b: %d \n", a, b);

	return 0;
}

int main_map() {
	// Ű���忡 ����Ű�� �̿��ؼ� ������� �����δ�....
	int key;
	int x, y;// ������� ��ġ
	int r, c;
	x = y = 10;
	while (1) {
		{
			for (r = 0; r < 15; ++r) {
				for (c = 0; c < 15; ++c) {
					printf("%s",
						(r==y&&c==x) ?"��":"��");
				}
				printf("\n");
			}
		}// ȭ�� ����ϱ�
		key = getch();// 224 ����Ű
		if (key == 224) {	// 0xE0 unsigned char
			key = getch();	// ���� Ű ��ȣ
//			printf("%d \n", key);
			switch (key) {
			case 72:	// ��
				--y;	break;
			case 75:	// ��
				--x;	break;
			case 77:	// ��
				++x;	break;
			case 80:	// ��
				++y;	 break;
			}
		}
		if ( key == 'q') {
			break;
		}
		Sleep(1000);	// ���� �ð� (�и��� ����)
		system("cls");
	}
	return 0;
}

int main_beep() {
	int freq;
	int msec;

	freq = 440;
	msec = 1000;// milli
	Beep(freq, msec);
	// �Ҹ����� ��...


	return 0;
}

/*
Q1.	rand �Լ����� ��ȯ�Ǵ� �������� ���� ���ϱ�
	
	
	0~100 : A ����
	~1000 : B ����
	~10000: C ����
	100000~:D ����
*/
/*
Q.2	������(20x20) ���� ��, �������� ��ġ�� Ű����� ����
	w,a,s,d - ��
	i,j,k,l - ������
	q - ����
*/
/*
Q.3	��ǻ�Ͱ� ����� ���� ���� ���߱� ( ���ٿ� )
	#include<stdlib>

	

    
	
	1. 1~1000 ���̿��� ����� ���� ����(�Է����� ����)
	2. ��ǻ�Ͱ� ���� �����Ͽ� ������
	3. ����� ��, �ٿ�, ���� �� �ϳ��� ���� �Է�
	4. ��ǻ�ʹ� ��信 ���� ���� ���� �����Ͽ� 2���� �ݺ�
	5. ������ ��� ����
*/
/*
Q.4	min, max �� �Է� �޾� �߰�(mid)���� ��� ��
	min ~ max ������ ���� ���� 20���� ����ϰ�
	�� �� mid �� ���� ����� ���� ���
*/



/*
Q.5	���� ���Ǳ� �����غ���
*/

/*
Q.6	Ű���� �ǹ� �����
	�����ڸ� �������....
	-	�ڵ� ���� ȯ�� ( but �迭������ )
*/

/*
Q.7	3���� ������ �Է¹޾� 1�� ������ ���
	1. int �� ������ ũ��� 4byte
	2. 1byte �� �ִ밪 ���(signed)

	
*/