/*
 * 417_Pacific_Atlantic_Water_Flow.cxx
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

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> solution;
        m = matrix.size();
        if( m == 0){
            return vector<vector<int>>{};
        }
        n = matrix[0].size();
        if( m == 0 && n == 0){
            return vector<vector<int>>{};
        }
        for(int i = 0 ; i < m ; ++i){
            for(int j = 0 ; j < n ; ++j){
                v_a = vector<vector<bool>>(m,vector<bool>(n,false));
                v_p = vector<vector<bool>>(m,vector<bool>(n,false));
                if(check_p(matrix ,  i , j,matrix[i][j]) && check_a(matrix ,  i , j,matrix[i][j])){
                    solution.push_back({i,j});
                }
            }
        }
        return solution;
    }
    bool check_p(vector<vector<int>>& matrix , int i , int j,int val){
        if(i < 0 || j < 0 ){
            return true;
        }
        if(val >= matrix[i][j] && !v_p[i][j]){
            v_p[i][j] = true;
            return check_p(matrix ,  i-1 , j,matrix[i][j]) || check_p(matrix ,  i , j-1,matrix[i][j])          || check_p(matrix ,  i+1 , j,matrix[i][j]) || check_p(matrix ,  i , j+1,matrix[i][j]);
        }
        return false;
    }
        bool check_a(vector<vector<int>>& matrix , int i , int j,int val){
        if(i > m-1 || j > n-1 ){
            return true;
        }
        if(val >= matrix[i][j] && !v_a[i][j]){
            v_a[i][j] = true;
            return check_a(matrix ,  i+1 , j,matrix[i][j]) || check_a(matrix ,  i , j+1,matrix[i][j]) || check_a(matrix ,  i-1 , j,matrix[i][j]) || check_a(matrix ,  i , j-1,matrix[i][j]) ;
        }
        return false;
    }
    private:
    int m ,n;
    vector<vector<bool>> v_a;
    vector<vector<bool>> v_p;
    
};

int main(int argc, char **argv)
{
	
	return 0;
}

