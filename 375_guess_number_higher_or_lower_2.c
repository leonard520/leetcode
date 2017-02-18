/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define MIN(x, y) (x) < (y) ? (x) : (y)

int getMoneyAmountInternal(int **a, int s, int e){
	if(a[s][e] != 0){
		return a[s][e];
	} else if(s >= e){
		return 0;
	} else if(e - s <= 2){
		return e - 1;
	}
	int mid = (s + e)/2 - 1;
	int min = INT_MAX;
	while(mid < e){
		int s_mid = getMoneyAmountInternal(a, s, mid - 1);
		int mid_e = getMoneyAmountInternal(a, mid + 1, e);
		min = MIN(min, mid + MIN(s_mid, mid_e));
		if (mid_e <= s_mid) break;
		mid++;
	}
	a[s][e] = min;
	return min;
}

int getMoneyAmount(int n) {
	int **a = malloc(sizeof(int *) * (n + 1));
	for(int i = 0; i < n; i++){
		a[i] = malloc(sizeof(int) * (n + 1));
	}
	return getMoneyAmountInternal(a, 1, n);
}

int main(){
	printf("%d\n", getMoneyAmount(1));
	return 0;
}
