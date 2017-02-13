/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int rangeBitwiseAnd(int m, int n) {
  int c = 0;
  while(m != n){
    m >>= 1;
    n >>= 1;
    c++;
  }
  return (m << c);
}
