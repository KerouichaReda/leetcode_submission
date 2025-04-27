/*
 * 1190_Reverse_Substrings_Between_Each_Pair_of Parentheses.cxx
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
#include <string>
#include <vector>

std::string reverseParentheses(std::string s) {
    std::vector<std::string> stack{std::string{}};
    for (char& c : s) {
        if (c == '(') {
            stack.push_back(std::string{});
        } else if (c == ')') {
            std::reverse(stack.back().begin(), stack.back().end());
            std::string temp = stack.back();
            stack.pop_back();
            stack.back() += temp;
        } else {
            stack.back().push_back(c);
        }
    }
    return stack[0];
}

int main(int argc, char** argv) {
    std::string s{"abc(def)ghi"};
    std::cout << reverseParentheses(s) << std::endl;
    return 0;
}
