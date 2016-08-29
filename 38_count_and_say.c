/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char* countAndSay(int n) {
   char *resultArray = malloc(sizeof(char) * 102400);
   char *result = malloc(sizeof(char) * 102400);
   resultArray[0] = '1';
   resultArray[1] = '\0';
   char *tmp = resultArray;
   strcpy(result,resultArray);
   char cur;
   int len = 1;

    while(--n > 0)
    {
        resultArray = tmp;
        while(*result != '\0'){
        	cur = *result;
        	len = 1;
        	while(cur == *++result){
        		len++;
        	}
        	*resultArray++ = len + 48;
        	*resultArray++ = cur;
        }
        *resultArray = '\0';
        strcpy(result,tmp);
    } 
    return result;;
}