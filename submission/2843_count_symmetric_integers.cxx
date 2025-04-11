/*
 * 2843_count_symmetric_integers.cxx
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

int countSymmetricIntegers(int low, int high) {
    int result{0};
    for (int i = low; i <= high; i++) {
        std::string temp = std::to_string(i);
        result += temp.size() == 2
                      ? temp[0] == temp[1]
                      : temp.size() == 4
                            ? (temp[0] + temp[1]) == (temp[2] + temp[3])
                            : 0;
    }
    return result;
}

int main(int argc, char** argv) {
    std::cout << countSymmetricIntegers(100, 1000) << std::endl;
    return 0;
}
