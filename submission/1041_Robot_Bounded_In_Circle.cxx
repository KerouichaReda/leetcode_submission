/*
 * 1041_Robot_Bounded_In_Circle.cxx
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
#include <string>

bool isRobotBounded(std::string instructions) {
    int pos_x = 0, pos_y = 0, rot = 0;                   // position and rotation
    int mov[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // movement matrix

    for (int i = 0; i < (int)instructions.size(); i++) {
        switch (instructions[i]) {
            case 'G':
                pos_x += mov[rot][0];
                pos_y += mov[rot][1];
                break;
            case 'L':
                rot = (rot + 1) % 4;
                break;
            case 'R':
                rot = (rot + 3) % 4;
                break;
        }
    }
    return (pos_x == 0 && pos_y == 0) || rot > 0;
}

int main(int argc, char** argv) {
    std::string inst = "GGRGRGLG";
    std::cout << isRobotBounded(inst) << std::endl;
    return 0;
}
