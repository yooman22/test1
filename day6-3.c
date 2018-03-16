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
	// 지정한 형식의 데이터들 추출한다....
	// 문자열 추출 시에는 구분자로 나뉘어 있어야 한다..
	return 0;
}

int main_format() {
	// 문자열 함수 응용 
	char buf[80] = { 0 };
	char format[] = {"idx = %d&freq = %lf&type = %c"};
	char ch;
	int n;
	double lf;
	//buf[0] = 0;
	//memset(buf, 0, sizeof(buf));// 초기화한다...
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
		printf("[%d]번 학생 점수 : ",0);
		scanf("%d", &score[i]);
	}
	return 0;
}

int main_dummy() {
	// 대량 데이터 일일이 변수, 변수들 모음
	// 1차배열로 처리해서 번호 이용 반복

	// 국어, 영어, 수학 점수들
	// 총합 구해서 출력
	// 점수들을 모두 출력
	// 학생 1명(국,영,수) 5명 총 15개 변수
	int k1, m1, e1;
	int k2, m2, e2;
	int k3, m3, e3;
	int k4, m4, e4;
	int k5, m5, e5;
	int total = 0;

	printf("1번 학생 점수 : ");
	printf(" 국어 :");
	scanf("%d", &k1);
	total += k1;
	printf(" 영어 :");
	scanf("%d", &e1);
	total += e1;
	printf(" 수학 :");
	scanf("%d", &m1);
	total += m1;

	printf("total : %d \n", total);
	printf("국어(%d), 영어(%d), 수학(%d)\n", k1, e1, m1);


	printf("1번 학생 점수 : ");
	printf(" 국어 :");
	scanf("%d", &k1);
	total += k1;
	printf(" 영어 :");
	scanf("%d", &e1);
	total += e1;
	printf(" 수학 :");
	scanf("%d", &m1);
	total += m1;

	printf("total : %d \n", total);
	printf("국어(%d), 영어(%d), 수학(%d)\n", k1, e1, m1);

	return 0;
}

int main_36() {
	// 20개 정수들을 저장 그 중에서 최대값, 최소값 찾는다...
	// 최소값은 [0]번으로,, 최대값[19]번으로
	int list[20] = { 0 };
	int i;
	for (i = 0; i < 20; ++i) {
		list[i] = rand() % 100;
	}
	for (i = 0; i < 20; ++i) {
		printf("%d ", list[i]);
	}
	{// 값이 얼마냐?
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
	{// 위치를 찾는다....
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
		// 처리 변경
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
	// 2개의 정수를 입력받아서 위치와 값의 판별
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
					// 값이 같다...
					if (i == k) {
						printf("위치도 같다...\n");
					}
					else {
						printf("위치는 다름...\n");
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
	// 400개의 데이터를 20개씩 행 단위로 출력하세요
	for (i = 0; i < 20; ++i) {
		for (k = 0; k < 20; ++k) {
			printf("%d ", map[ i*20 + k ] );	// map[i][k]
		}
		printf("\n");
	}
	// 이미지 파일
	// 동적배열 : 실행 중 재할당되는 배열
	return 0;
}

int main_33() {
	char temp[80] = { 0 };
	itoa(2014, temp, 2);
	printf("%s \n", temp);
	// 이천십사
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
	// 문자열 : 가변 길이 '\0' 종료값
	// 문자 char 1byte
	char temp[80] = { 0 };
	// 문자열 대입하기
	strcpy(temp , "Hello");
	strcpy(temp, "Korea");
	printf("%s \n", /*문자열의 위치(주소)*/temp);

	// 문자열 합친다... : 직렬화
	strcat(temp, "Japan");
	strcat(temp, "20120");
	printf("%s \n", /*문자열의 위치(주소)*/temp);

	// 문자열 비교 : 사전식, 일치하는 문자열
	printf("%d \n", strcmp("Korea","Japan"));
	printf("%d \n", strcmp("Korea", "Korea"));
	printf("%d \n", strcmp("Japan", "Korea"));
	// 문자열 비교 : 부분 문자열
	printf("%d \n", strstr("Korea","ea"));
	printf("%d \n", strstr("Korea", "aa"));

	printf("Hel\0lo");
	// 문자열 길이
	printf("%d \n", strlen("Hello"));// 널문자전까지 글자 수
	printf("%d \n", strlen("한글"));

	return 0;
}