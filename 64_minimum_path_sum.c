/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
  int i = 0, j = 0;
  int r[gridRowSize][gridColSize];
  memset(r, 0, sizeof(r));
  r[0][0] = grid[0][0];
  for(i = 1; i < gridRowSize; i++){
    r[i][0] += (grid[i][0] + r[i - 1][0]);
  }
  for(i =1; i < gridColSize; i++){
    r[0][i] += (grid[0][i] + r[0][i - 1]);
  }
  for(i = 1; i < gridRowSize; i++){
    for(j = 1; j < gridColSize; j++){
      r[i][j] = r[i - 1][j] < r[i][j - 1] ? (grid[i][j] + r[i - 1][j]) : (grid[i][j] + r[i][j - 1]);
    }
  }
  
  return r[gridRowSize - 1][gridColSize - 1];
}
