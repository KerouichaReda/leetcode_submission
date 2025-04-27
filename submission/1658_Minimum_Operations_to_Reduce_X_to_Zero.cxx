/*
 * 1658_Minimum_Operations_to_Reduce_X_to_Zero.cxx
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

#include <limits.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int minOperations(std::vector<int>& nums, int x) {
    std::unordered_map<int, int> left;
    int res = INT_MAX;
    for (int l = 0, sum = 0; l < (int)nums.size() && sum <= x; ++l) {
        left[sum] = l;
        sum += nums[l];
    }
    for (int r = nums.size() - 1, sum = 0; r >= 0 && sum <= x; --r) {
        std::unordered_map<int, int>::iterator it = left.find(x - sum);
        if (it != end(left) && r + 1 >= it->second) {
            res = std::min(res, (int)nums.size() - r - 1 + it->second);
        }
        sum += nums[r];
    }
    return res == INT_MAX ? -1 : res;
}
int main(int argc, char** argv) {
    std::vector<int> nums = {1, 1, 4, 2, 3};
    int x = 5;
    std::cout << minOperations(nums, x) << std::endl;
    return 0;
}
