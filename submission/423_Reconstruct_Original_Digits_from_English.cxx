/*
 * 423_Reconstruct_Original_Digits_from_English.cxx
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

string originalDigits(string s) {
    vector<int> a(10, 0);
    vector<int> alpha(26, 0);
    for (char c : s) {
        alpha[c - 'a']++;
    }
    a[0] = alpha['z' - 'a'];
    a[2] = alpha['w' - 'a'];
    a[4] = alpha['u' - 'a'];
    a[6] = alpha['x' - 'a'];
    a[8] = alpha['g' - 'a'];
    a[3] = alpha['h' - 'a'] - a[8];
    a[5] = alpha['f' - 'a'] - a[4];
    a[7] = alpha['v' - 'a'] - a[5];
    a[1] = alpha['o' - 'a'] - a[0] - a[2] - a[4];
    a[9] = alpha['i' - 'a'] - a[5] - a[6] - a[8];
    string ans = string{};
    for (int i = 0; i < 10; i++) {
        if (a[i] > 0) ans += string(a[i], '0' + i);
    }
    return ans;
}

int main(int argc, char** argv) { return 0; }
