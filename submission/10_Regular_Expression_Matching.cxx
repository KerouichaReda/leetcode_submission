/*
 * 10_Regular_Expression_Matching.cxx
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
 * GNU General Public License for more details.z
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
#include <cstring>

bool isMatch(std::string text, std::string pattern) {
    if (pattern.empty()) return text.empty();
    bool first_match = (!text.empty() && (pattern.at(0) == text.at(0) || pattern.at(0) == '.'));
    if (pattern.length() >= 2 && pattern.at(1) == '*') {
        return (isMatch(text, pattern.substr(2)) || (first_match && isMatch(text.substr(1), pattern)));
    } else {
        return first_match && isMatch(text.substr(1), pattern.substr(1));
    }
}

bool isMatch(char* text, char* pattern) {
    if (*(pattern) == '\0') return *(text) == '\0';
    bool first_match = (*(text) != '\0' && (*pattern == *text || *pattern == '.'));
    if (strlen(pattern) >= 2 && *(pattern + 1) == '*') {
        return (isMatch(text, pattern + 2)) || (first_match && isMatch(text + 1, pattern));
    } else {
        return first_match && isMatch(text + 1, pattern + 1);
    }
}

int main(int argc, char** argv) {
    char reg[] = "ab*c*d*";
    char text[] = "abcd";
    // std::string reg ="ab*c*d*";
    // std::string text="abcd";

    std::cout << isMatch(text, reg) << std::endl;
    return 0;
}
