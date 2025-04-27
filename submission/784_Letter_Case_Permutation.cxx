/*
 * 784_Letter_Case_Permutation.cxx
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

void letterCasePermutationHelper(std::string& S, std::string msg, int index, int& length,
                                 std::vector<std::string>& solution) {
    if (index >= length) {
        solution.push_back(msg);
        return;
    }
    letterCasePermutationHelper(S, msg + S[index], index + 1, length, solution);
    if (S[index] >= 'a' && S[index] <= 'z') {
        letterCasePermutationHelper(S, msg + (char)(S[index] + 'A' - 'a'), index + 1, length, solution);
    }
    if (S[index] >= 'A' && S[index] <= 'Z') {
        letterCasePermutationHelper(S, msg + (char)(S[index] - 'A' + 'a'), index + 1, length, solution);
    }
}

std::vector<std::string> letterCasePermutation(std::string S) {
    std::vector<std::string> solution;
    int length = S.size();
    letterCasePermutationHelper(S, std::string{}, 0, length, solution);
    return solution;
}

int main(int argc, char** argv) {
    std::string str = "11ga1b";
    std::vector<std::string> solution = letterCasePermutation(str);
    for (std::string s : solution) {
        std::cout << s << '\n';
    }
    std::cout << std::endl;
    return 0;
}
