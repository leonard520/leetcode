/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int uniquePaths(int m, int n) {
  if(m == 1 && n == 1){
    return 1;
  }
  int r[m][n];
  int i = 0, j = 0;
  for(i = 1; i < m; i++){
    r[i][0] = 1;
  }
  for(i = 1; i < n; i++){
    r[0][i] = 1;
  }
  r[0][0] = 0;
  for(i = 1; i < m; i++){
    for(j = 1; j < n; j++){
      r[i][j] = r[i - 1][j] + r[i][j - 1];
    }
  }

  return r[m - 1][n - 1];
}

int main(){
  printf("%d\n", uniquePaths(1, 2));
}
