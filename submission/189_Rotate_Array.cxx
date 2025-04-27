/*
 * 189_Rotate_Array.cxx
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
// First function doesn't handle the long sequene
void rotate(vector<int>& nums, int k) {
    if (nums.empty()) {
        return;
    }

    int rot = k % nums.size();

    if (nums.size() == 1 || rot == 0) {
        return;
    }

    for (int i = 0; i < rot; i++) {
        rotate_by_one(nums);
    }
}

void rotate_by_one(vector<int>& nums) {
    int temp = nums[nums.size() - 1];
    for (int i = nums.size() - 1; i > 0; i--) {
        nums[i] = nums[i - 1];
    }
    nums[0] = temp;
}
// temp vector
void rotate(vector<int>& nums, int k) {
    if (nums.empty()) {
        return;
    }
    int nums_size = nums.size();
    int rot = k % nums_size;

    if (nums_size == 1 || rot == 0) {
        return;
    }

    std::vector<int> temp_vec;

    for (int i = 0; i < rot; i++) {
        temp_vec.push_back(nums[nums_size - rot + i]);
    }

    for (int i = nums_size - 1; i >= rot; i--) {
        nums[i] = nums[i - rot];
    }

    for (int i = 0; i < rot; i++) {
        nums[i] = temp_vec[i];
    }
}

int main(int argc, char** argv) { return 0; }
