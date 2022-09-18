/*
 * 890_Find_and_Replace_Pattern.cxx
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

vector<string> findAndReplacePattern(vector<string>& words, string p) {
	vector<string> solution;        
	for(string w : words){
		unordered_map<char,char> word_to_pat;
		unordered_map<char,char> pat_to_word;
		int i;
		for(i = 0 ; i < p.size() ;++i ){
			if(!word_to_pat.count(w[i]) && !pat_to_word.count(p[i])){
				word_to_pat[w[i]]=p[i];
				pat_to_word[p[i]]=w[i];
			}else if(word_to_pat[w[i]] != p[i] || pat_to_word[p[i]] != w[i]){
				break;
			}                
		}
		if(i==w.size())
		solution.push_back(w);
	}
	return solution;
}
int main(int argc, char **argv)
{
	
	return 0;
}

