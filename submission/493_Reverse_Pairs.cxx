/*
 * 493_Reverse_Pairs.cxx
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
#include <utility>
#include <algorithm>

int reversePairs(std::vector<int>& nums) {
    int count = 0;
    std::vector<std::pair<int, int>> vec;
    for (int i = 0; i < (int)nums.size(); i++) {
        vec.push_back(std::make_pair(nums[i], i));
    }
    std::sort(vec.rbegin(), vec.rend());
    for (int i = 0; i < (int)vec.size() && vec[i].first > vec.back().first * 2; ++i) {
        for (int j = (int)vec.size() - 1; j >= 0 && vec[i].first > vec[j].first * 2; --j) {
            // std::cout << vec[j].first << std::endl;
            if (vec[i].second < vec[j].second) {
                count++;
            }
        }
    }

    return count;
}

int main(int argc, char** argv) {
    std::vector<int> nums = {2566, 5469, 1898, 127, 2441};
    std::cout << reversePairs(nums) << std::endl;
    return 0;
}
