/*
 * 22_Generate_Parentheses.cxx
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

void generateParenthesisHelper(int& n, int left, int right, std::string str, std::vector<std::string>& solutions) {
    if (left == n && right == n) {
        solutions.push_back(str);
        return;
    }
    if (left < n) generateParenthesisHelper(n, left + 1, right, str + '(', solutions);
    if (right < left) generateParenthesisHelper(n, left, right + 1, str + ')', solutions);
}
std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> solutions;
    generateParenthesisHelper(n, 0, 0, string{}, solutions);
    return solutions;
}

int main(int argc, char** argv) { return 0; }
