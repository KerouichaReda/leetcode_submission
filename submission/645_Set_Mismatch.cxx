/*
 * 645_Set_Mismatch.cxx
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
#include <unordered_map>

std::vector<int> findErrorNums(std::vector<int>& nums) {  
	std::unordered_map<int,int> m;
	int rep = 0 , miss = 0;
	for(int element : nums) m[element]++;

	for(int i = 1 ; i < nums.size() + 1  ; i ++){
		if(m[i] == 0) miss = i;
		if(m[i] > 1) rep = i;
	}
	return {rep,miss};
}
int main(int argc, char **argv)
{
	
	return 0;
}

