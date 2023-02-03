/*
 * 6_ ZigZag_Conversion.cxx
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
 * https://leetcode.com/problems/zigzag-conversion/
 */
/*
 * string convert(string s, int nRows) {

    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)
            step = 1;
        else if (row == nRows - 1)
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
}
*/

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

std::string convert(std::string s, int numRows) {
    if (numRows == 1) return s;
    std::vector<std::string> temp(numRows, std::string{});
    int index{0};
    int increment = 1;
    for (char& c : s) {;
        temp[index].push_back(c);
        index += increment;
        increment = (index == numRows - 1) ? -1 : index == 0 ? 1 : increment;
    }
    return std::accumulate(temp.begin(), temp.end(), std::string{});
}

int main(int argc, char** argv) { return 0; }
