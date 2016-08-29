/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int lengthOfLastWord(char* s) {
  if(s == NULL){
    return 0;
  }
  int length = 0;
  int last = 0;
  bool flag;
  while(*s != '\0'){
    if(*s != ' '){
      length++;
      flag = false;
    } else {
      last = length == 0 ? last : length;
      length = 0;
      flag = true;
    }
    s++;
  }
  return flag == true ? last:length;
}