/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int char2int(char *c, int start, int end){
    int sum = 0;
    int pow = 1;
    for(int i = end; i >= start; i--){
        sum += pow * (c[i] - '0');
        pow *= 10;
    }
    return sum;
}
int compareVersion(char* version1, char* version2) {
    int m = strlen(version1);
    int n = strlen(version2);
    int i = 0, j = 0;
    int ii, jj;
    int flag = 0;
    while(flag == 0){
        ii = i; jj = j;
        if(i < m && j == n + 1){
            while(i < m){
                ii = i;
                while(i < m && version1[i] != '.') i++;
                printf("%d\n",char2int(version1, ii, i - 1));
                if(char2int(version1, ii, i - 1) != 0) return 1;
                i++;
            }
            return 0;
        }
        else if(i == m + 1 && j < n){
            while(j < n){
                jj = j;
                while(j < n && version2[j] != '.') j++;
                printf("%d\n",char2int(version2, jj, j - 1));
                if(char2int(version2, jj, j - 1) != 0) return -1;
                printf("%d\n",char2int(version2, jj, j - 1));
                j++;
            }
            return 0;
        } 
        else if(i == m + 1 && j == n + 1) return 0;
        while(i < m && version1[i] != '.') i++;
        while(j < n && version2[j] != '.') j++;
        int v1 = char2int(version1, ii, i - 1);
        int v2 = char2int(version2, jj, j - 1);
        flag = v1 > v2 ? 1 : (v1 < v2 ? -1 : 0);
        i++; j++;
    }
    return flag;
}

int main(){
    char *ver1 = "1.1";
    char *ver2 = "1.2";
    compareVersion(ver1, ver2);
    return 0;
}