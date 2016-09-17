/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool isIsomorphic(char* s, char* t) {
    if(s == NULL && t == NULL) return true;
    else if(s == NULL || t == NULL) return false;
    int m = strlen(s);
    int n = strlen(t);
    if(m != n) return false;
    char *array = malloc(sizeof(char) * 102400);
    char *array2 = malloc(sizeof(char) * 102400);
    int *dict = malloc(sizeof(int) * 256);
    memset(array, -1, sizeof(char) * 102400);
    memset(array2, -1, sizeof(char) * 102400);
    memset(dict, -1, sizeof(int) * 256);
    int i = 0;
    int j = 1;
    for(; i < m; i++){
        if(dict[s[i]] == -1){
            dict[s[i]] = j;
            array[i] = j;
            j++;
        } else {
            array[i] = dict[s[i]];
        }
    }
    memset(dict, -1, sizeof(int) * 256);
    i = 0;
    j = 1;
    for(; i < n; i++){
        if(dict[t[i]] == -1){
            dict[t[i]] = j;
            array2[i] = j;
            j++;
        } else {
            array2[i] = dict[t[i]];
        }
    }
    for(i = 0; i < 102400; i++){
        if(array2[i] != array[i]){
            return false;
        }
    }
    return true;
}