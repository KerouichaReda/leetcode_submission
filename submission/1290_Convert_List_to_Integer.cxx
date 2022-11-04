/*
 * 1290_Convert_List_to_Integer.cxx
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
#include "listnode.hpp"

int getDecimalValue(ListNode* head) {
    int solution = 0;
    while (head != nullptr) {
        solution = (solution << 1) + head->val;
        head = head->next;
    }
    return solution;
}

int main(int argc, char** argv) {
    std::cout << getDecimalValue(nullptr) << std::endl;
    return 0;
}
