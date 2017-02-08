/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

void findOnesAndZeroes(char *s, int *m, int *n){
  *m = 0;
  *n = 0;

  if(s == NULL){
    return;
  }

  int len = strlen(s);
  for(int i = 0; i < len; i++){
    if(s[i] == '0'){
      (*m)++;
    } else if(s[i] == '1'){
      (*n)++;
    }
  }
}

int findMaxForm(char** strs, int strsSize, int m, int n) {
  if(strs == NULL || strsSize == 0){
    return 0;
  }
  int map[m + 1][n + 1];
  memset(map, 0, (m + 1) * (n + 1) * sizeof(int));
  int *mm = malloc(sizeof(int));
  int *nn = malloc(sizeof(int));
  for(int i = 0; i < strsSize; i++){
    findOnesAndZeroes(strs[i], mm, nn);
    for(int j = m; j >= *mm; j--){
      for(int k = n; k >= *nn; k--){
        map[j][k] = MAX(map[j][k], map[j - (*mm)][k - (*nn)] + 1);
      }
    }

  }
  return map[m][n];
}

int main(){
  char **a = {"10", "0", "1"};
  printf("%d", findMaxForm(a, 1, 1));
}
