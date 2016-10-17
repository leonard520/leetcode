/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define MAX(x,y) (x) > (y) ? (x) : (y)

int maxProfit(int* prices, int pricesSize) {
	if(prices == NULL || pricesSize == 0 || pricesSize == 1){
		return 0;
	}
    int *buy = malloc(sizeof(int) * pricesSize);
    int *sell = malloc(sizeof(int) * pricesSize);
    buy[0] = -prices[0];
    sell[0] = 0;
    int max = 0;
    for(int i = 1; i < pricesSize; i++){
    	sell[i] = MAX(buy[i - 1] + prices[i], sell[i - 1] - prices[i - 1] + prices[i]);
    	buy[i] = MAX(sell[i - 2] - prices[i], buy[i - 1] + prices[i - 1] - prices[i]);
    	max = sell[i] > max ? sell[i] : max;
    }
    return max;
}