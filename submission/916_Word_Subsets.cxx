/*
 * 916_Word_Subsets.cxx
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
#include <string>
#include <utility>

std::vector<int> counter(std::string& str) {
    std::vector<int> result(26, 0);
    for (char c : str) {
        result[c - 'a']++;
    }
    return result;
}

std::vector<std::string> wordSubsets(std::vector<std::string>& A, std::vector<std::string>& B) {
    std::vector<int> temp(26, 0), comp(26, 0);
    std::vector<std::string> solution;
    int i;
    for (std::string str : B) {
        temp = counter(str);
        for (int i = 0; i < 26; ++i) {
            comp[i] = std::max(temp[i], comp[i]);
        }
    }
    for (std::string str : A) {
        temp = counter(str);
        for (i = 0; i < 26; ++i) {
            if (temp[i] < comp[i]) {
                break;
            }
        }
        if (i == 26) {
            solution.push_back(str);
        }
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
