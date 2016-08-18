/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void push(char *s, char c, int length){
    s[length] = c;
}

char pop(char *s, int length){
    return s[length - 1];
}
bool isValid(char* s) {
    if(s == NULL){
        return false;
    }
    int length = 0;
    char *stack = malloc(sizeof(char) * 1024);
    while(*s != '\0'){
        char c = *s;
        if(c == '[' || c == '{' || c == '('){
            push(stack, c, length);
            length++;
        } else if(c == ']'){
            if(length > 0 && pop(stack, length) == '['){
                length--;
            } else {
                return false;
            }
        } else if(c == '}'){
            if(length > 0 && pop(stack, length) == '{'){
                length--;
            } else {
                return false;
            }
        } else if(c == ')'){
            if(length > 0 && pop(stack, length) == '('){
                length--;
            } else {
                return false;
            }
        } 
        s++;
    }
    return length == 0 ? true : false;
}