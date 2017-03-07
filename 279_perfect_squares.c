/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647
#define MIN(a,b) (a) < (b) ? (a) : (b)

int numSquares(int n) {
  if(n <= 0){
    return 0;
  }
  int *a = malloc((n + 1) * sizeof(int));
  a[0] = 0;
  for(int i = 1; i <= n; i++){
    a[i] = INT_MAX;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j * j <= i; j++){
      a[i] = MIN(a[i], a[i - j * j] + 1);
    }
  }
  return a[n];
}
