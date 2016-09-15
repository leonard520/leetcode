/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char* convertToTitle(int n) {
    char *result = malloc(sizeof(char) * 1024);
    int i = 0;
    
    while(n > 0){
        n--;
        result[i++] = n % 26 + 'A';
        n /= 26;
    }
    result[i] = '\0';

    for(int j = 0; j < i / 2; j++){
        char tmp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = tmp;
    }
    return result;
}