/*
 * 242_Valid_Anagram.cxx
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
#include <string>
#include <algorithm>

bool isAnagram(string s, string t) {
	std::vector<int> vs(26),vt(26);
	for(char c : s) vs[c-'a']++;
	for(char c : t) vt[c-'a']++;
	return std::equal(vs.begin(),vs.end(),vt.begin());
}

int main(int argc, char **argv)
{
	
	return 0;
}

