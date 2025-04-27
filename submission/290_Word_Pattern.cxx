/*
 * 290_Word_Pattern.cxx
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
 * https://leetcode.com/problems/word-pattern/
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

bool wordPattern(std::string pattern, std::string s) {
    std::vector<std::string> tokens;
    s.push_back(' ');
    std::string temp;
    for (char& c : s) {
        if (c == ' ') {
            if (!temp.empty()) {
                tokens.push_back(temp);
                temp.clear();
            }
        } else {
            temp.push_back(c);
        }
    }
    if (pattern.size() != tokens.size()) return false;
    std::unordered_map<char, std::string> m1;
    std::unordered_map<std::string, char> m2;
    for (std::size_t index = 0, size = pattern.size(); index < size; index++) {
        if (m1.count(pattern[index]) && m1[pattern[index]] != tokens[index]) return false;
        if (m2.count(tokens[index]) && m2[tokens[index]] != pattern[index]) return false;
        m1[pattern[index]] = tokens[index];
        m2[tokens[index]] = pattern[index];
    }
    return true;
}

int main(int argc, char** argv) {
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    std::cout << wordPattern(pattern, str) << std::endl;

    return 0;
}
