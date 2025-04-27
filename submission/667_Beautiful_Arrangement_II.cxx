/*
 * 667_Beautiful_Arrangement_II.cxx
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
#include <unordered_set>
std::ostream& operator<<(std::ostream& os, std::vector<int> const& v) {
    for (const int& s : v) os << s << ' ';
    return os << std::endl;
}

std::vector<int> constructArray(int n, int k) {
    std::vector<int> solution;
    std::unordered_set<int> s;
    int coef = 1;
    int pre = 1;
    int element;
    solution.push_back(1);
    for (int i = 2; i <= n; i++) {
        std::cout << i << " " << k << " " << coef << " " << pre << std::endl;
        if (k > 1 || coef < 0) {
            element = pre + k * coef;
            if (k > 1) k--;
            coef *= -1;
        } else {
            element = pre + k;
        }
        while (s.count(element)) {
            element++;
        }
        solution.push_back(element);
        s.insert(element);
        pre = element;
    }
    return solution;
}

int main(int argc, char** argv) {
    std::cout << constructArray(6, 5);
    return 0;
}
