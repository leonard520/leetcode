/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char* addBinary(char* a, char* b) {
  if(a == NULL) return b;
  if(b == NULL) return a;
  int l1 = strlen(a);
  int l2 = strlen(b);
  int l = l1 > l2 ? l1:l2;
  char *result = malloc(l + 1);
  memset(result, '\0', l + 1)
  int i = 0;
  int carry = 0;
  while(l1 && l2){
    if(a[l1 - 1] + b[l2 - 1] + carry == 96){
      result[i] = '0';
      carry = 0;
    } else if(a[l1 - 1] + b[l2 - 1] + carry == 97){
      result[i] = '1';
      carry = 0;
    } else if(a[l1 - 1] + b[l2 - 1] + carry == 98){
      result[i] = '0';
      carry = 1;
    } else if(a[l1 - 1] + b[l2 - 1] + carry == 99){
      result[i] = '1';
      carry = 1;
    }
    i++;
    l1--;
    l2--;
  }
  if(l1){
    while(l1){
      if(a[l1 - 1] + carry == 48){
        result[i] = '0';
        carry = 0;
      } else if(a[l1 - 1] + carry == 49){
        result[i] = '1';
        carry = 0;
      } else if(a[l1 - 1] + carry == 50){
        result[i] = '0';
        carry = 1;
      }
      i++;
      l1--;
    }
  }
  if(l2){
    while(l2){
      if(b[l2 - 1] + carry == 48){
        result[i] = '0';
        carry = 0;
      } else if(b[l2 - 1] + carry == 49){
        result[i] = '1';
        carry = 0;
      } else if(b[l2 - 1] + carry == 50){
        result[i] = '0';
        carry = 1;
      }
      i++;
      l2--;
    }
  }
  if(carry == 1){
    result[i++] = '1';
  }
  result[i] = '\0';
  l = strlen(result);
  for(int i = 0; i < l / 2; i++){
    char tmp = result[i];
    result[i] = result[l - 1 - i];
    result[l - 1 - i] = tmp;
  }
  return result;
}

int main(){

  char *a = "110011101101001101010001010100101000110101001011111101101101111011110100001000110010000110";
  char *b = "10011100000001101001000000011100100010110101011011110110100010";
  printf("%s", addBinary(a, b));
  return 0;
}
