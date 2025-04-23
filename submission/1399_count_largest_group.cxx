/*
 * 1399_count_largest_group.cxx
 *
 * Copyright 2025 - present RedaKerouicha <reda_kerouicha@outlook.com>
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
#include <set>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

int digit_sum(int n) { return n == 0 ? 0 : (n % 10) + digit_sum(n / 10); }
int countLargestGroup(int n) {
    std::map<int, std::vector<int>> m_;
    std::map<int, int> c_;
    for (int i = 1; i <= n; ++i) {
        m_[digit_sum(i)].push_back(i);
    }
    int solution{0};
    for (std::pair<const int, std::vector<int>>& p : m_) {
        ++c_[p.second.size()];
    }
    return (*c_.crbegin()).second;
}

int main(int argc, char** argv) {
    std::cout << countLargestGroup(13) << std::endl;

    return 0;
}
