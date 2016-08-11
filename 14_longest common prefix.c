/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char* substr(char *src, int s, int l){
    printf("%s\n", src);
    if(src == NULL){
        return NULL;
    }
    while(s--) src++;
    src[l] = '\0';
    return src;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if(strs == NULL) return NULL;
    if(strsSize == 0) return "";
    if(strsSize == 1) return strs[0];
    int i, minLength = 0, index = 0;
    int *length = malloc(sizeof(int) * strsSize);
    minLength = length[0] = strlen(strs[0]);
    for(i = 1; i < strsSize; i++){
        length[i] = strlen(strs[i]);
        if(minLength > length[i]){
            minLength = length[i];
            index = i;
        }
    }
    for(i = 0; i < minLength; i++){
        for(int j = 1; j < strsSize; j++){
            if(strs[j][i] != strs[0][i]){
                return substr(strs[0], 0, i);
            }
        }
    }
    if((i == minLength)) return strs[index];
    return "";
}