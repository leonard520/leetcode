/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define INT_MAX 2147483647

int leastBricks(int** wall, int wallRowSize, int *wallColSizes) {
  if(wall == NULL) return 0;
  int width = 0;
  for(int i = 0; i < wallColSizes[0]; i++){
    width += wall[0][i];
  }

  int **flag = malloc(sizeof(int *) * wallRowSize);
  for(int i = 0; i < wallRowSize; i++){
    flag[i] = malloc(sizeof(int) * width);
    memset(flag[i], 0, sizeof(int) * width);
  }
  for(int i = 0; i < wallRowSize; i++){
    width = 0;
    for(int j = 0; j < wallColSizes[i] - 1; j++){
      width += wall[i][j];
      flag[i][width] = 1;
    }
  }
  int max = INT_MAX;

  for(int i = 1; i < width; i++){
    int tmp = 0;
    for(int j = 0; j < wallRowSize - 1; j++){
      tmp += flag[j][i] == 1 ? 0 : 1;
    }
    if(tmp < max) max = tmp;
  }
  return max;
}
