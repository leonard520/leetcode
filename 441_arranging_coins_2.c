/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int arrangeCoins(int n) {
  if(n == 0) return 0;
  long a = sqrt(1 + 8 * (long)n);
  long x = (-1 + a)/2 - 2;
  while((1 + x) * x / 2 <= (long)n){
    x++;
  }
  return (--x);
}

int main(){
  printf("%d\n", arrangeCoins(1804289383));
}
