/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

void kmpTable(char *nums, int numsSize, int *table) {
    table[0] = 0;
    int i = 0;
    for(i = 1; i < numsSize; i++){
        if(nums[table[i - 1]] == nums[i]){
            table[i] = table[i - 1] + 1;
        } else {
            table[i] = 0;
        }
    }
}

int strStr(char* haystack, char* needle) {
    if(haystack == NULL || needle == NULL){
        return 0;
    }
    int l1, l2;
    l1 = strlen(haystack);
    l2 = strlen(needle);
    if(l2 > l1){
        return -1;
    }
    if(l1 == 0 || l2 == 0){
        return 0;
    }

    int *table = malloc(sizeof(int) * l2);
    kmpTable(needle, l2, table);
    int i, j;
    i = 0;
    bool flag;
    while(i <= l1 - l2){
        if(haystack[i] == needle[0]){
            j = 1; 
            flag = true;
            while(j < l2){
                if(haystack[i + j] != needle[j]){
                    flag = false;
                    i += (j - table[j - 1]);
                    break;
                } else {
                    j++;
                }
            }
            if(flag == true){
                return i;
            }
        } else {
            i++;
        }
    }
    return -1;
}

int main(){
    int n = strStr("mississippi", "issip");
    printf("%d", n);
    return 0;
}