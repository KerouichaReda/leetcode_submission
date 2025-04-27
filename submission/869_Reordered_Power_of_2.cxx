/*
 * 869_Reordered_Power_of_2.cxx
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
class Solution {
   public:
    unordered_map<int, vector<int>> m;
    bool reorderedPowerOf2(int N) {
        if (m.empty()) {
            long p;
            for (int i = 0; i <= 30; i++) {
                p = pow(2, i);
                m[p] = count(p);
            }
        }
        vector<int> num = count(N);
        bool test = false;
        for (pair<int, vector<int>> p : m) {
            test = true;
            for (int i = 0; i < 10; i++) {
                if (num[i] != p.second[i]) {
                    test = false;
                    break;
                }
            }
            if (test) return true;
        }
        return false;
    }
    vector<int> count(long in) {
        vector<int> num(10, 0);
        while (in > 0) {
            num[in % 10]++;
            in /= 10;
        }
        return num;
    }
};
int main(int argc, char** argv) { return 0; }
