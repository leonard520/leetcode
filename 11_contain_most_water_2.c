/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */

int maxArea(int* height, int heightSize) {
    int area, h, max = 0;
    int i, j;
    i = 0;
    j = heightSize - 1;
    while(i < j){
        h = height[i] < height[j] ? height[i] : height[j];
        area = h * (j - i);
        max = max > area ? max : area;
        while(i < j && height[i] <= h) i++;
        while(j > i && height[j] < h) j--;
    }
    return max;
}