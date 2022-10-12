/*
 * 1657_Determine_if_Two_Strings_Are_Close.cxx
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
#include <algorithm>

bool closeStrings(std::string w1, std::string w2) {
    if (w1.size() != w2.size())
        return false;
    std::vector<int> cnt1(26), cnt2(26);
    for (unsigned i = 0; i < w1.size(); ++i) {
        ++cnt1[w1[i] - 'a'];
        ++cnt2[w2[i] - 'a'];
    }
    if (!std::equal(begin(cnt1), end(cnt1), begin(cnt2), end(cnt2), [](int a, int b) 
    { 
		return (bool)a == bool(b); 
		}))   return false;
    std::sort(begin(cnt1), end(cnt1));
    std::sort(begin(cnt2), end(cnt2));
    return cnt1 == cnt2;
}

int main(int argc, char **argv)
{
	
	return 0;
}

