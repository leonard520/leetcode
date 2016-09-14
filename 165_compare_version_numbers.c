/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int char2int(char *c, int start, int end){
    int sum = 0;
    int pow = 1;
    for(int i = end; i >= start; i--){
        sum += pow * c[i];
        pow *= 10; 
    }
    return sum;
}
int compareVersion(char* version1, char* version2) {
    int m = strlen(version1);
    int n = strlen(version2);
    int i = 0, j = 0;
    while(i < m && version1[i] != '.') i++;
    while(j < n && version2[j] != '.') j++;
    int v1 = char2int(version1, 0, i - 1);
    int v2 = char2int(version2, 0, j - 1);
    int v11 = 0, v12 = 0;
    if(i < m){
        v11 = char2int(version1, i + 1, m);
    }
    if(j < n){
        v12 =  char2int(version2, j + 1, n);
    }
    return v1 > v2 ? 1 : (v1 < v2 ? -1 : (v11 > v12 ? 1 : (v11 < v12 ? -1 : 0)));
}