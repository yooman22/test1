#include	"DnA.h"

int	Partition(int a[], int first, int last){
	int pivot;
	int i,j;
	pivot = a[last];	// ������ ����� ���� ���ذ����� ����
	i = first - 1;		// ���ĵ� ��� ��ȣ
	for(j=first;j<last;j++){	// ù��° ��ҿ�������
		if(a[j] <= pivot ){		// ���ذ����� ���� ��Ұ� ������ ����(i)���� �̵�(��ȯ) 
			++i;
			SWAP(a[i],a[j]);	
		}
	}
	//i�� ��ұ��� ���ذ� ���� ���� ������ �̵��� ���°� �ȴ�.
	SWAP(a[i+1],a[last]);
	return i+1;//	���ذ��� �̵��� ���
}

int QuickSort(int a[], int first, int last){
	int mid;
	printf("%d-%d:", first, last);PrintStep(a,10,first,last);
	if( first < last ){
		mid = Partition(a, first, last);
		QuickSort(a, first, mid-1);
		QuickSort(a, mid+1, last);
	}
	printf("%d-%d:", first, last);PrintStep(a,10,first,last);
	return 0;
}

int	Quick_Sort(int a[], int left, int right){
	int i,j;
	int pivot,t;
	if(left < right ){
		pivot = a[(left+right)/2];	// �߰� ��Ұ��� ���ذ����� ����
		i = left-1;
		j = right+1;
		while(1){
			while( a[++i] < pivot );
			while( a[--j] > pivot );
			if( i>=j )	break;	//i�� j �� ����(����)�Ǹ�
			t=a[i];	a[i] = a[j];	a[j] = t;
		}
		Quick_Sort(a, left, i-1);
		Quick_Sort(a, j+1, right);
	}
	return 0;
}
