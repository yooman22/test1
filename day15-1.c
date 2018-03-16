#include "Simple.h"
#define SZMAX	20
int view(int psz[], int length);
int randomize(int psz[], int length);
int indexOfMin(int *psz, int length);
int indexOfMax(int *psz, int length);
int swap(int *a, int *b);
int bubbleSort(int psz[], int length);// 배열시작주소,길이
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
	// 삽입될 요소 위치를 찾는다....
	int i, k, temp;
	for (i = 1; i < length; ++i) {
		// [i] 옮길 요소의 번호
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
	// 부분 배열, 최소값의 위치를 찾아, 부분 배열 첫요소와 교환한다...
	int min;
	int i;	// [i] 부분 배열의 첫번째 [0]
	for (i = 0; i < length; ++i) {
		min = indexOfMin(psz + i, length - i);
		// 부분 배열에서의 [0]번은 [i]번으로 매핑
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
		printf("교환: %d \n", count);
	}// 요소 개수만큼 반복
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
	int minIndex = 0;//번 요소
	int i;
	for (i = minIndex+1; i < length; i++) {
		if (psz[i] < psz[minIndex]) {
			minIndex = i;
		}
	}
	return minIndex;
}
int indexOfMax(int *psz, int length) {
	int maxIndex = 0;//번 요소
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
	srand((unsigned int)time(NULL));// 상시 변경되는 값

	randomize(sz, SZMAX);// 테스트용 값들 저장
	view(sz, SZMAX);
	printf("min : %d \n", indexOfMin(sz, SZMAX));
	printf("max : %d \n", indexOfMax(sz, SZMAX));
//	swap(sz + min, sz + max);

	return 0;
}
