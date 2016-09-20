/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

void rotate(int *array, int n){
    int tmp = array[n - 1];
    for(int i = n - 2; i >=0; i--){
        array[i + 1] = array[i];
    }
    array[0] = tmp;
}

int maxRotateFunction(int* A, int ASize) {
    if(A == NULL || ASize == 0) return 0;
    int i = 0, j = 0;
    int sum = 0;
    int max = INT_MIN;
    int *array = malloc(sizeof(int) * ASize);
    for(i = 0; i < ASize; i++){
        array[i] = i;
    }
    for(i = 0; i < ASize; i++){
        sum = 0;
        for(j = 0; j < ASize; j++){
            sum += j * A[array[j]];
        }
        max = max > sum ? max : sum;
        rotate(array, ASize);
    }
    return max;
}