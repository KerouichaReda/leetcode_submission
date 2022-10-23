/*
 * 946_Validate_Stack_Sequences.cxx
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
#include <stack>

bool validateStackSequences(std::vector<int> &push, std::vector<int> &pop) {
	std::stack<int> s;
	for (unsigned i = 0, j = 0; i < push.size(); ++i) {
		s.push(push[i]);
		while (!s.empty() && s.top() == pop[j]) {
			s.pop();
			++j;
		}
	}
	return s.empty();
}

int main(int argc, char **argv)
{
	
	return 0;
}

