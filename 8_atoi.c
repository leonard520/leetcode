/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int myAtoi(char* str) {
    if(str == NULL){
        return 0;
    }
    while (*str == ' ')
        str++;
    int sign = 1;
    int result = 0;
    if(*str == '-'){
        sign = -1;
        str++;
    } else if(*str == '+'){
        str++;
    }
    while(*str != '\0'){
        int bit = (int)(*str) - 48;
        if( bit >= 0 &&  bit < 10){
            if(sign == 1){
                if(result > (INT_MAX - bit) / 10){
                    return INT_MAX;
                }
            } else {
                if(result * sign < (INT_MIN + bit)/10){
                    return INT_MIN;
                }
            }

            result = result * 10 + bit;
            str++;
        } else {
            return result * sign;
        }
    }
    return result * sign;
}

int main(){
    char s[] = {' ', '+','1','0','\0'};
    printf("%d", myAtoi(s));
    return 0;
}