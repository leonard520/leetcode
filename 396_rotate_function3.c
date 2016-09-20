/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int maxRotateFunction(int* A, int ASize) {
    if(A == NULL || ASize == 0) return 0;
    int sum = 0;
    int max = INT_MIN;
    int s = 0;
    for(int i = 0; i < ASize; i++){
        sum += i * A[i];
        s += A[i];
    }
    max = sum;
    for(int i = ASize - 1; i > 0; i--){
        sum += s;
        sum -= ASize * A[i];
        max = max > sum ? max : sum;
    }
    return max;
}

int main(){
    int A[] = {4, 3, 2, 6};
    printf("%d\n", maxRotateFunction(A, 4));
    return 0;
}