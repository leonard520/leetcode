/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int addDigits(int num) {
    return num == 0 ? 0 : (num % 9 == 0 ? 9 : num % 9);
}