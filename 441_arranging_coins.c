/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int arrangeCoins(int n) {
  int x = 1;
  while((1 + x) * x / 2 <= n){
    x++;
  }
  return --x;
}
