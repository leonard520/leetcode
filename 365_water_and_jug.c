/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int gcd(int m, int n){
    if(n > m) return gcd(n, m);
    if(n == 0) return m;
    return gcd(n, m % n);
}
bool canMeasureWater(int x, int y, int z) {
    if(z == 0) return true;
    if(z > x + y) return false;
    return z % gcd(x, y) == 0;
}
