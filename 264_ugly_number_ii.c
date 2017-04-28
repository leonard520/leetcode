/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MIN(a,b) (a) < (b) ? (a) : (b)
#define N 2048
int nthUglyNumber(int n) {
  int r[N];
  memset(r, 0, sizeof(int) * N);
  int k1, k2, k3;
  k1 = k2 = k3 = 0;
  r[0] = 1;
  for(int i = 1; i < n; i++){
    r[i] = MIN(MIN(r[k1] * 2, r[k2] * 3), r[k3] * 5);
    if(r[i] == r[k1] * 2) k1++;
    if(r[i] == r[k2] * 3) k2++;
    if(r[i] == r[k3] * 5) k3++;
  }
  return r[n - 1];
}
