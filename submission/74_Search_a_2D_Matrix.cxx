/*
 * 74_Search_a_2D_Matrix.cxx
 * 
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if(matrix.empty() || matrix[0].empty())
	return false;
	
	if(matrix.size()==1 && matrix[0].size()==1)
	return(matrix[0][0]==target)?true:false; 
	
	int row_numb,col_numb,left,right,mid;
	
	row_numb=matrix.size();
	col_numb=matrix[0].size();        
	left=0;
	right=col_numb*row_numb-1;        
	
	while(right>=left){
		mid=(left+right)/2;               
		if(matrix[mid/col_numb][mid%col_numb]>target){
			right=mid-1;
		}
		else if(matrix[mid/col_numb][mid%col_numb]<target){
			left=mid+1;
		}
		else{
			return true;
		} 
	} 
	   return false;
}

int main(int argc, char **argv)
{
	
	return 0;
}

