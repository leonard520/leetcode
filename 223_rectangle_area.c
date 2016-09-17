/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    
    if(A == C && B == D){
        return (G - E) * (H - F);
    }
    if(E == G && F == H){
        return (C - A) * (D - B);
    }
    int x, y;
    if(A < E){
        x = C < E ? 0 : (G > C ? (C - E) : (G - E));
    } else {
        x = A > G ? 0 : (G > C ? (C - A) : (G - A));
    }
    x = x > 0 ? x : 0;
    if(D > H){
        y = H < B ? 0: (B > F ? (H - B) : (H - F));
    } else {
        y = F > D ? 0 : (B > F ? (D - B) : (D - F));
    }
    y = y > 0 ? y : 0;
    return (C - A) * (D - B) + (G - E) * (H - F) - x * y;
}

int main(){
    printf("%d\n", computeArea(-1500000001,0,-1500000000,1,1500000000,0,1500000001,1));
    return 0;
}