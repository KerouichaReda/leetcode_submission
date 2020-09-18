/*
 * 165_Compare_Version_Numbers.cxx
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


    int compareVersion(string version1, string version2) 
    {
    std::replace( version1.begin(), version1.end(), '.', ' ');
    std::replace( version2.begin(), version2.end(), '.', ' ');
    istringstream s1(version1), s2(version2);
    while(1) 
    {
        int n1,n2;
        if (!(s1 >> n1) ) 
            n1 = 0;
        
        if (!(s2 >> n2) ) 
            n2 = 0;
        
        if (! s1 && ! s2) 
            return 0;
        
        if (n1<n2) 
            return -1;
        
        if (n1>n2) 
            return 1;
    }
}
    
int main(int argc, char **argv)
{
	
	return 0;
}

