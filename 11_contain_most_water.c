/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

int maxArea(int* height, int heightSize) {
    int h, area, max;
    max = 0;
    for(int i = 0; i < heightSize - 1; i++){
        for(int j = i + 1; j < heightSize; j++){
            h = height[i] < height[j] ? height[i] : height[j];
            area = h * (j - i);
            max = area > max ? area:max;
        }
    }
    return max;
}