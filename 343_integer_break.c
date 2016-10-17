/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int max(int x, int y){
    return x > y ? x : y;
}

int integerBreak(int n) {
    int *dp = malloc((1 + n) * sizeof(int));
    for(int i = 1; i <= n; i++){
        dp[i] = i - 1;
    }
    for(int i = 3; i <= n; i++){
        for(int j = 2; j < i - 1; j++ ){
            dp[i] = max(dp[i], (max(j, dp[j])) * (max(i - j, dp[i - j])));
        }
    }
    return dp[n];
}