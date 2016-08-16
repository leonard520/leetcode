/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int count = 0;

void append(char **r, char *s, int left, int n){
    if(strlen(s) == 2 * n){
        printf("%d %s", count, s);
        r[count++] = s;
        return;
    }
    int length = strlen(s);
    if(left > length - left){
        if(left < n) {
            char *s2 = malloc(sizeof(char) * 32);
            memset(s2, '\0', 16);
            strcpy(s2, s);
            s[length] = '(';
            s[length + 1] = '\0';
            append(r, s, left + 1, n);
            s2[length] = ')';
            s2[length + 1] = '\0';
            append(r, s2, left, n);
        } else {
            s[length] = ')';
            s[length + 1] = '\0';
            append(r, s, left, n);
        }
    } else {
        s[length] = '(';
        s[length + 1] = '\0';
        append(r, s, left + 1, n);
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char **result = malloc(sizeof(int) * 4096);
    count = 0;
    char *s = malloc(sizeof(char) * 32);
    memset(s, '\0', 16);
    s[0] = '\0';
    append(result, s, 0, n);
    *returnSize = count;
    return result;
}

int main(){
    int *returnSize = malloc(sizeof(int));
    char **r = generateParenthesis(8, returnSize);

}