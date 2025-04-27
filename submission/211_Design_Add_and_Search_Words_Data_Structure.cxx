/*
 * 211_Design_Add_and_Search_Words_Data_Structure.cxx
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
#include <vector>
#include <string>

class WordDictionary {
   public:
    /** Initialize your data structure here. */
    WordDictionary() { root = new TrieNode(); }
    void addWord(std::string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (curr->child[index] == nullptr) {
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr->end_of_string = true;
    }

    bool search(std::string word) { return search_util(root, 0, word); }
    struct TrieNode {
        std::vector<TrieNode*> child;
        bool end_of_string;
        TrieNode() : end_of_string(false) { child = std::vector<TrieNode*>(26, nullptr); }
    } * root;
    bool search_util(TrieNode* root, int index, std::string& word) {
        if (root == nullptr) {
            return false;
        }
        if (root != nullptr && index == (int)(word.length())) {
            return root->end_of_string;
        }
        bool solution = false;
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                solution = solution || search_util(root->child[i], index + 1, word);
            }
        } else {
            int p = word[index] - 'a';
            solution = solution || search_util(root->child[p], index + 1, word);
        }
        return solution;
    }
};

int main(int argc, char** argv) { return 0; }
