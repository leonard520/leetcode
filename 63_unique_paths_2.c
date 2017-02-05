/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
  if(obstacleGrid[0][0] == 1){
    return 0;
  }
  if(obstacleGridRowSize == 1 && obstacleGridColSize == 1 && obstacleGrid[0][0] != 1){
    return 1;
  }
  int r[obstacleGridRowSize][obstacleGridColSize];
  memset(r, 0, sizeof(r));
  int i = 0, j = 0;
  for(i = 1; i < obstacleGridRowSize; i++){
    if(obstacleGrid[i][0] == 0){
      r[i][0] = 1;
    } else {
      break;
    }
  }
  for(i = 1; i < obstacleGridColSize; i++){
    if(obstacleGrid[0][i] == 0){
      r[0][i] = 1;
    } else {
      break;
    }
  }
  for(i = 1; i < obstacleGridRowSize; i++){
    for(j = 1; j < obstacleGridColSize; j++){
      if(obstacleGrid[i][j] == 1){
        r[i][j] = 0;
      } else {
        r[i][j] = r[i - 1][j] + r[i][j - 1];
      }
    }
  }

  return r[obstacleGridRowSize - 1][obstacleGridColSize - 1];
}
