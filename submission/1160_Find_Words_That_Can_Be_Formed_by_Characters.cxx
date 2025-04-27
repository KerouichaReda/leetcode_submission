/*
 * 1160_Find_Words_That_Can_Be_Formed_by_Characters.cxx
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

int countCharacters(vector<string>& words, string chars) {
    vector<int> freq = count(chars);
    int solution = 0;
    for (string w : words) {
        vector<int> temp = count(w);
        int i;
        for (i = 0; i < 26; i++) {
            if (freq[i] < temp[i]) break;
        }
        if (i == 26) {
            solution += w.size();
        }
    }

    return solution;
}

vector<int> count(string s) {
    vector<int> freq(26);
    for (char c : s) {
        freq[c - 'a']++;
    }
    return freq;
}

int main(int argc, char** argv) { return 0; }
