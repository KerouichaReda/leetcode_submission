/*
 * 11_Container_With_Most_Water.cxx
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
#include <algorithm>
#include <vector>


int maxArea(std::vector<int>& height) {
    int area = 0;
    int i = 0, j = height.size() - 1;
    int h;
    while (i < j) {
        h = std::min(height[i], height[j]);
        area = std::max(area, (j - i) * h);
        for(;height[i] <= h && i < j; i++);
        for(;height[j] <= h && i < j; j--);
        
    }
    return area;
}

int main(int argc, char **argv)
{
	std::vector<int> heights = {4,3,2,1,4};
	std::cout << maxArea(heights) << std::endl;
	return 0;
}

