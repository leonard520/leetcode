/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

typedef struct {
  int matrixRowSize;
  int matrixColSize;
  int** matrix;
} NumMatrix;

NumMatrix* numMatrixCreate(int** matrix, int matrixRowSize, int matrixColSize) {
  if(matrix == NULL){
    return NULL;
  }
  int i, j;
  NumMatrix* m = malloc(sizeof(NumMatrix));
  m->matrix = malloc(sizeof(int *) * matrixRowSize);
  for(i = 0; i < matrixRowSize; i++){
    m->matrix[i] = malloc(sizeof(int) * matrixColSize);
  }

  m->matrix[0][0] = matrix[0][0];
  for(i = 1; i < matrixRowSize; i++){
    m->matrix[i][0] += matrix[i][0] + m->matrix[i - 1][0];
  }
  for(j = 1; j < matrixColSize; j++){
    m->matrix[0][j] += matrix[0][j] + m->matrix[0][j - 1];
  }
  for(i = 1; i < matrixRowSize; i++){
    for(j = 1; j < matrixColSize; j++){
      m->matrix[i][j] += m->matrix[i - 1][j] + m->matrix[i][j - 1] + matrix[i][j] - m->matrix[i - 1][j - 1];
    }
  }
  for(i = 0; i < matrixRowSize; i++){
    for(j = 0; j < matrixColSize; j++){
      printf("%d ", m->matrix[i][j]);
    }
    printf("\n");
  }
  return m;
}

int numMatrixSumRegion(NumMatrix* obj, int row1, int col1, int row2, int col2) {
  if(row1 == 0 && col1 == 0){
    return obj->matrix[row2][col2];
  } else if(row1 == 0){
    return obj->matrix[row2][col2] - obj->matrix[row2][col1 - 1];
  } else if(col1 == 0){
    return obj->matrix[row2][col2] - obj->matrix[row1 - 1][col2];
  } else {
    return obj->matrix[row2][col2] - obj->matrix[row2][col1 - 1] - obj->matrix[row1 - 1][col2] + obj->matrix[row1 - 1][col1 - 1];
  }
}

void numMatrixFree(NumMatrix* obj) {
  free(obj->matrix);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * struct NumMatrix* obj = numMatrixCreate(matrix, matrixRowSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 * numMatrixFree(obj);
 */

3 0 1 4 2
5 6 3 2 1
1 2 0 1 5
4 1 0 1 7
1 0 3 0 5
