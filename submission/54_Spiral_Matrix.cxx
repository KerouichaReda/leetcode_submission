/*
 * 54_Spiral_Matrix.cxx
 * 
 * Copyright 2022 RedaKerouicha <redakerouicha@localhost>
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

    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int brow{0};
        int bcol{-1};
        int dir[4][2] = {{0,1}, {1,0},{0,-1},{-1,0}};
        int rot{0};
        int x{0}, y{0};
        std::vector<int> solution;
        for(int i = 0 , size = row * col ; i < size ; ++i  ){
            solution.push_back(matrix[x][y]);
            if(rot == 0 && y + dir[rot][1] == col){
                col--;
                rot = 1;
            }else if (rot == 1 && x + dir[rot][0] == row) {
                row--;
                rot = 2;
            }else if(rot == 2 && y + dir[rot][1] == bcol){
                bcol++;
                rot = 3;
            }else if(rot == 3 && x + dir[rot][0] == brow ){
                brow++;
                rot = 0;
            }
            x += dir[rot][0];
            y += dir[rot][1];
        }
        return solution;
    }

int main(int argc, char **argv)
{
	
	return 0;
}

