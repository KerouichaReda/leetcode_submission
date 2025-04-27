/*
 * 1679_Max_Number_of_KSum_Pairs.cxx
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
#include <unordered_map>

int maxOperations(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    int solution = 0;
    for (int n : nums) {
        if (m[k - n] > 0) {
            m[k - n]--;
            solution++;
        } else {
            m[n]++;
        }
    }
    return solution;
}

int main(int argc, char** argv) {
    std::vector nums = {1, 2, 3, 4};
    int k = 5;
    std::cout << maxOperations(nums, k) << std::endl;
    return 0;
}
