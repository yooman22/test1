#include "Simple.h"
#define SZMAX	20
int view(int psz[], int length);
int randomize(int psz[], int length);
int indexOfMin(int *psz, int length);
int indexOfMax(int *psz, int length);
int swap(int *a, int *b);
int bubbleSort(int psz[], int length);// �迭�����ּ�,����
int selectionSort(int psz[], int length);
int insertionSort(int psz[], int length);

int main() {
	int sz[SZMAX];
	randomize(sz, SZMAX);
	bubbleSort(sz, SZMAX);
	selectionSort(sz, SZMAX);
	insertionSort(sz, SZMAX);
	return 0;
}
int insertionSort(int psz[], int length) {
	// ���Ե� ��� ��ġ�� ã�´�....
	int i, k, temp;
	for (i = 1; i < length; ++i) {
		// [i] �ű� ����� ��ȣ
		k = i - 1;
		temp = psz[i];
		while (k>=0 && psz[k]>temp) {
			psz[k + 1] = psz[k];
			--k;
		}
		psz[k+1] = temp;
		view(psz, SZMAX);
	}
	return 0;
}
int selectionSort(int psz[], int length) {
	// �κ� �迭, �ּҰ��� ��ġ�� ã��, �κ� �迭 ù��ҿ� ��ȯ�Ѵ�...
	int min;
	int i;	// [i] �κ� �迭�� ù��° [0]
	for (i = 0; i < length; ++i) {
		min = indexOfMin(psz + i, length - i);
		// �κ� �迭������ [0]���� [i]������ ����
		swap(psz + i, psz + i + min);
		view(psz, length);
	}
	return 0;
}
int bubbleSort(int psz[], int length) {
	int i, k;
	int count = 0;
	for (k = 0; k < length; k++) {
		for (i = 0; i < length - 1; ++i) {
			if (psz[i] > psz[i + 1]) {
				swap(psz + i, psz + (i + 1));
				count++;
			}
		}
		view(psz, length);
		printf("��ȯ: %d \n", count);
	}// ��� ������ŭ �ݺ�
	return 0;
}
int swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int indexOfMin(int *psz, int length) {
	int minIndex = 0;//�� ���
	int i;
	for (i = minIndex+1; i < length; i++) {
		if (psz[i] < psz[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}
int indexOfMax(int *psz, int length) {
	int maxIndex = 0;//�� ���
	int i;
	for (i = maxIndex + 1; i < length; i++) {
		if (psz[i] > psz[maxIndex]) {
			maxIndex = i;
		}
	}
	return maxIndex;
}

int view(int psz[], int length) {
	if (length < 1) {
		printf("\n");
		return 0;
	}
	printf("%3d ", *psz);	// psz[0]
	view(psz + 1, length - 1);
	return 0;
}
int randomize(int psz[], int length) {
	if (length < 1) {
		return 0;
	}
	psz[0] = rand() % 99 + 1;
	randomize(psz + 1, length - 1);
	return 0;
}



int main_1() {
	int sz[SZMAX];
	int min, max;
	srand((unsigned int)time(NULL));// ��� ����Ǵ� ��

	randomize(sz, SZMAX);// �׽�Ʈ�� ���� ����
	view(sz, SZMAX);
	printf("min : %d \n", indexOfMin(sz, SZMAX));
	printf("max : %d \n", indexOfMax(sz, SZMAX));
//	swap(sz + min, sz + max);

	return 0;
}
