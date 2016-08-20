/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int i, j;

	char *map = malloc(sizeof(char) * 9);

	for(i = 0; i < 9; i++){
		memset(map, '0', 9);
		for(j = 0; j < 9; j++)
			if(board[i][j] == '.' ) {
				continue;
			} else if(map[board[i][j] - 49] == '0'){
				map[board[i][j] - 49] = '1';
			} else {
				printf("false\n");
				return false;
			}
	}  

	for(j = 0; j < 9; j++){
		memset(map, '0', 9);
		for(i = 0; i < 9; i++)
			if(board[i][j] == '.' ) {
				continue;
			} else if(map[board[i][j] - 49] == '0'){
				map[board[i][j] - 49] = '1';
			} else {
				printf("false\n");
				return false;
			}
	}   

	for(i = 0; i < 9; i+=3){
		for(j = 0; j < 9; j+=3){
			memset(map, '0', 9);
			for(int m = 0; m < 3; m++){
				for(int n = 0; n < 3; n++){
					if(board[i + m][j + n] == '.' ) {
						continue;
					} else if(map[board[i + m][j + n] - 49] == '0'){
						map[board[i + m][j + n] - 49] = '1';
					} else {
						printf("false\n");
						return false;
					}
				}
			}
		}
	}
	return true;
}