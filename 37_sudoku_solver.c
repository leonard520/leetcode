/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isValid(char **board, int row, int col){
	char *map = malloc(sizeof(char) * 9);
	int i, j;
	memset(map, '0', 9);
	for(i = 0; i < 9; i++){
		if(board[i][col] == '.' ) {
			continue;
		} else if(map[board[i][col] - 49] == '0'){
			map[board[i][col] - 49] = '1';
		} else {
			return false;
		}
	}
	memset(map, '0', 9);
	for(j = 0; j < 9; j++){
		if(board[row][j] == '.' ) {
			continue;
		} else if(map[board[row][j] - 49] == '0'){
			map[board[row][j] - 49] = '1';
		} else {
			return false;
		}
	}
	memset(map, '0', 9);
	i = row / 3;
	j = col / 3;
	for(; i < row / 3 + 3; i++){
		for(; j < col / 3 + 3; j++){
			if(board[i][j] == '.' ) {
				continue;
			} else if(map[board[i][j] - 49] == '0'){
				map[board[i][j] - 49] = '1';
			} else {
				return false;
			}
		}
	}
	return true;
}

bool findNextEmpty(char **bitmap, int *row, int *col){
	int i, j;
	i = *row;
	while(i < 9){
		j = (i == *row) ? *col + 1 : 0;
		while(j < 9 && bitmap[i][j] == '0'){
			j++;
		}
		if(j < 9){
			*row = i;
			*col = j;
			return true;
		}
		i++;
	}
	return false;
}

bool next(char **board, int row, int col, char **bitmap, char **option, int number){
	int *i, *j;
	i = malloc(sizeof(int));
	j = malloc(sizeof(int));

	int k, l;
	
	//bitmap[row][col] = '0';
	number++;
	for(k = 0; k < 9; k++){
		if(option[row][k] == '0'){
			option[row][k] = '1';
			board[row][col] = k + 49;;
			*i = row;
			*j = col;
			if(findNextEmpty(bitmap, i, j) == true){
				next(board, *i, *j, bitmap, option, number);
			}
			option[row][k] = '0';
		}
	}
	if(isValid(board, row, col) == true && number == 81){
		return true;
	}
	
	return false;
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    int i, j, row;
    char **bitmap = malloc(sizeof(char *)*9);
    for(i = 0; i < 9; i++){
    	bitmap[i] = malloc(sizeof(char)*9);
    	memset(bitmap[i], '0', 9);
    }

    char **option = malloc(sizeof(char *)*9);
    for(i = 0; i < 9; i++){
    	option[i] = malloc(sizeof(char)*9);
    	memset(option[i], '0', 9);
    }

    int number = 0;
    bool flag = false;
    for(i = 0; i < 9; i++){
    	for(j = 0; j < 9; j++){
    		if(board[i][j] == '.'){
    			bitmap[i][j] = '1';//need fill
    		} else {
    			option[i][board[i][j] - 49] = '1';//occupy
    			number++;
    		}
    	}
    }

    i = j = 0;
	int *k;
	int *l;
	k = &i;
	l = &j;
    if(board[0][0] != '.'){
	    findNextEmpty(bitmap, k, l);
    }
    next(board, *k, *l, bitmap, option, number);
}

int main(){
     char **board = malloc(sizeof(char *)*9);
     char b1[] = {'.','1','9','7','4','8','6','3','2'}; board[0] = b1;
     char b2[] = {'7','.','3','6','5','.','4','1','9'}; board[1] = b2;
     char b3[] = {'4','2','6','1','3','9','8','.','5'}; board[2] = b3;
     char b4[] = {'3','5','7','.','8','6','2','4','.'}; board[3] = b4;
     char b5[] = {'2','6','4','3','1','7','5','9','8'}; board[4] = b5;
     char b6[] = {'.','9','8','5','2','.','3','6','7'}; board[5] = b6;
     char b7[] = {'9','7','5','8','.','3','1','2','4'}; board[6] = b7;
     char b8[] = {'8','3','2','4','9','1','7','5','6'}; board[7] = b8;
     char b9[] = {'6','4','1','.','7','5','9','8','3'}; board[8] = b9;

	 solveSudoku(board, 9, 9);
}