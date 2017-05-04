/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
  if(prices == NULL) return 0;
  int sum = 0;
  for(int i = 0; i < pricesSize - 1; i++){
    if(prices[i + 1] > prices[i]) sum += prices[i + 1] - prices[i];
  }
  return sum;
}
