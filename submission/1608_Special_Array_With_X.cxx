/*
 * 1608_Special_Array_With_X.cxx
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
 * https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
 */

#include <iostream>
#include <vector>
#include <algorithm>

int specialArray(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int min_index;

    for (int x = 1, min_index = 0; x <= nums.size(); x++) {
        for (; min_index < nums.size() && nums[min_index] < x; min_index++)
            ;

        if (nums.size() - min_index == x) return x;
    }

    return -1;
}

int main(int argc, char** argv) { return 0; }
