/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
	int result = 0;
    for(int i = 0; i < 32; i++){
    	int shift = 31 - 2 * i;
    	if(shift > 0){
    		result += ((n & (1 << i)) << shift);
    	} else {
    		result += ((n & (1 << i)) >> (-shift));
    	}
    }
    return result;
}

int main(){
	uint32_t n = 1;
	printf("%d", 1 >> 2);
	printf("%d", reverseBits(43261596));
}