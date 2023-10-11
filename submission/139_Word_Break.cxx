/*
 * 139_Word_Break.cxx
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
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
    std::queue<int> queue;
    std::vector<bool> seen(s.length(), false);
    queue.push(0);
    while (!queue.empty()) {
        int start = queue.front();
        queue.pop();
        if (start == s.length()) {
            return true;
        }
        for (int end = start + 1; end <= s.length(); end++) {
            if (seen[end]) {
                continue;
            }
            if (words.find(s.substr(start, end - start)) != words.end()) {
                queue.push(end);
                seen[end] = true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv) {
    std::string s = "aaaaaaa";
    std::vector<std::string> dic = {"aaaa", "aa"};

    std::cout << wordBreak(s, dic) << std::endl;
    return 0;
}
