/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char* convert(char* s, int numRows) {
    if(s == NULL){
        return NULL;
    }
    int n = strlen(s);
    if(n <= numRows){
        return s;
    }
    if(numRows == 1){
        return s;
    }
    char *result = malloc(sizeof(char) * n + 1);
    int count = 0;
    for(int i = 0; i < numRows; i++){
        int tmp = i;
        result[count++] = s[i];
        if(i == 0 || i == numRows -1){
            tmp += 2 * numRows - 2;
            while(tmp < n){
                result[count++] = s[tmp];
                tmp += 2 * numRows - 2;
            }
        } else {
            bool odd = true;
            tmp += 2 * numRows - 2 - 2 * i;
            while(tmp < n){
                result[count++] = s[tmp];
                if(odd){
                    tmp += 2 * i;
                    odd = false;
                } else {
                    tmp += 2 * numRows - 2 - 2 * i;
                    odd = true;
                }
            }
        }
    }
    result[n] = '\0';
    return result;
}

int main(){
    printf("%s", convert("banana", 2));
    return 0;
}