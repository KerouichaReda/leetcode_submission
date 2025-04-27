/*
 * 953_Verifying_an_Alien_Dictionary.cxx
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

bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, int> m;
    for (int i = 0; i < order.size(); i++) {
        m[order[i]] = i;
    }

    for (int i = 0; i < words.size() - 1; i++) {
        if (!compare(words[i], words[i + 1], m)) {
            return false;
        }
    }
    return true;
}
bool compare(string a, string b, unordered_map<char, int> m) {
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        if (m[a[i]] < m[b[i]]) {
            return true;
        } else if (m[a[i]] > m[b[i]]) {
            return false;
        }
    }
    return i == a.size();
}

int main(int argc, char** argv) { return 0; }
