/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isPalindrome(char *s, int start, int end){
    if(s == NULL){
        return true;
    }
    int n = end - start + 1;
    int middle = n / 2;
    for(int i = 0; i <= middle; i++){
        if(s[start + i] != s[end - i]){
            return false;
        }
    }
    return true;
}

char* longestPalindrome(char* s) {
    if(s == NULL){
        return NULL;
    }
    int n = strlen(s);
    int max = 0;
    int start, end;
    char* result = NULL;
    for(int i = 0; i < n; i++){
        int edge = (i > n - i - 1) ? n - i - 1: i;
        for(int j = 0; j <= edge; j++) {
            if(isPalindrome(s, i - j, i + j) == true){
                if(max < 1 + 2 * j){
                    start = i - j;
                    end = j + i;
                    max = 1 + 2 * j;
                }
            }
        }
    }
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            int edge = (i > n - i - 2) ? n - i - 2: i;
            for(int j = 0; j <= edge; j++) {
                if(isPalindrome(s, i - j, i + 1 + j) == true){
                    if(max < 2 + 2 * j){
                        start = i - j;
                        end = j + i + 1;
                        max = 2 + 2 * j;
                    }
                }
            }
        }
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
    printf("%s", longestPalindrome("abb"));
    return 0;
}