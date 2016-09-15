/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int trailingZeroes(int n) {
    int sum = 0;
    while(n > 0){
        sum += n / 5;
        n /= 5;
    }
    return sum;
}