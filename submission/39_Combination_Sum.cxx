/*
 * 39_Combination_Sum.cxx
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

void combinationSum(vector<int>& candidates, vector<int>& temp, int target, int index, vector<vector<int>>& solution) {
    if (target == 0) {
        solution.push_back(temp);
        return;
    }
    if (target < 0) return;

    for (int i = index; i < candidates.size(); ++i) {
        temp.push_back(candidates[i]);
        int reminder = target - candidates[i];
        combinationSum(candidates, temp, reminder, i, solution);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> solution;
    vector<int> temp;
    combinationSum(candidates, temp, target, 0, solution);
    return solution;
}

int main(int argc, char** argv) { return 0; }
