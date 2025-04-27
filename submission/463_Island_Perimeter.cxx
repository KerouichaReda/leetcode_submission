/*
 * 463_Island_Perimeter.cxx
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
int islandPerimeter(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int perim = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                perim += 4;
                if (i > 0 && grid[i - 1][j] == 1) perim -= 1;
                if (j > 0 && grid[i][j - 1] == 1) perim -= 1;
                if (i < m - 1 && grid[i + 1][j] == 1) perim -= 1;
                if (j < n - 1 && grid[i][j + 1] == 1) perim -= 1;
            }
        }
    }
    return perim;
}
int main(int argc, char** argv) { return 0; }
