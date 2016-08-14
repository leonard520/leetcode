/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

char *dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int append(char **result, int digit, int length){
    int i, j;
    for(i = 0; i < length; i++){
        //printf("%lu--", strlen(dict[digit - 2]));
        for(j = 1; j < strlen(dict[digit - 2]); j++){
            result[length * j + i] = malloc(sizeof(char) * 8);
            memcpy(result[length * j + i], result[i], strlen(result[i]) + 1);
            //printf("%d\t", length * j + i);
        }
    }
    //printf("\n");
    for(i = 0; i < strlen(dict[digit - 2]); i++){
        for(j = 0; j < length; j++){
            char *s = malloc(sizeof(char) * 2);
            s[0] = dict[digit - 2][i];
            s[1] = '\0';
            strcat(result[length * i + j], s);
            //printf("%d, %d, %d\t", length * i + j, i, j);
            free(s);
        }
    }
    return (length * strlen(dict[digit - 2]));
}
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    if(digits == NULL || *digits == '\0') {
        return NULL;
    }
    char **result = malloc(sizeof(int) * 512);
    result[0] = malloc(sizeof(char) * 8);
    result[0][0] = '\0';
    int n = strlen(digits);
    int length = 1;
    for(int i = 1; i <= n; i++){
        int digit = (int)*digits - 48;
        length = append(result, digit, length); 
        digits++;
    }
    /*
    printf("%d\n", length);
    for(int i = 0; i < length; i++)
        printf("%s\n", result[i]);
    */
    *returnSize = length;
    return result;
}

int main(){
    char *array = "2";
    int *returnSize = malloc(sizeof(int));
    char **result = letterCombinations(array, returnSize);
    for(int i = 0; i < *returnSize; i++)
        printf("%s\n", result[i]);

    return 0;
}