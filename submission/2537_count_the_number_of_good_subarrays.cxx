/*
 * 2537_count_the_number_of_good_subarrays.cxx
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

std::int64_t countGood(std::vector<std::int32_t>& nums, std::int32_t k) {
    std::int64_t solution{};
    std::map<std::int32_t, std::int32_t> m_;
    for (std::size_t i = 0, j = 0, size = nums.size(); j < size; ++j) {
        k -= m_[nums[j]]++;
        while (k <= 0) {
            k += --m_[nums[i++]];
        }
        solution += i;
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
