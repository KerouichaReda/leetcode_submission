/*
 * heap.cxx
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

#include "heap.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	
	int array[] = {1,2,3,4,5,6,7,8,9,1};
	
	for(int i ; i<10;i++)
		std::cout<<array[i]<<" ";
	std::cout<<std::endl;
	
	Heap<int> h(array,10,100);
	h.display_heap();

	return 0;
}

