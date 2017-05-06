/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void reverseWordsInternal(char* s, int start, int end) {
  if(s == NULL) return;
  char tmp;
  for(int i = start; i < (end + start) / 2 + 1; i++){
    tmp = s[i];
    s[i] = s[end - i + start];
    s[end - i + start] = tmp;
  }
  return;
}

char* reverseWords(char* s) {
  if(s == NULL) return NULL;
  int len = strlen(s);
  int start = 0;
  int i = 0;
  for(i = 0; i < len; i++){
    start = i;
    while(i < len && s[i] != ' '){
      i++;
    }
    if(i >= len){
      break;
    }
    reverseWordsInternal(s, start, i - 1);
  }
  if(start != i){
    reverseWordsInternal(s, start, i - 1);
  }
  return s;
}
