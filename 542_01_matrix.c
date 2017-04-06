/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647
#define MIN(a,b) (a) < (b) ? (a) : (b)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixRowSize, int *matrixColSizes, int** columnSizes, int* returnSize) {
  int **result = malloc(sizeof(int *) * matrixRowSize);
  int *columnSize = malloc(sizeof(int) * matrixRowSize);
  for(int i = 0; i < matrixRowSize; i++){
    columnSize[i] = matrixColSizes[i];
  }
  *columnSizes = columnSize;
  *returnSize = matrixRowSize;

  for(int i = 0; i < matrixRowSize; i++){
    result[i] = malloc(sizeof(int) * matrixColSizes[i]);
    for(int j = 0; j < matrixColSizes[i]; j++){
      result[i][j] = INT_MAX;
    }
  }
  int a, b;
  for(int i = 0; i < matrixRowSize; i++){
    for(int j = 0; j < matrixColSizes[i]; j++){
      if(matrix[i][j] == 0){
        result[i][j] = 0;
      } else {
        a = b = INT_MAX;
        if(i > 0) a = result[i - 1][j];
        if(j > 0) b = result[i][j - 1];
        if(a != INT_MAX || b != INT_MAX){
          result[i][j] = (MIN(a, b)) + 1;
        }
      }
      printf("%d, %d, %d\n", i, j, result[i][j]);
    }
  }
  for(int i = matrixRowSize - 1; i >= 0; i--){
    for(int j = matrixColSizes[i] - 1; j >= 0 ; j--){
      if(matrix[i][j] == 0){
        result[i][j] = 0;
      } else {
        a = b = INT_MAX;
        if(i < matrixRowSize - 1) a = result[i + 1][j];
        if(j < matrixColSizes[i] - 1) b = result[i][j + 1];
        if(a != INT_MAX || b != INT_MAX){
          result[i][j] = (MIN(a, b)) + 1;
        }
      }
      printf("%d, %d, %d\n", i, j, result[i][j]);
    }
  }

  return result;
}

int main() {
  /* code */
  return 0;
}
