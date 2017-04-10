/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int calculateInternal(char* s, int end) {
  int i = end;
  bool isMultiple = true;
  int cache = 0;
  int sum = 0;
  while(i >= 0){
    int num = 0;
    int base = 1;
    while(isdigit(s[i])){
      num += (s[i] - '0') * base;
      base *= 10;
      i--;
      sum = num;
    }
    if(cache != 0){
      num = (isMultiple == true) ? (num * cache) : (num / cache);
      sum = cache;
      cache = 0;
    }
    if(i < 0){
      return sum;
    }
    switch (s[i]) {
      case '+': return calculateInternal(s, i - 1) + num;
      case '-': return calculateInternal(s, i - 1) - num;
      case '*': isMultiple = true; break;
      case '/': isMultiple = false; break;
    }
    cache = num;
    i--;
  }
  return sum;
}

int calculate(char* s) {
  if(s == NULL) return 0;
  return calculateInternal(s, strlen(s) - 1);
}

int main(){
  char *s = "3+2*2";
  printf("%d\n", calculate(s));
  return 0;
}
