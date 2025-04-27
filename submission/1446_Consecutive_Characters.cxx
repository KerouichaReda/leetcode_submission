/*
 * 1446_Consecutive_Characters.cxx
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

int maxPower(std::string s) {
    int len = s.size();
    int max = 1;
    int compute = 0;
    char compare_char = s[0];
    for (int i = 0; i < len; i++) {
        if (s[i] == compare_char) {
            compute++;
        } else {
            if (max < compute) {
                max = compute;
            }
            compute = 1;
            compare_char = s[i];
        }
    }
    if (max < compute) {
        max = compute;
    }
    return max;
}

int main(int argc, char** argv) {
    std::string s = "";

    std::cout << "\n" << maxPower(s) << std::endl;
    return 0;
}
