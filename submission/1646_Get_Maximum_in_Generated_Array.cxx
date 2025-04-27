/*
 * 1646_Get_Maximum_in_Generated_Array.cxx
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
#include <vector>
#include <algorithm>

int getMaximumGenerated(int n) {
    if (n <= 1) return n;
    std::vector<int> array(n + 1);
    array[0] = 0;
    array[1] = 1;
    for (int i = 2; i <= n; i++) array[i] = (i % 2 == 0) ? array[i / 2] : array[i / 2] + array[i / 2 + 1];

    return *std::max_element(array.begin(), array.end());
}

int main(int argc, char** argv) {
    int n;
    std::cin >> n;
    std::cout << getMaximumGenerated(n) << std::endl;
    return 0;
}
