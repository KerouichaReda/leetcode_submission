/*
 * 554_Brick_Wall.cxx
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

int leastBricks(vector<vector<int>>& wall) {
    unordered_map<int, int> edges;
    int min_bricks = wall.size();
    for (vector<int>row : wall){
        for (int i = 0, width = 0; i < row.size() - 1; ++i){ // skip last brick
            width += row[i];
            edges[width]++;
            int rows =  wall.size() - edges[width];
            min_bricks = std::min(min_bricks, rows);
        }
    }
    return min_bricks;
}

int main(int argc, char **argv)
{
	
	return 0;
}

