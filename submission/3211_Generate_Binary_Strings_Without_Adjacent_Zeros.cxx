/*
 * 3211_Generate_Binary_Strings_Without_Adjacent_Zeros.cxx
 *
 * Copyright 2024 Reda Kerouicha <redakerouicha@192.168.0.105>
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
#include <optional>
#include <string>
#include <vector>

void backtrack(std::string temp, int n, std::vector<std::string>& solution, std::optional<bool> flag = std::nullopt) {
    if (n == 0) {
        solution.push_back(temp);
        return;
    }
    if (flag == std::nullopt) {
        backtrack(temp, n, solution, true);
        backtrack(temp, n, solution, false);
    } else {
        temp.push_back(flag.value() ? '1' : '0');

        backtrack(temp, n - 1, solution, true);
        if (flag.value() && n > 1) {
            backtrack(temp, n - 1, solution, false);
        }
    }
}

std::vector<std::string> validStrings(int n) {
    std::vector<std::string> solution;
    backtrack(std::string{}, n, solution);
    return solution;
}

int main(int argc, char** argv) {
    std::vector<std::string> solution = validStrings(5);

    for (std::string& s : solution) {
        std::cout << s << std::endl;
    }

    return 0;
}
