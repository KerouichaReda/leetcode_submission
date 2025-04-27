/*
 * 821_Shortest_Distance_to_a_Character.cxx
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

vector<int> shortestToChar(string s, char c) {
    unsigned position = 0, previous;
    vector<int> solution;
    for (position = 0; s[position] != c && position < s.size(); position++)
        ;
    previous = position;
    for (int i = 0; i < s.size(); i++) {
        solution.push_back(position - i < i - previous ? position - i : i - previous);
        if (position - i == 0) {
            previous = position;
            for (position = i + 1; s[position] != c && position < s.size(); position++)
                ;
            if (position == s.size()) position = previous;
        }
    }
    return solution;
}

int main(int argc, char** argv) { return 0; }
