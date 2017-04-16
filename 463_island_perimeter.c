/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
  if(grid == NULL || gridRowSize == 0 || gridColSize == 0){
    return 0;
  }
  int ones = 0;
  int board = 0;
  for(int i = 0; i < gridRowSize; i++){
    for(int j = 0; j < gridColSize; j++){
      if(grid[i][j] == 1){
        ones++;
        if(i > 0 && grid[i - 1][j] == 1) board++;
        if(j > 0 && grid[i][j - 1] == 1) board++;
      }
    }
  }
  return ones * 4 - board * 2;
}
