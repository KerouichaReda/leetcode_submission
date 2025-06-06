/*
 * 1556_thousand_separator.cxx
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
std::string thousandSeparator(int n) {
    std::string solution{};
    std::string temp = std::to_string(n);
    std::reverse(temp.begin(), temp.end());
    int index{};
    for (char c : temp) {
        solution.push_back(c);
        if (++index % 3 == 0) solution.push_back('.');
    }
    if (solution.back() == '.') solution.pop_back();
    std::reverse(solution.begin(), solution.end());
    return solution;
}

int main(int argc, char** argv) { return 0; }
