/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

void numIslandsInternal(char** grid, int i, int j, int m, int n){
  if(i < 0 || j < 0 || i >= m || j >= n || grid == '0'){
    return;
  }
  grid[i][j] = '0';
  numIslandsInternal(grid, i - 1, j, m, n);
  numIslandsInternal(grid, i, j - 1, m, n);
  numIslandsInternal(grid, i + 1, j, m, n);
  numIslandsInternal(grid, i, j + 1, m, n);
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
  if(grid == NULL){
    return 0;
  }

}
