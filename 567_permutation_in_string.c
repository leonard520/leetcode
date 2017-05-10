/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool isZero(int d[]){
  for(int j = 0; j < 26; j++){
    if(d[j] != 0){
      return false;
    }
  }
  return true;
}

bool checkInclusion(char* s1, char* s2) {
  if(s2 == NULL) return false;
  if(s1 == NULL) return true;
  int l1 = strlen(s1);
  int l2 = strlen(s2);
  if(l1 > l2) return false;

  int dict[26];
  memset(dict, 0, sizeof(int) * 26);
  for(int i = 0; i < l1; i++){
    dict[s1[i] - 'a']++;
  }
  for(int i = 0; i < l1; i++){
    dict[s2[i] - 'a']--;
  }
  for(int i = l1; i < l2; i++){
    if(isZero(dict) == true){
      return true;
    }
    dict[s2[i] - 'a']--;
    dict[s2[i - l1] - 'a']++;
  }
  return isZero(dict);
}
