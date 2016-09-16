/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

bool isHappy(int n) {
    while(n != 4){
        if(n == 1){
            return true;
        }
        int next = 0;
        while(n){
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        n = next;
    }
    return false;
}

int main(){
    isHappy(89);
}