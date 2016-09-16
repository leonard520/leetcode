/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
     n = n - ((n >> 1) & 0x55555555);
     n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
     return (((n + (n >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main(){
    printf("%d\n", hammingWeight(11));
    return 0;
}