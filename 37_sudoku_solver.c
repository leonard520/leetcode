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
		printf("before: %d, %d\n", *row, *col);

	i = *row;
	while(i < 9){
		j = (i == *row) ? *col + 1 : 0;
		while(j < 9 && bitmap[i][j] == '.'){
			j++;
		}
		if(j < 9){
			*row = i;
			*col = j;
			printf("after: %d, %d\n", *row, *col);
			return true;
		}
		i++;
	}
	return false;
}

bool next(char **board, int row, int col, char **bitmap, char **option, int number){

	if(isValid(board, row, col) == false){
		return false;
	}

	if(isValid(board, row, col) == true && number == 81){
		printf("valid");
		return true;
	}

	printf("next: %d, %d\n", row, col);
	int *i, *j;
	i = malloc(sizeof(int));
	j = malloc(sizeof(int));

	int k, l;
	char **o = malloc(sizeof(char *)*9);
	for(l = 0; l < 9; l++){
		o[l] = malloc(sizeof(char)*9);
		memcpy(o[l], option[l], 9);
	}
	char **b = malloc(sizeof(char *)*9);
	for(l = 0; l < 9; l++){
		b[l] = malloc(sizeof(char)*9);
		memcpy(b[l], bitmap[l], 9);
	}
	//bitmap[row][col] = '0';
	number++;
	for(k = 0; k < 9; k++){
		if(o[row][k] == '0'){
			o[row][k] = '1';
			b[row][col] = k + 49;;
			*i = row;
			*j = col;
			if(findNextEmpty(bitmap, i, j) == true){
				next(board, *i, *j, b, o, number);
			} else {
				next(board, row, col, b, o, number);
			}
			o[row][k] = '0';
		}
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
char b1[] = {'.','.','.','.','.','.','.','6','.'}; board[0] = b1;
     char b2[] = {'9','.','1','7','.','.','4','.','.'}; board[1] = b2;
     char b3[] = {'7','.','4','6','.','5','.','2','.'}; board[2] = b3;
     char b4[] = {'.','.','2','.','.','.','.','.','.'}; board[3] = b4;
     char b5[] = {'.','.','.','.','.','.','5','.','.'}; board[4] = b5;
     char b6[] = {'.','.','7','.','9','.','1','.','2'}; board[5] = b6;
     char b7[] = {'.','.','8','.','.','.','.','1','.'}; board[6] = b7;
     char b8[] = {'4','2','.','.','1','9','.','8','.'}; board[7] = b8;
     char b9[] = {'5','.','.','.','7','.','.','.','6'}; board[8] = b9;

	 solveSudoku(board, 9, 9);
}