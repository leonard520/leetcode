/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdio.h>

#ifndef _UTIL_H_ 
#define _UTIL_H_
void swap(int *a, int *b);
void quickSort(int* nums, int low, int high);
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define MIN(a,b) (a) < (b) ? (a) : (b)
#endif