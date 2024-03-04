/*
 * 870_Advantage_Shuffle.cxx
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

#include <vector>
#include <set>
#include <iostream>

std::vector<int> advantageCount(std::vector<int>& A, std::vector<int>& B) {
    if (A.size() == 1) return A;
    int size = A.size();
    std::vector<int> solution(size);
    std::multiset<int> s(A.begin(), A.end());
    for (int i = 0; i < size; i++) {
        std::multiset<int>::iterator itr =
            B[i] >= *s.rbegin() ? s.begin() : s.upper_bound(B[i]);
        solution[i] = *itr;
        s.erase(itr);
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
