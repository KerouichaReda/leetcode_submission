/*
 * 881_Boats_to_Save_People.cxx
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
#include <algorithm>

int numRescueBoats(std::vector<int>& people, int limit) {
	std::sort(people.rbegin(),people.rend());
	int i = 0;
	int j = people.size() - 1 ;
	for( ;i <= j; i++){
		if(people[i]+people[j] <= limit) j--;
	}
	
	return i;
}

int main(int argc, char **argv)

{
	std::vector<int> people = {3,2,2,1};
	int limit = 3;
	std::cout << numRescueBoats(people,  limit) << std::endl;
	
	return 0;
}

