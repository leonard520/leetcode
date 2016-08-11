/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char* longestPalindrome(char* s) {
    if(s == NULL){
        return NULL;
    }
    int n = strlen(s);
    if(n == 1){
        return s;
    }
    int max = 1;
    int point = 0;
    int start, end;
    char* result = NULL;
    while(point + max / 2 < n){
        int i = 1;
        while(s[point] == s[point + i]) i++;
        i--;
        int j = 1;

        while((point - j >= 0) && (point + i + j < n) && (s[point - j] == s[point + i + j])) j++;
        j--;
        if(max < i + 2 * j + 1){
            max = i + 2 * j + 1;
            start = point - j;
            end = point + i + j;
        }
        point = point + i + 1;
    }
    if(max != 0){
        result = malloc(sizeof(char) * max + 1);
        for(int i = 0; i < max; i++){
            result[i] = s[start + i];
        }
        result[max] = '\0';
    }
    return result;
}

int main(){
    printf("%s", longestPalindrome("banana"));
    return 0;
}