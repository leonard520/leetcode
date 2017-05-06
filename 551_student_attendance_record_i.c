/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool checkRecord(char* s) {
  if(s == NULL) return false;
  int len = strlen(s);
  int a, l;
  a = l = 0;
  for(int i = 0; i < len; i++){
    if(s[i] == 'A') a++;
    else if(s[i] == 'L'){
      if(i < len - 1 && s[i + 1] == 'L'){
        if(i < len - 2 && s[i + 2] == 'L'){
          i += 2;
          l++;
        }
      }
    }
  }
  return (a <= 1 && l <=0);
}
