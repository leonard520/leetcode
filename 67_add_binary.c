/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int binary2dec(char *a){
  if(a == NULL) return 0;
  int len = strlen(a);
  int sum = 0;
  int d = 1;
  for(int i = len - 1; i >= 0; i--){
    if(a[i] == '1'){
      sum += d;
    }
    d *= 2;
  }
  return sum;
}

char* dec2bin(int a){ 
  char *result = NULL;
  if(a == 0){
    result = malloc(sizeof(char) * 2);
    result[0] = '0';
    result[1] = '\0';
    return result;
  }
  int n = a;
  int count = 0;
  int i;
  while(n > 0){
    n /= 2;
    count++;
  }
  result = malloc(sizeof(char) * (count + 1));
  n = a;
  i = count - 1;
  while(n > 0){
    if(n % 2 == 0){
      result[i] = '0';
    } else {
      result[i] = '1';
    }
    i--;
    n /= 2;
  }
  result[count] = '\0';
  return result;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* addBinary(char* a, char* b) {
  if(a == NULL) return b;
  if(b == NULL) return a;
  return dec2bin(binary2dec(a) + binary2dec(b));
}

int main(){
  char *a = "0";
  printf("%s", dec2bin(0));
  return 0;
}
