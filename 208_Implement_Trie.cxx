/*
 * 208_Implement_Trie.cxx
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
 * TrieNode
 */


#include <iostream>

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *curr = root ;
        for(int i = 0; i < word.size(); ++i){
            int index = word[i] - 'a';
            if(curr->child[index] == nullptr){
                curr->child[index] = new TrieNode();
            }
            curr = curr->child[index];
        }
        curr-> end_of_string = true;
    }    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *curr = root ;
        for(int i = 0; i < word.size(); ++i){
        int index = word[i] - 'a';
            if(curr->child[index] == nullptr){
                return false;
            }
            curr = curr->child[index];
        }
        return curr != nullptr && curr->end_of_string == true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *curr = root ;
        for(int i = 0; i < prefix.size(); ++i){
        int index = prefix[i] - 'a';
            if(curr->child[index] == nullptr){
                return false;
            }
            curr = curr->child[index];
        }
         return curr != nullptr ;
    }
    private:
    struct  TrieNode{
	std::vector<TrieNode*> child;
	bool end_of_string;
	TrieNode() : end_of_string(false)  {
		child =std::vector<TrieNode*>(26,nullptr); }
    } *root;
};


int main(int argc, char **argv)
{
	
	return 0;
}

