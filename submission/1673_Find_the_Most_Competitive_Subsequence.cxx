/*
 * 1673_Find_the_Most_Competitive_Subsequence.cxx
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

void disp(std::vector<int>& A) {
    for (int n : A) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

std::vector<int> mostCompetitive(std::vector<int>& n, int k) {
    std::vector<int> stack;
    int l = n.size();
    for (int i = 0; i < l; i++) {
        while (!stack.empty() && stack.back() > n[i] && l - i + stack.size() > (unsigned)k) {
            stack.pop_back();
        }
        if (stack.size() < (unsigned)k) {
            stack.push_back(n[i]);
        }
        disp(stack);
    }
    return stack;
}

int main(int argc, char** argv) {
    std::vector<int> array = {3, 5, 2, 6, 6, 6, 6, 6, 6, 6, 6, 1, 0};
    int k = 2;
    std::vector<int> solution = mostCompetitive(array, k);
    disp(solution);

    return 0;
}
