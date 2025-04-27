/*
 * 7_Word_Search.cxx
 *
 * Copyright 2022 RedaKerouicha <redakerouicha@localhost>
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
#include <vector>

using grid = std::vector<std::vector<char>>;
int row{};
int col{};
bool dfs(grid& board, int i, int j, std::string& word) {
    if (word.empty()) return true;
    if (i >= row || i < 0 || j >= col || j < 0 || board[i][j] == 0 || word.back() != board[i][j]) return false;
    board[i][j] = 0;
    char temp = word.back();
    word.pop_back();
    bool result = dfs(board, i + 1, j, word) || dfs(board, i - 1, j, word) || dfs(board, i, j + 1, word) ||
                  dfs(board, i, j - 1, word);
    word.push_back(temp);
    board[i][j] = temp;
    return result;
}

bool exist(grid& board, std::string word) {
    row = board.size();
    col = board[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (dfs(board, i, j, word)) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char** argv) { return 0; }
