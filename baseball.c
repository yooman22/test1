/*	�߱�����(���ڸ��߱�)
	���� ����
		��ġ(�ڸ�) ���� ++strike
		��ġ(�ڸ�) �ٸ��� ++ball;
	����� ��ġ�Ѵٸ� strike �� 3�̴�.(3�ڸ�)
	���� �� ���� ����� ����ϱ⸦ �ݺ��Ѵ�.
*/
#include "simple.h"

//ȣ�� �� �Ű������� ����, type �ٸ���....�Ϲ�ȭ
int user1(int mode, int arg,int *ps,int *pn) {
	static int answer = 0; //static ��������Ҷ��� �� �ʱ�ȭ�ؾߵ�.
	int call;
	int strike, ball;
	char as[8] = { 0 };
	char cs[8] = { 0 },
	int i, k;

	strike = ball = 0;
	if (mode == 1) {	//�������ϱ�
		answer = rand() % 900 + 100;
	}
	if (mode == 2) {	//�θ���
		//��뿡�� �θ� ���� ��ȯ�Ѵ�...
		call = rand() % 900 + 100;
		return call;
	}
	if (mode == 3) {	//����ϱ� : ��ġ(�迭)�� ��
		itoa(answer, as, 10);
		itoa(arg, as, 10);
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
	if (mode == 4) {	//����� : ���� ���� ����
		// ��Ʈ����ũ, �� ������ ���� �޴´�...
		strike = *ps;
		ball = *pb;
		//�� ������ ���� �����ϴ� ó��
	}
	return 0;
}

int user2() {
	static int answer = 0; //static ��������Ҷ��� �� �ʱ�ȭ�ؾߵ�.
	int call;
	int strike, ball;
	char as[8] = { 0 };
	char cs[8] = { 0 },
		int i, k;

	strike = ball = 0;
	if (mode == 1) {	//�������ϱ�
		answer = rand() % 900 + 100;
	}
	if (mode == 2) {	//�θ���
						//��뿡�� �θ� ���� ��ȯ�Ѵ�...
		call = rand() % 900 + 100;
		return call;
	}
	if (mode == 3) {	//����ϱ� : ��ġ(�迭)�� ��
		itoa(answer, as, 10);
		itoa(arg, as, 10);
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
	if (mode == 4) {	//����� : ���� ���� ����
						// ��Ʈ����ũ, �� ������ ���� �޴´�...
		strike = *ps;
		ball = *pb;
		//�� ������ ���� �����ϴ� ó��
	}
	return 0;
}

int main() {
	int caller=1;
	int strike, ball;
	int call; //��뿡�� �θ��� ��
	strike = ball = 0; //���� ���� : 0�ʱ�ȭ�صд�....
	// ���� ���ϱ�
	user1(1, 0, NULL, NULL);
	user2(1, 0, NULL, NULL);
	while (1) {
		if (caller == 1) {
			call = user1(2,0,NULL,NULL);	//�θ���
			user2(3,call,&strike, &ball);	//����ϱ�
			user1(4,0,&strike,&ball);	//���ޱ�
		}
		else {
			call = user2(2, 0, NULL, NULL);	//�θ���
			user1(3,call,&strike, &ball);	//����ϱ�
			user2(4,0,&strike,&ball);	//���ޱ�
		}
		if (strike == 3) {
			// ����
			break;
		}
		caller = (caller == 1) ? 2 : 1;
	}
	return 0;
}