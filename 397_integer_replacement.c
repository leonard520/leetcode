/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int integerReplacement(int n) {
    if(n == 1) return 0;
    if(n % 2 == 0) return 1 + integerReplacement(n / 2);
    else{
        int a = integerReplacement(n + 1);
        int b = integerReplacement(n - 1);
        return (a < b ? (a + 1) : (b + 1));
    }
}