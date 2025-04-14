/*
 * 1995_count_special_quadruplets.cxx
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
int countQuadruplets(const std::vector<int>& arr) {
    int solution{0};
    for (int i = 0, size = arr.size(); i < size - 3; ++i) {
        for (int j = i + 1; j < size - 2; ++j) {
            for (int k = j + 1; k < size - 1; ++k) {
                for (int l = k + 1; l < size; ++l) {
                    solution += (arr[i] + arr[j] + arr[k]) == arr[l];
                }
            }
        }
    }
    return solution;
}

int main(int argc, char** argv) {
    std::cout << countQuadruplets(std::vector<int>{1, 2, 3, 4, 5}) << std::endl;
    return 0;
}
