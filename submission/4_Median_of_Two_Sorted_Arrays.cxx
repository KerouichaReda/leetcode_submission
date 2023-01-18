/*
 * 4_Median_of_Two_Sorted_Arrays.cxx
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
 * https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    if (len1 == 0) {
        return (len2 % 2 == 0)
                   ? (double)(nums2[len2 / 2 - 1] + nums2[len2 / 2]) / 2
                   : nums2[(len2 - 1) / 2];
    }
    if (len2 == 0) {
        return (len1 % 2 == 0)
                   ? (double)(nums1[len1 / 2 - 1] + nums1[len1 / 2]) / 2
                   : nums1[(len1 - 1) / 2];
    }
    int len = len1 + len2;
    int index1 = 0;
    int index2 = 0;
    double med;
    vector<int> result(len);
    for (int index = 0; index < len; ++index) {
        if (index1 == len1) {
            result[index] = (nums2[index2]);
            index2++;
            continue;
        }
        if (index2 == len2) {
            result[index] = (nums1[index1]);
            index1++;
            continue;
        }
        if (nums1[index1] <= nums2[index2]) {
            result[index] = (nums1[index1]);
            index1++;

        } else {
            result[index] = (nums2[index2]);
            index2++;
        }
    }
    std::cout << (len % 2 == 0);
    med = (len % 2 == 0) ? ((double)(result[len / 2 - 1] + result[len / 2])) / 2
                         : result[(len - 1) / 2];
    return med;
}
}
;
#include <iostream>

int main(int argc, char** argv) { return 0; }
