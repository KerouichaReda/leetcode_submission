/*
 * 36_Valid_Sudoku.cxx
 * 
 * Copyright 2021 RedaKerouicha <redakerouicha@localhost>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <iostream>
#include <vector>

bool isValidSudoku(vector<vector<char>>& board) {
	vector<vector<int>> test;
	for(int i = 0; i < 9 ; i ++){
		test = vector<vector<int>>(3,(vector<int>(9)));
		for(int j = 0; j < 9 ; j++){
			if(board[i][j] != '.'){
				if(++test[0][board[i][j]-'1']>1)
					return false;
			}
			if(board[j][i] != '.'){
				if(++test[1][board[j][i]-'1']>1)
					return false;
			}
			if(board[i/3*3+j/3][i*3%9+j%3] != '.'){
				if(++test[2][board[((i/3)*3)+j/3][i*3%9+j%3]-'1']>1)
					return false;
			}
		}
	}
	return true;
}

int main(int argc, char **argv)
{
	
	return 0;
}

