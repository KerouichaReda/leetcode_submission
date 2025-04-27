/*
 * 1641_Count_Sorted_Vowel_Strings.cxx
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
#include <vector>

int countVowelStrings(int n) {
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(6));
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k <= 5; ++k) dp[i][k] = dp[i][k - 1] + (i > 1 ? dp[i - 1][k] : 1);
    return dp[n][5];
}

int main(int argc, char** argv) {
    int n = 100;
    std::cout << countVowelStrings(n) << std::endl;
    return 0;
}
