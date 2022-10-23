/*
 * 1461_Check.cxx
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
    bool hasAllCodes(string s, int k) {
        if(k > s.size()){
            return false;
        }
        long t = pow(2,k);        
        vector<bool> dict(t,0);
        for(int i = 0 ; i < s.size()-k+1 ; ++i){
            dict[stoi(s.substr(i,k), nullptr, 2)] = 1;            
        }        
        return accumulate(dict.begin(),dict.end(),0L) == t;
    }

int main(int argc, char **argv)
{
	
	return 0;
}

