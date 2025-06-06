/*
 * 3452_sum_of_good_numbers.cxx
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

int sumOfGoodNumbers(std::vector<int>& nums, int k) {
    int res{0};
    for (int i = 0, size = nums.size(); i < size; i++) {
        bool left = i >= k ? nums[i] > nums[i - k] : true;
        bool right = i < size - k ? nums[i] > nums[i + k] : true;
        res += (left && right) * nums[i];
    }
    return res;
}

int main(int argc, char** argv) {
    std::vector<int> nums = {0, 0, 0, 0, 0};
    std::cout << sumOfGoodNumbers(nums, 2) << std::endl;
    return 0;
}
