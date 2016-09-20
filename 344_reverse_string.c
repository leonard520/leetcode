/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

char* reverseString(char* s) {
    if(s == NULL){
        return NULL;
    }
    int m = strlen(s);
    for(int i = 0; i < m / 2; i++){
        char tmp = s[i];
        s[i] = s[m - i - 1];
        s[m - i - 1] = tmp;
    }
    return s;
}