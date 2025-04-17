/*
 * 2176_count_equal_and_divisible_pairs_in_an_array.cxx
 *
 * Copyright 2025 - present RedaKerouicha <reda_kerouicha@outlook.com>
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
#include <set>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
int countPairs(std::vector<int>& nums, int k) {
    int solution{};
    for (std::size_t i = 0, size = nums.size(); i < size - 1; i++) {
        for (std::size_t j = i + 1; j < size; j++) {
            solution += (nums[i] == nums[j] && i * j % k == 0);
        }
    }
    return solution;
}
int main(int argc, char** argv) {
    std::vector<int> nums{1, 2, 3, 4, 5};
    std::cout << countPairs(nums, 2) << std::endl;
    return 0;
}
