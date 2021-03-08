/*
 * 1337_The_K_Weakest_Rows_in_a_Matrix.cxx
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
vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {        
	vector<pair<int,int>> vec;
	vector<int> solution;   
	for(int i = 0 ; i < mat.size(); i++){    
		vec.push_back(pair<int,int>{i,accumulate(mat[i].begin(),mat[i].end(),0)});
	}        
	sort(vec.begin(),vec.end(),[](pair<int,int> a, pair<int,int> b){
		return  a.second == b.second ? a.first < b.first : a.second < b.second;
	});             
	for(int i = 0; i < k ; i++){
		solution.push_back(vec[i].first);
	}        
	return solution;    
}


int main(int argc, char **argv)
{
	
	return 0;
}

