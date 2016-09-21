/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool isPowerOfFour(int num) {
    return (num > 0) && ((num & -num) == num) && ((num - 1 )% 3 == 0);
}