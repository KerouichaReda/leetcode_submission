/*
 * 377_Combination_Sum_IV.cxx
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
    int combinationSum4(vector<int>& nums, int target) {
        if(target == 0)  return 1;
        if(target < 0)  return 0;
        if(memo.count(target))  return memo[target];

        int solution = 0; 
        
        for(int e : nums){
            int rest  = target - e;
            solution += combinationSum4( nums, rest);
        }
        memo[target] = solution;
        return solution;
    }
    
private :
    unordered_map<int,int> memo;
};

int main(int argc, char **argv)
{
	
	return 0;
}

