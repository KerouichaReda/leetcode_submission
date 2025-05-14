/*
 * 884_uncommon_words_from_two_sentences.cxx
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

std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
    std::vector<std::string> solution;
    std::map<std::string, std::int32_t> m_;
    s1 = s1 + " " + s2 + " ";
    std::string temp;
    for (const char& c : s1) {
        if (c == ' ') {
            m_[temp]++;
            temp.clear();
        } else {
            temp.push_back(c);
        }
    }
    for (const std::pair<std::string, std::int32_t> p : m_) {
        if (p.second == 1) {
            solution.push_back(p.first);
        }
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
