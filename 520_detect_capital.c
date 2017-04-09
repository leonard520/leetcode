/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool detectCapitalUse(char* word) {
  if(word == NULL) return true;
  int n = strlen(word);
  if(n == 1) return true;
  int i = 0;
  if(word[0] >= 'A' && word[0] <= 'Z'){
    if(word[1] >= 'A' && word[1] <= 'Z'){
      i = 2;
      while(i < n){
        if(word[i] < 'A' || word[i] > 'Z'){
          return false;
        }
        i++;
      }
    } else{
      i = 2;
      while(i < n){
        if(word[i] < 'a' || word[i] > 'z'){
          return false;
        }
        i++;
      }
    }
  } else {
    i = 1;
    while(i < n){
      if(word[i] < 'a' || word[i] > 'z'){
        return false;
      }
      i++;
    }
  }
  return true;
}
