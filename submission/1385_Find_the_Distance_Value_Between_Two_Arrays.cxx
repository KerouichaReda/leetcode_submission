/*
 * 1385_Find_the_Distance_Value_Between_Two_Arrays.cxx
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
#include <algorithm>
#include <numeric>

int findTheDistanceValue(std::vector<int>& arr1, std::vector<int>& arr2,
                         const int& d) {
    return std::accumulate(arr1.begin(), arr1.end(), 0, [&](int sum, int& e) {
        return sum + std::all_of(arr2.begin(), arr2.end(),
                                 [&](int& i) { return std::abs(i - e) > d; });
    });
}

int main(int argc, char** argv) {
    std::vector<int> arr1 = {1, 5, 3, 6};
    std::vector<int> arr2 = {8, 6, 9, 3};
    int d = 2;
    std::cout << findTheDistanceValue(arr1, arr2, d) << std::endl;
    return 0;
}
