/*
 * 1249_Minimum_Remove_to_Make_Valid_Parentheses.cxx
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
#include <string>
#include <stack>

std::string minRemoveToMakeValid(std::string s) {
    std::stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') st.push(i);
        if (s[i] == ')') {
            if (!st.empty())
                st.pop();
            else
                s[i] = '*';
        }
    }
    while (!st.empty()) {
        s[st.top()] = '*';
        st.pop();
    }
    s.erase(std::remove(s.begin(), s.end(), '*'), s.end());
    return s;
}

int main(int argc, char** argv) { return 0; }
