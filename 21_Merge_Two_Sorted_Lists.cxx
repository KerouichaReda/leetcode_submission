/*
 * 21_Merge_Two_Sorted_Lists.cxx
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

#include "listnode.hpp"

int main(int argc, char **argv)
{
	std::vector<int> vec1 = {2};
	std::vector<int> vec2 = {3};
	ListNode *l1 = createListFromArray(vec1);
	ListNode *l2 = createListFromArray(vec2);
	
	ListNode *ans = mergeTwoLists(l1,l2);
	
	displayList(l1);
	displayList(l2);
	displayList(ans);	
	
	return 0;
}

