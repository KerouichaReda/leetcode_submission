/*
 * 720_Longest_Word_in_Dictionary.cxx
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

class Solution {
   public:
    string longestWord(vector<string>& words) {
        Trie* root = new Trie();
        int size = 0;
        for (string s : words) {
            insert(root, s);
        }
        string solution = string{};
        for (string s : words) {
            if (consectutive(root, s)) {
                if (s.size() > solution.size()) {
                    solution = s;
                } else if (s.size() == solution.size() && s < solution) {
                    solution = s;
                }
            }
        }
        return solution;
    }
    struct Trie {
        std::vector<Trie*> child;
        bool end_of_string;
        Trie() : end_of_string(false) { child = std::vector<Trie*>(26, nullptr); }
    };
    bool consectutive(Trie* root, std::string key) {
        Trie* curr = root;
        for (int i = 0; i < (int)key.length(); ++i) {
            int index = key[i] - 'a';
            if (!curr->child[index]->end_of_string) {
                return false;
            }
            curr = curr->child[index];
        }
        return true;
    }
    void insert(Trie* root, std::string key) {
        Trie* curr = root;
        for (int i = 0; i < (int)key.length(); ++i) {
            int index = key[i] - 'a';
            if (curr->child[index] == nullptr) {
                curr->child[index] = new Trie();
            }
            curr = curr->child[index];
        }
        curr->end_of_string = true;  // last node as leaf;
    }
};

int main(int argc, char** argv) { return 0; }
