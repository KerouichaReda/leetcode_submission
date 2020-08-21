/*
 * 1_Two_Sum.cxx
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
 * 
 * https://leetcode.com/problems/two-sum/
 */


#include <iostream>
 vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int n = nums.size();
        for(int i=0;i<n;i++)
            m.insert({nums[i], i});
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int check = target - nums[i];
            if(m.find(check) != m.end()){
                if(m[check] != i){
                    ans.push_back(i);
                    ans.push_back(m[check]);
                    break;
                }
            }
        }
        return ans;
    }

int main(int argc, char **argv)
{
	
	return 0;
}

