/* Copyright (C) 2016 Leonard Ding <dingxiaoyun88@gmail.com> */
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int i, j;
	for(i = 0; i < 9; i++){
		for(j = 0; j < 9; j++){
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	char *map = malloc(sizeof(char) * 9);

	for(i = 0; i < 9; i++){
		memset(map, '0', 9);
		for(j = 0; j < 9; j++)
			if(board[i][j] == '.' ) {
				continue;
			} else if(map[board[i][j] - 49] == '0'){
				printf("1 %d, %d, %c\n", i, j, board[i][j]);
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
				printf("2 %d, %d, %c\n", i, j, board[i][j]);
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
					if(board[m][n] == '.' ) {
						continue;
					} else if(map[board[m][n] - 49] == '0'){
						printf("3 %d, %d, %c\n", i, j, board[i][j]);
						map[board[m][n] - 49] = '1';
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

int main(){
	int array[] = {1,3,5,6};
	printf("%d",searchInsert(array, 4, 5));
	return 0;
}