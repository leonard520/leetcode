/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define POW2(x) (x) * (x)

int mySqrt(int x) {
    int high = x;
    int low = 0;
    int mid = x / 2;
    while(true){
        if(POW2(mid) < x){
            low = mid + 1;
            mid = (high + mid + 1) / 2;
        } else if(POW2(mid) == x){
            return mid;
        } else if(POW2(mid - 1) > x){
            high = mid - 1;
            mid = (low + mid - 1) / 2;
        } else {
            return mid - 1;
        }
    }
}

int main(){
    for(int i = 0; i < 100; i++){
        printf("%d: %d\n", i, mySqrt(i));
    }
}