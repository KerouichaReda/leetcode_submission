/*
 * 46_Permutations.cxx
 *
 * Copyright 2020 RedaKerouicha <redakerouicha@localhost>
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
 * TODO:
 * |X| - https://en.wikipedia.org/wiki/Heap%27s_algorithm
 * |X| - https://en.wikipedia.org/wiki/Permutation
 */

#include <iostream>
#include <vector>
#include <algorithm>
void displayArray(std::vector<int>& array) {
    for (int e : array) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void heapPermutation(int size, std::vector<int>& array) {
    if (size == 1) {
        displayArray(array);
        return;
    }
    for (int i = 0; i < size; ++i) {
        heapPermutation(size - 1, array);
        if ((size % 2) == 1) {
            std::swap(array[0], array[size - 1]);

        } else {
            std::swap(array[i], array[size - 1]);
        }
    }
}
void heapPermutation(int size, std::vector<int>& array, std::vector<std::vector<int>>& solution) {
    if (size == 1) {
        solution.push_back(array);
        return;
    }
    for (int i = 0; i < size; ++i) {
        heapPermutation(size - 1, array, solution);
        if ((size % 2) == 1) {
            std::swap(array[0], array[size - 1]);
        } else {
            std::swap(array[i], array[size - 1]);
        }
    }
}

int main(int argc, char** argv) {
    std::vector<int> array = {1, 2, 3};
    heapPermutation(static_cast<int>(array.size()), array);
    return 0;
}
