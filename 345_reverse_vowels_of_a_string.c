/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

char* reverseVowels(char* s) {
    if(s == NULL){
        return NULL;
    }
    int m = strlen(s);
    int dict[256];
    memset(dict, 0, 256 * sizeof(int));
    dict['a'] = 1, dict['A'] = 1;
    dict['e'] = 1, dict['E'] = 1;
    dict['i'] = 1, dict['I'] = 1;
    dict['o'] = 1, dict['O'] = 1;
    dict['u'] = 1, dict['U'] = 1;
    int start = 0, end = m - 1;
    while(start < end){
      while(start < end && dict[s[start]] == 0) start++;
      while(end > start && dict[s[end]] == 0) end--;
      if(start < end) swap(&s[start], &s[end]);
      start++;
      end--;
    }
    return s;
}

int main(){
  char *s ="hello";
  printf("%s\n", reverseVowels(s));
}
