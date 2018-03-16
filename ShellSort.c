#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "DnA.h"

int IntervalSort(int a[], int start, int sz, int interval){
	int i;
	int p;
	int temp;
	for(i=start+interval;i<sz;i+=interval){
		p = i;
		temp = a[i];
		while( p>0 && a[p-interval] > temp ){
			a[ p ] = a[p-interval];
			p-=interval;
		}
		a[p] = temp;
	}
	return 0;
}

int ShellSort(int base[], int n){
	int interval;
	int i;

	interval = n;
	while (interval >= 1){
		interval = interval / 2;
		for (i = 0; i < interval; i = i + 1) {
			IntervalSort(base, i, n, interval);
		}
	}
	return 0;
}
