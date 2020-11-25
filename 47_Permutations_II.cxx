/*
 * 47_Permutations_II.cxx
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
#include <algorithm>
void displayArray(std::vector<int> &array){
	for(int e:array){
		std::cout<<e<<" ";
	}
	std::cout<<std::endl;
}
void generate(std::vector<int> num, int begin, int end, std::vector<std::vector<int> > &res) {
	if (begin == end-1) {
		res.push_back(num);
		return;
	}
	for (int i = begin; i < end; i++) {
		if (begin != i && num[begin] == num[i]) 
			continue;
		std::swap(num[begin], num[i]);
		generate(num, begin+1, end, res);
	}
}
std::vector<std::vector<int> > permuteUnique(std::vector<int> &num) {
	std::sort(num.begin(), num.end());
	std::vector<std::vector<int> >res;
	generate(num, 0, num.size(), res);
	return res;
}


int main(int argc, char **argv)
{
	std::vector<int> array = {1,1,2};
	
	return 0;
}

