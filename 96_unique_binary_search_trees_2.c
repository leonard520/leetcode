/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int numTrees(int n) {
    int *result = malloc(sizeof(int) * n);
    memset(result, 0, sizeof(int) * n);
    result[0] = 1;
    result[1] = 2;
    for(int i = 2; i < n; i++){
    	for(int j = 0; j <= i; j++){
    		if(j == 0 || j == i) result[i] += result[i - 1];
    		else result[i] += result[i - j - 1] * result[j - 1];
    	}
    }
    return result[n - 1];
}