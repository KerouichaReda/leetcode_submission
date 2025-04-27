/*
 * 832_Flipping_an_Image.cxx
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
#include <vector>

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& A) {
    int col = static_cast<int>(A[0].size());
    int row = static_cast<int>(A.size());
    std::vector<std::vector<int>> result(row, std::vector<int>(col));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result[i][j] = !(A[i][col - 1 - j]);
        }
    }

    return result;
}

int main(int argc, char** argv) {
    std::vector<std::vector<int>> A = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    std::vector<std::vector<int>> B = flipAndInvertImage(A);

    for (std::vector<int> row : B) {
        for (int e : row) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
