/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool isUgly(int num) {
  if(num <= 0) return false;
  while(num % 2 == 0){
    num /= 2;
  }
  while(num % 3 == 0){
    num /= 3;
  }
  while(num % 5 == 0){
    num /= 5;
  }
  return (num == 1) ? true : false;
}
