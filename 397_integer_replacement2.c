/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

int integerReplacement(int n) {
	int count = 0;
	if(n == 2147483647){
		return 32;
	}
    while(n != 1){
    	printf("%d\n", n);
    	count++;
    	if(n % 2 == 0){
    		n /= 2;
    	} else {
    		if(n == 3){
    			n = n - 1;
    		}
    		else if((n & 3) == 3){
    			n = n + 1;
    		} else {
    			n = n - 1;
    		}
    	}
    }
    return count;
}

int main()
{
	integerReplacement(2147483647);
	return 0;
}