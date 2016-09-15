/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int titleToNumber(char* s) {
    if(s == NULL){
        return 0;
    }
    int n = strlen(s);
    int sum = 0;
    int pow = 1;
    for(int i = n - 1; i >=0; i--){
        sum += (s[i] - 'A' + 1) * pow;
        pow *= 26;
    }
    return sum;
}