/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int hammingDistance(int x, int y) {
  int n = 0;
  int result = 0;
  for(int i = 0; i < 32; i++){
    if((x & (1 << n)) != (y & (1 << n))){
      result++;
    }
    n++;
  }
  return result;
}
