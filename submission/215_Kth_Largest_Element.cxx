/*
 * 215_Kth_Largest_Element.cxx
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
 * https://leetcode.com/problems/kth-largest-element-in-an-array/
 * https://www.reddit.com/r/cscareerquestions/comments/kyjwim/just_got_laid_off/
 */

#include <iostream>
#include <vector>
#include <algorithm>

int findKthLargest(std::vector<int>& nums, int k) {
    std::make_heap(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++) {
        std::pop_heap(nums.begin(), nums.end());
        nums.pop_back();
    }
    return nums.front();
}

int main(int argc, char** argv) {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 5;
    std::cout << findKthLargest(nums, k) << std::endl;

    return 0;
}
