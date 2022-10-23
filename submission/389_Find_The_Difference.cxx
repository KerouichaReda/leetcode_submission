/*
 * 389_Find_The_Difference.cxx
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
char findTheDifference(string s, string t) 
    {
        std::vector<int> l(26,0),n(26,0);
        for(int i=0;i<s.length();i++)
        {
            l[s[i]-'a']++; 
            n[t[i]-'a']++;
        }
        n[t[t.length()-1]-'a']++;
        for(int i=0;i<26;i++)
        {
           if(n[i]>l[i])
               return (char)('a'+i);            
        }
        return NULL;
    }
    
    char findTheDifference(string s, string t) 
    {
        int i=0,l=0,n=0;
        for(i=0;i<s.length();i++)
        {
            l+=s[i]-'a'; 
            n+=t[i]-'a';
        }
        n+=t[i]-'a';
       
        return (char)n-l+'a';
    }
int main(int argc, char **argv)
{
	
	return 0;
}

