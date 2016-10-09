/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

int numTrees(int n) {
    if(n == 0 || n == 1) return n + 1;
    int sum = 0;
    for(int i = 0; i < n; i++){
        int left = numTrees(i);
        int right = numTrees(n - i - 1);
        sum += left * right;
    }
    return sum;
}