#include "Simple.h"
#include <Windows.h>

/*Q1. 10 개의 임의(입력된) 정수 중 최소, 최대 출력 */
int minmax() {
	int i;
	int r;
	int min,max;// 가장 작은 값이 저장된 상태를 유지한다...
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
/*Q2. 최소(min) 과 최대(max) 를 입력받은 후
	min ~ max 사이 가운데 지점의 값을 출력
*/
int pivot() {
	int mid;
	int min, max;

	printf("최소, 최대 순으로 입력하시오 :");
	scanf("%d %d", &min, &max);	

	mid = (min+max)/2;
	printf("mid : %d \n", mid);	// 중간값
	// 정렬된 데이터들을 반으로 나누어서 탐색 : 이진탐색
	return 0;
}

int main_swap() {
	// 두 변수의 값을 바꾸세요 : 교환
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
	// 키보드에 방향키를 이용해서 별모양을 움직인다....
	int key;
	int x, y;// 별모양의 위치
	int r, c;
	x = y = 10;
	while (1) {
		{
			for (r = 0; r < 15; ++r) {
				for (c = 0; c < 15; ++c) {
					printf("%s",
						(r==y&&c==x) ?"★":"╋");
				}
				printf("\n");
			}
		}// 화면 출력하기
		key = getch();// 224 실제키
		if (key == 224) {	// 0xE0 unsigned char
			key = getch();	// 실제 키 번호
//			printf("%d \n", key);
			switch (key) {
			case 72:	// 위
				--y;	break;
			case 75:	// 왼
				--x;	break;
			case 77:	// 오
				++x;	break;
			case 80:	// 아
				++y;	 break;
			}
		}
		if ( key == 'q') {
			break;
		}
		Sleep(1000);	// 지연 시간 (밀리초 단위)
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
	// 소리내는 법...


	return 0;
}

/*
Q1.	rand 함수에서 반환되는 정수들의 분포 구하기
	
	
	0~100 : A 구간
	~1000 : B 구간
	~10000: C 구간
	100000~:D 구간
*/
/*
Q.2	오목판(20x20) 위에 흰별, 검은별의 위치를 키보드로 변경
	w,a,s,d - 흰별
	i,j,k,l - 검은별
	q - 종료
*/
/*
Q.3	컴퓨터가 사람이 정한 수를 맞추기 ( 업다운 )
	#include<stdlib>

	

    
	
	1. 1~1000 사이에서 사람이 수를 정함(입력하지 않음)
	2. 컴퓨터가 수를 예측하여 보여줌
	3. 사람은 업, 다운, 정답 중 하나를 선택 입력
	4. 컴퓨터는 대답에 따라 다음 수를 예측하여 2부터 반복
	5. 정답인 경우 종료
*/
/*
Q.4	min, max 를 입력 받아 중간(mid)값을 계산 후
	min ~ max 사이의 임의 정수 20개를 출력하고
	그 중 mid 에 가장 가까운 값을 출력
*/



/*
Q.5	음료 자판기 구현해보기
*/

/*
Q.6	키보드 건반 만들기
	영문자만 대상으로....
	-	자동 연주 환영 ( but 배열사용금지 )
*/

/*
Q.7	3개의 정수를 입력받아 1개 정수로 출력
	1. int 형 변수의 크기는 4byte
	2. 1byte 의 최대값 고려(signed)

	
*/