/*
 * 57_Insert_Interval.cxx
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
 * https://leetcode.com/problems/insert-interval/
 */


#include <iostream>
#include <vector>


std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) 
    {
        std::vector<std::vector<int>> updatedIntervals ={{1,3},{6,9}};
        
        return updatedIntervals ;
    }
    
 void showInterval(std::vector<int> Interval)
 {
	 std::cout<<"["<<Interval[0]<<","<<Interval[1]<<"]"<<std::endl;
	 }   
int main(int argc, char **argv)
{
	//std::vector<std::vector<int>> intervals ={{1,3},{6,9}};
	
	std::vector<int> newInterval={4,8};
	showInterval(newInterval);
	
	return 0;
}

