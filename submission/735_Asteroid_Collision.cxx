/*
 * 735_Asteroid_Collision.cxx
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
#include <list>
#include <vector>

std::vector<int> asteroidCollision(std::vector<int>& asteroids) {
    std::vector<int> solution;
    std::list<int> right;
    int length = asteroids.size();

    for (int i = 0; i < length; i++) {
        if (right.empty() && asteroids[i] < 0) {
            solution.push_back(asteroids[i]);
        }
        if (asteroids[i] > 0) {
            right.push_back(asteroids[i]);
        } else if (!right.empty() && asteroids[i] < 0) {
            solution.push_back(asteroids[i]);
            while (!right.empty()) {
                if (right.back() == -asteroids[i]) {
                    right.pop_back();
                    solution.pop_back();
                    break;
                } else if (right.back() > -asteroids[i]) {
                    solution.pop_back();
                    break;
                } else {
                    right.pop_back();
                }
            }
        }
    }
    for (int n : right) {
        solution.push_back(n);
    }
    return solution;
}

int main(int argc, char** argv) {
    std::vector<int> asteroids = {-2, -1, 1, 2};

    for (int n : asteroidCollision(asteroids)) std::cout << n << " ";
    std::cout << std::endl;
    return 0;
}
