/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool isPowerOfTwo(int n) {
    if(n <= 0){
        return false;
    }
    while(n >= 2){
        if(n & 1 != 0){
            return false;
        }
        n >>= 1;
    }
    return true;
}