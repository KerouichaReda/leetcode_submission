/*
 * 1217_Minimum_Cost_to_Move_Chips.cxx
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

	
int minCostToMoveChips(std::vector<int>& position) {
        int total[]={0,0};        
        for (int chip_position:position )
        {
                ++total[chip_position%2];       
        }     
		return (total[1]>=total[0])? total[0]:total[1];
}

int main(int argc, char **argv)
{
	std::vector<int> positions = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
	
	std::cout<<minCostToMoveChips(positions)<<std::endl;
	
	return 0;
}

