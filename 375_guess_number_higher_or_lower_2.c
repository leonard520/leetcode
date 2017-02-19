/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(x,y) (x) < (y) ? (x) : (y)

int getMoneyAmountInternal(int **a, int s, int e){
	if(a[s][e] != 0){
		return a[s][e];
	} else if(s >= e){
		return 0;
	} else if(e - s <= 2){
		a[s][e] = e - 1;
		return e - 1;
	}
	int mid = (s + e)/2 - 1;
	int min = INT_MAX;
	for(int i = s + 1; i < e; i++){
		int s_mid = getMoneyAmountInternal(a, s, i - 1);
		int mid_e = getMoneyAmountInternal(a, i + 1, e);
		int tmp = i + (s_mid > mid_e ? s_mid : mid_e);
		min = MIN(min, tmp);
	}
	a[s][e] = min;
	return min;
}

int getMoneyAmount(int n) {
	int **a = malloc(sizeof(int *) * (n + 1));
	for(int i = 0; i < n + 1; i++){
		a[i] = malloc(sizeof(int) * (n + 1));
		memset(a[i], 0, sizeof(int) * (n + 1));
	}
	return getMoneyAmountInternal(a, 1, n);
}

int main(){
	printf("%d\n", getMoneyAmount(1));
	return 0;
}
