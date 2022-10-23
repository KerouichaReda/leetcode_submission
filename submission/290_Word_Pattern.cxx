/*
 * 290_Word_Pattern.cxx
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
 * https://leetcode.com/problems/word-pattern/
 */


#include <iostream>
#include <sstream>
/*
 * map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}*/
 bool wordPattern(string pattern, string str) 
    {
       std::stringstream input(str);
        std::string words[26],word;
        
        int space=0;
        bool test[26];
        for(int i=0;i<26;i++)
        {
            test[i]=false;
        }
        for(int i=0;i<str.length();i++)
        {
            if(str[i]==' ')
                space++;
        }
        if((space+1)!=(int)pattern.length())
            return false;
        for (int i=0;i<pattern.length();i++)
        {   
            input>>word;
            if(!test[pattern[i]-'a'])
            {
                for(int j=0;j<26;j++)
                {
                    if(words[j]==word)
                        return false;
                }
                words[pattern[i]-'a']=word;
                test[pattern[i]-'a']=true;
            }
            else
            {
                if(words[pattern[i]-'a']!=word)
                {
                    return false;
                }
            }
        }

        return true;
    }
int main(int argc, char **argv)
{
	std::string pattern="abba";
	std::string str="dog cat cat dog";
	std::cout<<wordPattern(pattern,str)<<std::endl;
	
	return 0;
}

