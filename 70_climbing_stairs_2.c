/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int climbStairs(int n) {
  if(n <= 2){
    return n;
  }
  int a, b, c;
  a = 1;
  b = 2;
  for(int i = 0; i < n - 2; i++){
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}

int main(){
  printf("%d", climbStairs(44));
  return 0;
}
