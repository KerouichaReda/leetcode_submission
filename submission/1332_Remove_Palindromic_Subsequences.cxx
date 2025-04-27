/*
 * 1332_Remove_Palindromic_Subsequences.cxx
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

#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

int removePalindromeSub(std::string s) {
    return 2 - std::equal(s.begin(), s.begin() + s.size() / 2, s.rbegin()) - s.empty();
}

int main(int argc, char** argv) {
    std::string msg{};
    int size = 8;
    int round = 10;
    srand(time(0));
    for (int r = 0; r < round; r++) {
        msg = std::string{};
        for (int i = 0; i < size; i++) {
            msg += 'a' + (random() % 2);
        }
        std::cout << msg << " " << removePalindromeSub(msg) << std::endl;
    }
    return 0;
}
