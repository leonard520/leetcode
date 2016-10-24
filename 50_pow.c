/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

double myPow(double x, int n) {
    if(n == 0) return 1;
    else if(n == 1) return x;
    else if(n == -1) return 1 / x;
    if(n % 2 == 0){
        double r = myPow(x, n / 2);
        return r * r;
    } else {
        double r = myPow(x, n / 2);
        return n > 0 ? (r * r * x) : (r * r / x);
    }
}