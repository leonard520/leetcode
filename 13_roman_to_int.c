/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int romanToInt(char* s) {
    int result = 0;
    while(*s){
        if(*s == 'M'){
            result += 1000;
        } else if(*s == 'C'){
            if(*(s + 1) == 'M'){
                result += 900;
                *s++;
            } else if(*(s + 1) == 'D'){
                result += 400;
                *s++;
            } else {
                result += 100;
            }
        } else if(*s == 'D'){
            result += 500;
        } else if(*s == 'X'){
            if(*(s + 1) == 'C'){
                result += 90;
                *s++;
            } else if(*(s + 1) == 'L'){
                result += 40;
                *s++;
            } else {
                result += 10;
            }
        } else if(*s == 'L'){
            result += 50;
        } else if(*s == 'I'){
            if(*(s + 1) == 'X'){
                result += 9;
                *s++;
            } else if(*(s + 1) == 'V'){
                result += 4;
                *s++;
            } else {
                result += 1;
            }
        } else if(*s == 'V'){
            result += 5;
        }
        *s++;
    }

    return result;
}

int main(){
    printf("%s", intToRoman(1));
}