/*
 * 300_Longest_Increasing_Subsequence.cxx
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
 * https://en.wikipedia.org/wiki/Longest_increasing_subsequence
 */


#include <iostream>
#include <vector>
#include <string>
void disp(std::vector<int> &array , std::string msg){
	std::cout << msg << " : " ;
	for(int n : array){
		std::cout<< n << " ";
	}
	std::cout << std::endl;
}

std::vector<int> lengthOfLIS(std::vector<int>& array){
	int nb =(int) array.size(); //number 
	std::vector<int> pred(nb); //predessor 
	std::vector<int> record(nb+1); // recording
	int length = 0; // lenght of the longest increasing seq
	int low,high,mid; //binary search 
	int newLength,k; //
	for(int i = 0; i < nb;i++){
		low = 1;
		high = length;
		while(low <= high){
			mid = (low + high + 1)/2;
			if(array[record[mid]] < array[i]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		newLength = low;
		pred[i] = record[newLength-1];
		record[newLength] = i;
		if(newLength > length){
			length = newLength;
		}
		disp(pred,"pred");
		disp(record,"record");
	}
	std::vector<int> solution(length);
	k=record[length];
	for(int i = length -1;i>=0;i--){
		solution[i] = array[k];
		k=pred[k];
	}
	//std::cout << std::endl ;
	return solution;	
}

int main(int argc, char **argv)
{
	std::vector<int> nums = {1,5,2};
	std::vector<int> sub = lengthOfLIS(nums);
	disp(sub,"result");
	
	return 0;
}

