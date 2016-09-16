/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int countPrimes(int n) {
    bool array[n + 1];
    int count = 0;
    memset(array, true, sizeof(array));
    for(int i = 2; i < n; i++){
        if(array[i] == true){
            count++;
            int j = i * 2;
            while(j < n){
                array[j] = false;
                j += i;
            }
        }
    }
    return count;
}

int main(){
    printf("%d\n", countPrimes(1111));
    return 0;
}