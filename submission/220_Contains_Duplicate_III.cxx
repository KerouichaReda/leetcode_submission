/*
 * 220_Contains_Duplicate_III.cxx
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
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    vector<pair<int, int>> dup;
    for (int i = 0; i < nums.size(); i++) {
        dup.push_back(make_pair(nums[i], i));
    }

    sort(dup.begin(), dup.end());
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (dup[i].first + t >= dup[j].first) {
                if (abs(dup[i].second - dup[j].second) <= k) {
                    return true;
                }
            } else {
                break;
            }
        }
    }

    return false;
}
int main(int argc, char** argv) { return 0; }
