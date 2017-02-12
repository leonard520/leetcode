/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool makeString(bool b[], char *c){
  int n = 0;
  for(int i = 0; i < 4; i++){
    n += (b[i] * (1 << i));
  }
  int m = 0;
  for(int i = 0; i < 6; i++){
    m += (b[i + 4] * (1 << i));
  }
  if(n >= 12 || m >= 60){
    return false;
  }
  sprintf(c, "%d", n);
  strcat(c, ":");

  int zero = 0;
  if(n > 9){
    if(m <= 9){
      sprintf(c + 3, "%d", zero);
      sprintf(c + 4, "%d", m);
    } else {
      sprintf(c + 3, "%d", m);
    }
  } else {
    if(m <= 9){
      sprintf(c + 2, "%d", zero);
      sprintf(c + 3, "%d", m);
    } else {
      sprintf(c + 2, "%d", m);
    }
  }
  return true;
}

void fun(bool a[], int start, int count, int *returnSize, char **c){
  if(count == 0){
    if(makeString(a, c[*returnSize]) == true){
      (*returnSize)++;
    }
    return;
  }
  for(int i = start; i < 10 - count + 1; i++){
    a[i] = true;
    fun(a, i + 1, count - 1, returnSize, c);
    a[i] = false;
  }
}

int C(int n, int r){
  int result = 1;
  for(int i = n; i > n - r; i--){
    result *= i;
  }
  for(int i = 1; i <= r; i++){
    result /= i;
  }
  return result;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int num, int* returnSize) {
  if(num == 0){
    *returnSize = 1;
    char** c = malloc(sizeof(char *));
    for(int i = 0; i < 1; i++){
      c[i] = malloc(sizeof(char ) * 6);
      c[0] = "0:00";
    }
    return c;
  }

  bool a[10];
  memset(a, 0, sizeof(bool) * 10);

  *returnSize = 0;
  int total = C(10, num);
  char** c = malloc(sizeof(char *) * total);
  for(int i = 0; i < total; i++){
    c[i] = malloc(sizeof(char ) * 6);
  }
  fun(a, 0, num, returnSize, c);
  return c;
}

int main(){
  int *returnSize = malloc(sizeof(int));
  memset(returnSize, 0, sizeof(int));
  readBinaryWatch(1, returnSize);
}
