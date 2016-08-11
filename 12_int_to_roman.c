/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int number[] = {2000,1000, 900,500, 400, 200,100,  90, 50,  40,  20, 10,  9,   5,   4,   2,  1};
char *roman[] = {"MM", "M","CM","D","CD","CC","C","XC","L","XL","XX","X","IX","V","IV","II","I"};
char* intToRoman(int num) {
    int point = 0;
    char *result = malloc(sizeof(char) * 64);
    result[0] = '\0';
    while(num > 0){
        while(num >= number[point]){
            strcat(result, roman[point]);
            num -= number[point];
        }
        point++;
    }

    return result;
}

int main(){
    printf("%s", intToRoman(1));
}