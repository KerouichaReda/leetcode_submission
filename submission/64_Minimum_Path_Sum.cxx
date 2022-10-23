/*
 * 64_Minimum_Path_Sum.cxx
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
int minPathSum(vector<vector<int>>& grid) {
	int m = grid.size();
	int n = grid[0].size();
	vector<vector<int>> dp(m,vector<int>(n,0));
	dp[0][0] = grid[0][0];
	for(int i = 1; i < m ;i++)
		dp[i][0] = dp[i-1][0] + grid[i][0];
	for(int i = 1; i < n ;i++)
		dp[0][i] = dp[0][i-1] + grid[0][i];
	for(int i = 1 ;i < m ;i++){
		for(int j = 1; j < n;j++){
			dp[i][j] = grid[i][j] +  min(dp[i][j-1],dp[i-1][j]);
		}
	}        
	return dp[m-1][n-1];
}

int main(int argc, char **argv)
{
	
	return 0;
}

