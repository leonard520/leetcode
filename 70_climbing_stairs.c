/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int climbStairs(int n) {
    if(n == 0){
      return 0;
    } else if(n == 1){
      return 1;
    } else if(n == 2){
      return 2;
    } else {
      return climbStairs(n - 1) + climbStairs(n - 2);
    }

}

int main(){
  printf("%d", climbStairs(44));
  return 0;
}
