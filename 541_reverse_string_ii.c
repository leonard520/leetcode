/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void reverseStrInternal(char* s, int start, int end) {
  char tmp;
  for(int i = start; i < start + (end - start) / 2 + 1; i++){
    tmp = s[i];
    s[i] = s[end - i + start];
    s[end - i + start] = tmp;
  }
}

char* reverseStr(char* s, int k) {
  if(s == NULL || k <= 0){
    return s;
  }
  int len = strlen(s);
  int end = k - 1;
  for(int i = 0; i < len; i += 2 * k){
    end = (end < len - 1) ? end : len - 1;
    reverseStrInternal(s, i, end);
    end += 2 * k;
  }
  return s;
}
