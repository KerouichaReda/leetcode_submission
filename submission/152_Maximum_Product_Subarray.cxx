/*
 * 152_Maximum_Product_Subarray.cxx
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
/*
 *
 * int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.empty()) return 0;

        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;

        for (int n: nums) {
            if (n < 0) {
                // Swap max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            best = max(best, maxProd);
        }

        return best;
    }
 */
int maxProduct(vector<int>& nums) {
    int max = INT_MIN;
    int product = 1;
    for (int i = 0; i < nums.size(); i++) {
        product = 1;
        for (int j = i; j < nums.size(); j++) {
            product *= nums[j];
            if (product > max) max = product;
        }
    }
    return max;
}

int main(int argc, char** argv) { return 0; }
