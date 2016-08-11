/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int reverse(int x) {
    int result = 0;
    while(x){
        int bit = x % 10;
        if(x > 0){
            if(result > (INT_MAX - bit) / 10)
                return 0;
        } else {
            if(result < (INT_MIN - bit)/10)
                return 0;
        }
        result *= 10;
        result += bit;
        x = x / 10;
    }
    return result;
}

int main(){
    printf("%d", reverse(1534236469));
    return 0;
}