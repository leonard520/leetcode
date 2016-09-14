/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)
int maxProfit(int* prices, int pricesSize) {
    int i = 0, start = 0;
    int max = 0;
    for(i = 1; i < pricesSize; i++){
        
        if(prices[i] - prices[start] > 0){
            max = MAX(max, prices[i] - prices[start]);
        } else {
            start = i;
        }
    }
    return max;
}