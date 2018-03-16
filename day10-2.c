/*	야구게임(숫자마추기)
	값이 같다
		위치(자리) 같다 ++strike
		위치(자리) 다르다 ++ball;
	정답과 일치한다면 strike 가 3이다.(3자리)
	서로 한 번씩 물어보고 대답하기를 반복한다.
*/
#include "Simple.h"

//int mode;
//int call;
//int *s;
//int *b;

// 호출 시 매개변수의 개수, type 다르다... 일반화
int user1(int mode, int arg, int *ps, int *pb) {
	static int answer = 0;
	int call;
	int strike, ball;
	char as[8] = { 0 };
	char cs[8] = { 0 };
	int i, k;

	strike = ball = 0;
	if (mode == 1) {	// 정답 정하기
		answer = rand() % 900 + 100;
	}
	if (mode == 2) {	// 부르기
		// 상대에게 부를 값을 반환한다...
		call = rand() % 900 + 100;
		return call;
	}
	if (mode == 3) {	// 대답하기 : 위치(배열)와 값 : 백,십,일
		itoa(answer, as, 10);
		itoa(arg, cs, 10);
		for (i = 0; i < 3; ++i) {
			for (k = 0; k < 3; ++k) {
				if (as[i] == cs[k]) {
					if (i == k) {
						++strike;
					}
					else {
						++ball;
					}
				}
			}
		}
		*ps = strike;
		*pb = ball;

	}
	if (mode == 4) {	// 대답듣기 : 다음 수를 예측
		// 스트라이크, 볼 개수를 전달 받는다...
		strike = *ps;
		ball = *pb;
		// 각 개수에 따라 예측하는 처리
	}
	return 0;
}

int user2(int mode, int arg, int *ps, int *pb) {
	static int answer = 0;
	int call;
	int strike, ball;
	char as[8] = { 0 };
	char cs[8] = { 0 };
	int i, k;

	strike = ball = 0;
	if (mode == 1) {	// 정답 정하기
		answer = rand() % 900 + 100;
	}
	if (mode == 2) {	// 부르기
						// 상대에게 부를 값을 반환한다...
		call = rand() % 900 + 100;
		return call;
	}
	if (mode == 3) {	// 대답하기 : 위치(배열)와 값 : 백,십,일
		itoa(answer, as, 10);
		itoa(arg, cs, 10);
		for (i = 0; i < 3; ++i) {
			for (k = 0; k < 3; ++k) {
				if (as[i] == cs[k]) {
					if (i == k) {
						++strike;
					}
					else {
						++ball;
					}
				}
			}
		}
		*ps = strike;
		*pb = ball;

	}
	if (mode == 4) {	// 대답듣기 : 다음 수를 예측
						// 스트라이크, 볼 개수를 전달 받는다...
		strike = *ps;
		ball = *pb;
		// 각 개수에 따라 예측하는 처리 : 지능형
	}
	return 0;
}

int main_base() {
	int caller=1;
	int strike, ball;
	int call;	// 상대에게 부르는 값
	strike = ball = 0;	// 개수 세기 : 0 초기화해둔다...
	// 정답 정하기
	user1(1,0,NULL,NULL);
	user2(1, 0, NULL, NULL);
	while (1) {
		if (caller == 1) {
			call = user1(2,0,NULL,NULL);	//부르기
			user2(3,call,&strike, &ball);	//대답하기
			user1(4,0,&strike,&ball);	//대답받기
		}
		else {
			call = user2(2, 0, NULL, NULL);	//부르기
			user1(3,call,&strike, &ball);	//대답하기
			user2(4,0,&strike,&ball);	//대답받기
		}
		printf("caller[%d] call[%d] -> S[%d],B[%d] \n",
			caller, call, strike, ball);
		getchar();	// 엔터친다...
		if (strike == 3) {
			// 종료 caller 가 맞추었다.
			break;
		}
		caller = (caller == 1) ? 2 : 1;
	}
	return 0;
}

int main() {
	int caller = 1;
	int strike, ball;
	int call;	// 상대에게 부르는 값
	int(*player[3])(int, int, int*, int*) = {NULL,user1,user2};
	// 매개변수가 다르면 에러 : callback
	// 배열에 요소가 함수 ?? 함수의 주소
	strike = ball = 0;	// 개수 세기 : 0 초기화해둔다...
						// 정답 정하기
	user1(1, 0, NULL, NULL);
	user2(1, 0, NULL, NULL);
	while (1) {
		call = player[caller](2, 0, NULL, NULL);	//부르기
		player[ 3-caller ](3, call, &strike, &ball);	//대답하기
		player[caller](4, 0, &strike, &ball);	//대답받기
		printf("caller[%d] call[%d] -> S[%d],B[%d] \n",
			caller, call, strike, ball);
		getchar();	// 엔터친다...
		if (strike == 3) {
			// 종료 caller 가 맞추었다.
			break;
		}
		caller = (caller == 1) ? 2 : 1;
	}
	return 0;
}