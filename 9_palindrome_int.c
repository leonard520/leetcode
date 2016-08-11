/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

bool isPalindrome(int x) {
    if(x < 0) return false;
    int tmp = x;
    int count = 0;
    while(tmp){
        tmp /= 10;
        count++;
    }
    for(int i = 0; i < count / 2; i++){
        if(((int)(x / pow(10, i)) % 10 ) != ((int)(x / pow(10, count - i - 1)) % 10 )){
            return false;
        }
    }
    return true;
}

int main(){
    printf("%d", isPalindrome(1232));
    return 0;
}