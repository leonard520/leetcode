/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647
#define MIN(a,b) (a) < (b) ? (a) : (b)
#define N 100000

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
  int r[N];
  memset(r, 0, sizeof(int) * N);
  r[0] = 1;
  int k[primesSize];
  memset(k, 0, sizeof(int) * primesSize);

  for(int i = 1; i < n; i++){
    int min = r[k[0]] * primes[0];
    int index = 0;
    for(int j = 1; j < primesSize; j++){
      int tmp = r[k[j]] * primes[j];
      if(tmp < min){
        min = tmp;
      }
    }
    printf("%d min %d\n", i, min);
    r[i] = min;
    for(int j = 0; j < primesSize; j++){
      if(min == r[k[j]] * primes[j]){
        k[j]++;
        printf("%d ++ %d\n", j, k[j]);
      }
    }
  }
  return r[n - 1];
}
