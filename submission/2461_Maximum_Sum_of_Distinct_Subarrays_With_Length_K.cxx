/*
 * 2461_Maximum_Sum_of_Distinct_Subarrays_With_Length_K.cxx
 *
 * Copyright 2022 RedaKerouicha <redakerouicha@localhost>
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
#include <unordered_map>
#include <algorithm>

long long maximumSubarraySum(std::vector<int>& nums, int k) {
    int64_t solution{0};
    int64_t temp{0};
    std::unordered_map<int, int> s;
    for (int i = 0, size = nums.size(); i < size; i++) {
        if (i >= k) {
            if (--s[nums[i - k]] == 0) {
                s.erase(nums[i - k]);
            }
            temp -= nums[i - k];
        }
        s[nums[i]]++;
        temp += nums[i];
        if (s.size() >= k) {
            solution = std::max(temp, solution);
        }
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
