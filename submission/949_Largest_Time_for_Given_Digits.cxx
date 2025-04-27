/*
 * 949_Largest_Time_for_Given_Digits.cxx
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
string largestTimeFromDigits(vector<int>& A) {
    int t[24];
    int max = 0;
    bool found = false;
    std::string result;

    for (int i = 0; i < 24; i++) {
        t[i] = A[0] * 1000 + A[1] * 100 + A[2] * 10 + A[3];
        // std::cout<<t[i]<<std::endl;
        next_permutation(A.begin(), A.end());
    }

    for (int i = 0; i < 24; i++) {
        if (t[i] <= 2359 && t[i] >= 0 && ((t[i] % 100) / 10) < 6 && t[i] >= max) {
            max = t[i];
            found = true;
        }
    }
    if (found) {
        result = std::to_string(max);
        if (result.length() == 3)
            result = "0" + result;
        else if (result.length() == 2)
            result = "00" + result;
        else if (result.length() == 1)
            result = "000" + result;
        return result.substr(0, 2) + ":" + result.substr(2, 2);
    } else {
        return result;
    }
}

#include <iostream>

int main(int argc, char** argv) { return 0; }
