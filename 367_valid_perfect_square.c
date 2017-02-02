/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool isPerfectSquare(int num) {
  long x = num;
  while(x * x > num){
    x = (x + num / x) / 2;
  }
  return (x * x == num);
}

int main() {
  printf("%d", isPerfectSquare(808201));
  return 0;
}
