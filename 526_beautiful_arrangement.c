/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int countArrangementInternal(int current, int n, int array[]){
  if(current == n) {
    return 1;
  }
  int sum = 0;
  for(int j = 0; j < n; j++){
    if(array[j] == 1){
      continue;
    }
    int a = j + 1;
    int b = current + 1;
    if(a % b == 0 || b % a == 0){
      array[j] = 1;
      sum += countArrangementInternal(current + 1, n, array);
      array[j] = 0;
    }
  }
  return sum;
}

int countArrangement(int N) {
  if(N <= 0) return 1;
  int array[N];
  for(int i = 0; i < N; i++){
    array[i] = 0;
  }
  return countArrangementInternal(0, N, array);
}

int main(){
  countArrangement(2);
  return 0;
}
