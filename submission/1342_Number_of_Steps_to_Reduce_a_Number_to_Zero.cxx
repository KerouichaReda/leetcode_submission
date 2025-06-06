/*
 * 1342_Number_of_Steps_to_Reduce_a_Number_to_Zero.cxx
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
int numberOfSteps(int num) {
    int steps = 0;
    while (num) {
        ++steps;
        num = num & 1 ? num & 0x7FFFFFFE : num >> 1;
    }
    return steps;
}
int main(int argc, char** argv) { return 0; }
