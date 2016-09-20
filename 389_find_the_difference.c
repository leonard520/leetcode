/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

char findTheDifference(char* s, char* t) {
    if(s == NULL && t == NULL){
        return true;
    } else if(s == NULL || t == NULL){
        return false;
    } 
    int m = strlen(s);
    int *a = malloc(sizeof(int) * 26);
    int *b = malloc(sizeof(int) * 26);
    memset(a, 0, sizeof(int) * 26);
    memset(b, 0, sizeof(int) * 26);
    int i;
    for(i = 0; i < m; i++){
        a[s[i] - 'a']++;
    }
    for(i = 0; i < m + 1; i++){
        b[t[i] - 'a']++;
    }
    for(i = 0; i < 26; i++){
        if(a[i] != b[i]){
            return i + 'a';
        }
    }
    return 'a';
}