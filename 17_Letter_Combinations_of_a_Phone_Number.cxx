/*
 * 17_Letter_Combinations_of_a_Phone_Number.cxx
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
#include <string>
    void helper(std::string &digits,std::string temp, int index , std::vector<std::vector<char>> &keys ,std::vector<std::string> &solution){
        if((unsigned)index == digits.size()){
            solution.push_back(temp);
            return;
        } 
        int key = digits[index] - '2';
        helper(digits,temp+keys[key][0],index+1,keys,solution);
        helper(digits,temp+keys[key][1],index+1,keys,solution);
        helper(digits,temp+keys[key][2],index+1,keys,solution);
        if(key == 5 || key == 7) {
            helper(digits,temp+keys[key][3],index+1,keys,solution);
        }     
    }
std::vector<std::string> letterCombinations(std::string digits) {
if(digits == "")
	return std::vector<std::string>{};
 std::vector<std::string> solution;  
 std::vector<std::vector<char>> keys = {
	 {'a','b','c'},
	 {'d','e','f'},
	 {'g','h','i'},
	 {'j','k','l'},
	 {'m','n','o'},
	 {'p','q','r','s'},
	 {'t','u','v'},
	 {'w','x','y','z'}
 };

helper(digits,"",0,keys,solution);
return solution;
}


int main(int argc, char **argv)
{
	std::string digits = "222";
	std::vector<std::string> solution = letterCombinations(digits);
	
	for (std::string s : solution){
		std::cout<< s <<'\n';
	}
	std::cout << std::endl;
	return 0;
}

