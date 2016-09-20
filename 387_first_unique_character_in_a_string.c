/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647

int firstUniqChar(char* s) {
    if(s == NULL) {
        return -1;
    }
    int m = strlen(s);
    int i, j;
    int *a = malloc(sizeof(int) * 26);
    memset(a, 0, sizeof(int) * 26);
    for(i = 0; i < m; i++){
        a[s[i] - 'a']++;
    }
    int min = INT_MAX;
    for(i = 0; i < 26; i++){
        if(a[i] == 1){
            for(j = 0; j < m; j++){
                if(s[j] == i + 'a'){
                    break;
                }
            }

            min = min < j ? min : j;
        }
    }
    return min == INT_MAX ? -1 : min;
}