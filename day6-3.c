#include "Simple.h"

int main() {

	return 0;
}

int main_parse() {
	char qry[80] = {"m=bit & n=2"};
	int m, n;
	char buf[80] = { 0 };
	sscanf(qry, "m=%s & n=%d", buf, &n);
	printf("buf %s, n %d \n", buf, n);
	// ������ ������ �����͵� �����Ѵ�....
	// ���ڿ� ���� �ÿ��� �����ڷ� ������ �־�� �Ѵ�..
	return 0;
}

int main_format() {
	// ���ڿ� �Լ� ���� 
	char buf[80] = { 0 };
	char format[] = {"idx = %d&freq = %lf&type = %c"};
	char ch;
	int n;
	double lf;
	//buf[0] = 0;
	//memset(buf, 0, sizeof(buf));// �ʱ�ȭ�Ѵ�...
	//printf("%s\n", buf);

	sprintf(buf, format, 10, 10.3, 'A');
	puts(buf);// printf("%s");

	sscanf(buf, format, &n, &lf, &ch);
	printf(format, n, lf, ch);


	return 0;
}

int main_basic() {
	int score[20];
	int i;
	int length = sizeof(score) / sizeof(int);
	for (i = 0; i < length; ++i) {
		printf("[%d]�� �л� ���� : ",0);
		scanf("%d", &score[i]);
	}
	return 0;
}

int main_dummy() {
	// �뷮 ������ ������ ����, ������ ����
	// 1���迭�� ó���ؼ� ��ȣ �̿� �ݺ�

	// ����, ����, ���� ������
	// ���� ���ؼ� ���
	// �������� ��� ���
	// �л� 1��(��,��,��) 5�� �� 15�� ����
	int k1, m1, e1;
	int k2, m2, e2;
	int k3, m3, e3;
	int k4, m4, e4;
	int k5, m5, e5;
	int total = 0;

	printf("1�� �л� ���� : ");
	printf(" ���� :");
	scanf("%d", &k1);
	total += k1;
	printf(" ���� :");
	scanf("%d", &e1);
	total += e1;
	printf(" ���� :");
	scanf("%d", &m1);
	total += m1;

	printf("total : %d \n", total);
	printf("����(%d), ����(%d), ����(%d)\n", k1, e1, m1);


	printf("1�� �л� ���� : ");
	printf(" ���� :");
	scanf("%d", &k1);
	total += k1;
	printf(" ���� :");
	scanf("%d", &e1);
	total += e1;
	printf(" ���� :");
	scanf("%d", &m1);
	total += m1;

	printf("total : %d \n", total);
	printf("����(%d), ����(%d), ����(%d)\n", k1, e1, m1);

	return 0;
}

int main_36() {
	// 20�� �������� ���� �� �߿��� �ִ밪, �ּҰ� ã�´�...
	// �ּҰ��� [0]������,, �ִ밪[19]������
	int list[20] = { 0 };
	int i;
	for (i = 0; i < 20; ++i) {
		list[i] = rand() % 100;
	}
	for (i = 0; i < 20; ++i) {
		printf("%d ", list[i]);
	}
	{// ���� �󸶳�?
		int min, max;
		min = list[0];
		max = list[0];
		for (i = 1; i < 20;++i) {
			if (min > list[i]) {
				min = list[i];
			}
			if (max < list[i]) {
				max = list[i];
			}
		}
	}
	{// ��ġ�� ã�´�....
		int min, max, t;
		min = 0;
		max = 0;
		for (i = 1; i < 20; ++i) {
			if (list[min] > list[i]) {
				min = i;
			}
			if (list[max] < list[i]) {
				max = i;
			}
		}
		// ó�� ����
		t = list[0];
		list[0] = list[min];
		list[min] = t;

		t = list[19];
		list[19] = list[max];
		list[max] = t;
	}
	printf("\n");
	for (i = 0; i < 20; ++i) {
		printf("%d ", list[i]);
	}
	printf("\n");
	return 0;
}

int main_35() {
	// 2���� ������ �Է¹޾Ƽ� ��ġ�� ���� �Ǻ�
	int a, b;
	char as[4] = { 0 };
	char bs[4] = { 0 };

	a = 325;
	b = 237;

	itoa(a, as, 10);
	itoa(b, bs, 10);
	printf("%s vs %s \n", as, bs);
	{
		int i, k;
		for (i = 0; i < 3; ++i) {
			for (k = 0; k < 3; ++k) {
				if (as[i] == bs[k]) {
					// ���� ����...
					if (i == k) {
						printf("��ġ�� ����...\n");
					}
					else {
						printf("��ġ�� �ٸ�...\n");
					}
				}
			}
		}
	}
	return 0;
}

int main_34() {
	char map[20 * 20] = { 0 };
	int i, k;
	for (i = 0; i < 400; ++i) {
		map[i] = i + 1;
	}
	// 400���� �����͸� 20���� �� ������ ����ϼ���
	for (i = 0; i < 20; ++i) {
		for (k = 0; k < 20; ++k) {
			printf("%d ", map[ i*20 + k ] );	// map[i][k]
		}
		printf("\n");
	}
	// �̹��� ����
	// �����迭 : ���� �� ���Ҵ�Ǵ� �迭
	return 0;
}

int main_33() {
	char temp[80] = { 0 };
	itoa(2014, temp, 2);
	printf("%s \n", temp);
	// ��õ�ʻ�
	return 0;
}

int main_32() {
	// CGI
	char text[80] = { 0 };
	printf("%s %d\n", "<li>", 10);
	strcat(text, "<!doctype html>");
	strcat(text, "<html>");
	strcat(text, "</html>");
	printf("%s\n\n", text);
	return 0;
}

int main_31() {
	// ���ڿ� : ���� ���� '\0' ���ᰪ
	// ���� char 1byte
	char temp[80] = { 0 };
	// ���ڿ� �����ϱ�
	strcpy(temp , "Hello");
	strcpy(temp, "Korea");
	printf("%s \n", /*���ڿ��� ��ġ(�ּ�)*/temp);

	// ���ڿ� ��ģ��... : ����ȭ
	strcat(temp, "Japan");
	strcat(temp, "20120");
	printf("%s \n", /*���ڿ��� ��ġ(�ּ�)*/temp);

	// ���ڿ� �� : ������, ��ġ�ϴ� ���ڿ�
	printf("%d \n", strcmp("Korea","Japan"));
	printf("%d \n", strcmp("Korea", "Korea"));
	printf("%d \n", strcmp("Japan", "Korea"));
	// ���ڿ� �� : �κ� ���ڿ�
	printf("%d \n", strstr("Korea","ea"));
	printf("%d \n", strstr("Korea", "aa"));

	printf("Hel\0lo");
	// ���ڿ� ����
	printf("%d \n", strlen("Hello"));// �ι��������� ���� ��
	printf("%d \n", strlen("�ѱ�"));

	return 0;
}