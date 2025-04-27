/*
 * 376_Wiggle_Subsequence.cxx
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

int wiggleMaxLength(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
        return 0;
    }
    vector<int> up(size, 0);
    vector<int> down(size, 0);
    up[0] = 1;
    down[0] = 1;
    for (int i = 1; i < size; ++i) {
        if (nums[i] > nums[i - 1]) {
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];
        } else if (nums[i] < nums[i - 1]) {
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        } else {
            up[i] = up[i - 1];
            down[i] = down[i - 1];
        }
    }
    return max(up[size - 1], down[size - 1]);
}

int main(int argc, char** argv) { return 0; }
