/*
 * 3_Longest_Substring_Without_Repeating_Characters.cxx
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
 * 
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */
int lengthOfLongestSubstring(string s) {
        if(s=="")
        {
            return 0;
        }
        int max=0;
        int inc=0;
        int alp[256];
        for(int i=0;i<256;i++)
        {
            alp[i]=0;
        }
        for (int i=0; i<(int)s.size();i++ )
        {
           
            for(int j=i+1;j<(int)s.size();j++)
            {
                //std::cout<<s[i]<<" "<<s[j]<<" "<<inc<<" "<<s[j]-'a'<< std::endl;
                
                if (s[i]!=s[j] && alp[(int)s[j]]!=1)
                {
                   // std::cout<<"test"<<std::endl;
                    alp[s[j]]=1;
                    inc++;
                    if(inc>=max)
                    {
                        max=inc;
                    }
                }
                else
                {
                    //std::cout<<"else"<<std::endl;
                    inc=0;
                    break;
                }
                if(j==(int)s.size()-1)
                inc=0;
            }
            
            
            for(int i=0;i<256;i++)
            {
                
                alp[i]=0;
            }
        }
        return max+1;
        
    }

#include <iostream>

int main(int argc, char **argv)
{
	
	return 0;
}

