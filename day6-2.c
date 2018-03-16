#include "Simple.h"


int main_histo() {
	int histo[10] = { 0 };
	int value;
	int i,idx;
	{// 배열에 값을 저장한다...
		for (i = 0; i < 1000; ++i) {
			value = rand();
			idx = value / 10;
			if (idx >= 9)	idx = 9;// 요소번호 범위 ??
			histo[idx]++;
		}
	}

	{// 배열에 값을 이용해서 출력한다....
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
	int length;	// 저장된 개수
	int i, k, m;
	char menu;// 선택한 번호
	length = 0;
	k = 0;	// 추가할때 번호
	while (1) {
		// 저장된 정수들을 출력한다... 목록보기
		total = 0;
		avg = 0;
		for (i = 0; i < length; ++i) {
			printf("[%d] %d \n", i, score[i]);
			total += score[i];
		}
		if (length) {
			avg = total / length;
		}
		// 총합, 평균
		printf("총합:%d, 평균:%d\n", total, avg);
		// 사용자 선택(추가[1]종료[0])
		printf("[1]add,[0]exit\nmenu : ");
		menu = getc(stdin);//scanf("%d");
		rewind(stdin);
		if (menu == '0') {
			break;
		}
		// 추가하기:배열 길이 넘지 않게
		if ( length < 10 ) {
			printf("정수 : ");
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