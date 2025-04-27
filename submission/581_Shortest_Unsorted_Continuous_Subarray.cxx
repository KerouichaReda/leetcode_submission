/*
 * 581_Shortest_Unsorted_Continuous_Subarray.cxx
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

int findUnsortedSubarray(std::vector<int>& nums) {
    std::vector<int> vec(nums);  // copy vector
    std::sort(vec.begin(), vec.end());
    int left = 0, right = nums.size() - 1;
    for (; left <= right; left++) {
        if (nums[left] != vec[left]) break;
    }
    if (left >= right) return 0;
    for (; right > 0; right--) {
        if (nums[right] != vec[right]) break;
    }
    return right - left + 1;
}
int main(int argc, char** argv) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 7, 6};
    std::cout << findUnsortedSubarray(nums) << std::endl;
    return 0;
}
