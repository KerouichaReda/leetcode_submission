/*
 * 648_Replace_Words.cxx
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
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (string s : dictionary) {
            insert(root, s);
        }
        stringstream checkline(sentence);
        string intermediate;
        string solution = string{};
        while (getline(checkline, intermediate, ' ')) {
            pair<bool, int> s = search(root, intermediate);
            solution += ((s.first) ? intermediate.substr(0, s.second) : intermediate) + ' ';
        }
        solution.pop_back();
        return solution;
    }

   private:
    struct TrieNode {
        std::vector<TrieNode*> child;
        bool end_of_string;
        TrieNode() : end_of_string(false) { child = std::vector<TrieNode*>(26, nullptr); }
    };
    void insert(TrieNode* root, std::string key) {
        TrieNode* curr = root;
        for (int i = 0; i < (int)key.length(); ++i) {
            int index = key[i] - 'a';
            if (curr->child[index] == nullptr) {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->end_of_string = true;  // last node as leaf;
    }
    pair<bool, int> search(TrieNode* root, std::string key) {
        TrieNode* curr = root;
        int i;
        for (i = 0; i < (int)key.length(); ++i) {
            int index = key[i] - 'a';
            if (curr->end_of_string == true) {
                return make_pair(true, i);
            }
            if (curr->child[index] == nullptr) {
                return make_pair(false, -1);
            }
            curr = curr->child[index];
        }
        return (curr != nullptr && curr->end_of_string == true) ? make_pair(true, i) : make_pair(false, -1);
    }
};

int main(int argc, char** argv) { return 0; }
