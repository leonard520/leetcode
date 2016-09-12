/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
	
    int i, j;
    *returnSize = rowIndex + 1;
    int *returnValue = malloc(sizeof(int) * (rowIndex + 1));

    int **result = malloc(sizeof(int *) * (1 + rowIndex));
    for(i = 0; i <= rowIndex; i++){
    	result[i] = malloc(sizeof(int) * (i + 1));
    }
    result[0][0] = 1;

    for(i = 1; i <= rowIndex; i++){
    	result[i][0] = result[i][i] = 1;
    	for(j = 1; j < i; j++){
    		result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
    	}
    }

    returnValue = result[rowIndex];
    return returnValue;
}

int main(){
	int numRows = 8;
	int** columnSizes = malloc(sizeof(int));
	int** result = generate(numRows, columnSizes);
	return 0;
}