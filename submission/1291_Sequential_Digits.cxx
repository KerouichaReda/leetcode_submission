/*
 * 1291_Sequential_Digits.cxx
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
vector<int> sequentialDigits(int low, int high) {
    // BFS Solution
    queue<int> digit;
    vector<int> solution;
    int f;
    int num;
    for (int i = 1; i <= 9; i++) {
        digit.push(i);
    }
    while (!digit.empty()) {
        f = digit.front();
        digit.pop();
        if (f <= high && f >= low) {
            solution.push_back(f);
        }
        if (f > high) break;
        num = f % 10;
        if (num < 9) {
            digit.push(f * 10 + (num + 1));
        }
    }
    return solution;
}

vector<int> sequentialDigits(int low, int high) {
    std::vector<int> solution;
    int num;
    for (int n = 2; n < 10; n++) {
        for (int i = 1; i <= 10 - n; i++) {
            num = 0;
            for (int j = 0; j < n; j++) {
                num = num * 10 + (i + j);
            }
            if (num >= low && num <= high) solution.push_back(num);
        }
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
