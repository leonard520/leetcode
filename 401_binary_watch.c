/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void fun(bool a[], int start, int count, int *returnSize, char **c){
  if(count == 0){
    (*returnSize)++;
    return;
  }
  for(int i = start; i < 10 - count + 1; i++){
    a[i] = true;
    fun(a, i + 1, count - 1, returnSize, c);
    a[i] = false;
  }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int num, int* returnSize) {
  if(num == 0){
    return NULL;
  }
  bool a[10];
  memset(a, 0, sizeof(bool) * 10);

  char** c = malloc(sizeof(char *));
  for(int i = 0; i < 252; i++){
    c[i] = malloc(sizeof(char ) * 6);
  }
  fun(a, 0, num, returnSize, c);
  printf("%d", *returnSize);
  return c;
}

int C(int n, int r){
  int result = 1;
  for(int i = n; i > n - r; i--){
    printf("m %d\n", i);
    result *= i;
  }
  for(int i = 1; i <= r; i++){
    printf("d %d\n", i);
    result /= i;
  }
  return result;
}

int main(){
  int *returnSize = malloc(sizeof(int));
  memset(returnSize, 0, sizeof(int));
  printf("%d\n", C(10, 6));
  readBinaryWatch(5, returnSize);
}
