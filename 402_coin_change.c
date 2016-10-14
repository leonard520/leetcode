/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define INT_MAX 2147483647

int coinChange(int* coins, int coinsSize, int amount) {
    int *dp = malloc(sizeof(int) * ( 1 + amount));
	for(int i = 0; i <= amount; i++){
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
	for(int i = 1; i <= amount; i++){
		for(int j = 0; j < coinsSize; j++){
			printf("coin %d, %d\n", j, coins[j] );
			if(i >= coins[j] && dp[i - coins[j]] != INT_MAX){
				int tmp = dp[i - coins[j]] + 1;
				dp[i] = dp[i] < tmp ? dp[i] : tmp;
				printf("change to dp[i] = %d", dp[i]);
			}
		}
	}
	if(dp[amount] == INT_MAX){
		return -1;
	}
	return dp[amount];
}