/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

bool isPalindrome(int x) {
    if(x == 0) return true;
    if(x < 0 || (x  % 10 == 0)) return false;
    int tmp = 0;
    while(x > tmp){
        tmp = tmp * 10 + x % 10;
        x /= 10;
    }
    return ((tmp == x) || (x == tmp / 10));
}

int main(){
    printf("%d", isPalindrome(10));
    return 0;
}