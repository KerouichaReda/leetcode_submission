/*
 * 9_Palindrome_Number.cxx
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

bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int sum = 0;
    while (x > sum) {
        sum = sum * 10 + x % 10;
        x = x / 10;
    }
    return (x == sum) || (x == sum / 10);
}

int main(int argc, char** argv) {
    std::cout << "is palindrome" << isPalindrome(1221) << std::endl;
    return 0;
}
