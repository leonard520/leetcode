/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int func(long dividend, long divisor) {
    int i = 0;    

    while(i < 31 && dividend >= divisor){
        divisor <<= 1;
        i++;
    }
    return i - 1;
}

int divide(int dividend, int divisor) {
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)){
        return INT_MAX;
    }
    int sign = (dividend < 0 ^ divisor < 0) ? -1 : 1;
    long d1 = labs((long)dividend);
    long d2 = labs((long)divisor);
        printf("%ld\n", d1);
    if(divisor == 1 || divisor == -1){
        return d1 * sign;
    }
    long t = d1;
    int i = 0;
    int result = 0;
    while(t >= d2){
        i = func(t, d2);
        t -= (d2 << i);
        result |= (1 << i);
    }
    return result * sign;
}

int main(){
    int i = divide(2147483647,2);
    printf("%d\n", i);
    return 0;
}