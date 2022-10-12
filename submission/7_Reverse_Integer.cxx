/*
 * 7_Reverse_Integer.cxx
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
 * https://leetcode.com/problems/reverse-integer/
 * 
 */

    int reverse(int x) 
    {
        if (x<=INT_MIN || x>=INT_MAX-1)
        {    
            return 0;
        }
        long solution=0;
        int abs=(x<0)?-1:1;
        long val=x*abs;
        int power=1; 
        
        while(val>0)
            {
                solution=solution*10+val%10;
                val=val/10;
                power++;                
            }
     
        if(power>=11 && solution>2147483644 )
            return 0;
            
        return solution*abs;
    }


#include <iostream>

int main(int argc, char **argv)
{


	return 0;
}

