/*
 * 56_Merge_Intervals.cxx
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
#include <set>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::vector<std::vector<int>> solution;
    std::set<int> all;
    for (std::vector<int> interval : intervals) {
        for (int i = interval[0]; i <= interval[1]; i++) {
            all.insert(i);
        }
    }
    int start = *all.begin();
    int end = start - 1;
    boo for (int element : all) {
        // std::cout<<element<<" "<<start<<" "<<end<<" "<<std::endl;
        if (element != end + 1) {
            solution.push_back({start, end});
            start = element;
            end = element;
        } else {
            end = element;
        }
    }
    solution.push_back({start, end});
    return solution;
}

int main(int argc, char** argv) { return 0; }
