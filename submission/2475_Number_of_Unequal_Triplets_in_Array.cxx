/*
 * 2475_Number_of_Unequal_Triplets_in_Array.cxx
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

int unequalTriplets(vector<int>& nums) {
    int solution{0};
    for (int i = 0, size = nums.size(); i < size - 2; ++i) {
        for (int j = i + 1; j < size - 1; ++j) {
            for (int k = j + 1; k < size; ++k) {
                solution += nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k];
            }
        }
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
