/*
 * 216_Combination_Sum_III.cxx
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

/*class Solution {
public:
  void combination(vector<vector<int>>& result, vector<int> sol, int k, int n) {
    if (sol.size() == k && n == 0) { result.push_back(sol); return ; }
    if (sol.size() < k) {
      for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i) {
        if (n - i < 0) break;
        sol.push_back(i);
        combination(result, sol, k, n - i);
        sol.pop_back();
      }
    }
  }

        vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> sol;
    combination(result, sol, k, n);
    return result;
  }
};*/

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> sol;
    vector<int> comb(k);
    bool dup = true;
    int sum = 0, c;
    std::vector<int>::iterator f0;
    std::vector<vector<int>>::iterator f1;
    for (int i = pow(10, k - 1); i < pow(10, k); i++) {
        c = i;
        sum = 0;
        dup = true;
        for (int j = 0; j < k; j++) {
            comb[j] = c % 10;
            sum += c % 10;
            c = c / 10;
        }
        std::sort(comb.begin(), comb.end());
        f0 = std::find(comb.begin(), comb.end(), 0);
        f1 = std::find(sol.begin(), sol.end(), comb);
        for (int j = 0; j < k; j++) {
            for (int l = j + 1; l < k; l++) {
                if (comb[j] == comb[l]) {
                    dup = false;
                }
            }
        }
        if (sum == n && f0 == comb.end() && f1 == sol.end() && dup) {
            // std::cout<<i<<'\n';
            sol.push_back(comb);
        }
    }

    return sol;
}

int main(int argc, char** argv) { return 0; }
