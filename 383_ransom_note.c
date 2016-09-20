/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

bool canConstruct(char* ransomNote, char* magazine) {
    if(ransomNote == NULL && magazine == NULL){
        return true;
    } else if(ransomNote != NULL && magazine == NULL){
        return false;
    } 
    int m = strlen(ransomNote);
    int n = strlen(magazine);
    if(m > n) return false;
    int *a = malloc(sizeof(int) * 26);
    int *b = malloc(sizeof(int) * 26);
    memset(a, 0, sizeof(int) * 26);
    memset(b, 0, sizeof(int) * 26);
    int i;
     for(i = 0; i < m; i++){
        a[ransomNote[i] - 'a']++;
    }
    for(i = 0; i < n; i++){
        b[magazine[i] - 'a']++;
    }
    for(i = 0; i < 26; i++){
        if(a[i] > b[i]){
            return false;
        }
    }
    return true;
}