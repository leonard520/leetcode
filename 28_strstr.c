/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>


int strStr(char* haystack, char* needle) {
    if(haystack == NULL || needle == NULL){
        return 0;
    }
    if(strlen(needle) > strlen(haystack)){
        return -1;
    }
    if(strlen(haystack) == 0 || strlen(needle) == 0){
        return 0;
    }
    int i, j;
    i = 0;
    bool flag;
    while(i <= strlen(haystack) - strlen(needle)){
        if(haystack[i] == needle[0]){
            j = 1; 
            flag = true;
            while(j < strlen(needle)){
                if(haystack[i + j] != needle[j]){
                    flag = false;
                    break;
                } else {
                    j++;
                }
            }
            if(flag == true){
                return i;
            }
        }
        i++;
    }
    return -1;
}