/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isalphanumeric(char c){
    return (c >= 'A' && c <= 'Z') || ( c >= 'a' && c <= 'z') || ( c >= '0' && c <= '9');
}

bool isalphamine(char c){
    return (c >= 'A' && c <= 'Z') || ( c >= 'a' && c <= 'z');
}

bool isPalindrome(char* s) {
    if( s == NULL){
        return true;
    }   
    int n = strlen(s) - 1;
    int m = 0;
    bool flag = true;
    while(m < n){
        while(m < n && !isalphanumeric(s[m])) m++;
        while(n > m && !isalphanumeric(s[n])) n--;
        if(s[m] == s[n] 
            || (isalphamine(s[m]) && isalphamine(s[n]) && s[m] == s[n] + 'a' - 'A') 
            || (isalphamine(s[m]) && isalphamine(s[n]) && s[m] == s[n] + 'A' - 'a')){
            m++;
            n--;
        } else {
            flag = false;
            break;
        }
    }
    return flag;
}