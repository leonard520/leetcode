/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

char* reverseString(char* s) {
    if(s == NULL){
        return NULL;
    }
    int m = strlen(s);
    printf("%d", m);
    for(int i = 0; i < m / 2; i++){
        char tmp = s[i];
        s[i] = s[m - i - 1];
        s[m - i - 1] = tmp;
    }
    return s;
}

char* itoa(int a, char *s){
    if(s == NULL) return NULL;
    int i = 0;
    if(a == 0){
        s[i] = '0';
        i++;
    }
    while(a > 0){
        s[i] = a % 10 + '0';
        a /= 10;
        i++;
    }
    s[i] = '\0';
    reverseString(s);
    printf("%s\n", s);
    return s;
}

char* getHint(char* secret, char* guess) {
    int n = strlen(secret);
    char *result = malloc(sizeof(char) * 1024);
    char *str = malloc(sizeof(char) * 10);
    int i = 0, j = 0;
    int a = 0, b = 0;
    for(i = 0; i < n; i++){
        if(secret[i] == guess[i]){
            a++;
            guess[i] = '-';
            secret[i] = '-';
        }
    }
    for(i = 0; i < n; i++){
        if(guess[i] == '-') continue;
        for(j = 0; j < n; j++){
            if(guess[i] == secret[j]){
                b++;
                guess[i] = '-';
                secret[j] = '-';
                break;
            }
        }
    }
    printf("%d, %d", a, b);
    memset(str, 0, 10);
    strcat(result, itoa(a, str));
    strcat(result, "A");
    memset(str, 0, 10);
    strcat(result, itoa(b, str));
    strcat(result, "B");

    return result;
}

int main(){
    char str[10]; 
    printf("%s", itoa(17, str));
}