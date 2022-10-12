/*
 * 179_Largest_Number.cxx
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

std::string largestNumber(std::vector<int>& nums) 
    {
        std::vector<std::string> num;
        std::string sol="";        
        for(int n : nums)
        {               
             num.push_back(std::to_string(n));
        }
       
        std::sort(num.begin(),num.end(),[](string &s1, string &s2){ return s1+s2<s2+s1; });        
        
        for(int i=num.size()-1;i>=0;i--)
        {           
            sol+=num[i];
        }
        int i;
        
        while(sol[0]=='0' && sol.length()>1)
            sol.erase(0,1);
        
        return sol;
    }

int main(int argc, char **argv)
{
	
	return 0;
}

