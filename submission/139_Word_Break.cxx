/*
 * 139_Word_Break.cxx
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
#include <string>
#include <vector>
#include <algorithm>
bool wordBreak(std::string s, std::vector<std::string>& wordDict) 
{

	std::sort(wordDict.begin(),wordDict.end());
	
	for(std::string word:wordDict)
	{		
		while(s.find(word)!=std::string::npos)
		{			
			s.erase(s.find(word),(int)word.size());
		}
	}
	
	return s.empty();
	
}
int main(int argc, char **argv)
{
	std::string s= "aaaaaaa";
	std::vector<std::string> dic = {"aaaa","aa"};
	
	std::cout<<wordBreak(s,dic)<<std::endl;
	return 0;
}

