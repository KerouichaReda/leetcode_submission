/*
 * 41_First_Missing_Positive.cxx
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

int firstMissingPositive(vector<int>& nums) {
    std::unordered_map<int, int> u;
    int max = 0;
    for (int n : nums) {
        u.insert(std::make_pair(n, n));
        if (n > max) max = n;
    }
    for (int i = 1; i <= max; i++) {
        if (u.find(i) == u.end()) return i;
    }
    return max + 1;
}

int main(int argc, char** argv) { return 0; }
