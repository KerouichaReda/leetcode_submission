/*
 * 1680_Concatenation_of_Consecutive_Binary_Numbers.cxx
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
int concatenatedBinary(int n) {
	long  result = 0 ;
	int temp ;  
		for (int i = 1 , bitl ; i <= n ; i++){
			temp = i;
			bitl = 0;
			while(temp > 0){            
				bitl++ ;            
				temp >>=  1;            
			}
		result = ((result << bitl) %  1000000007 ) + i;
		}
	return result ;
}


int main(int argc, char **argv)
{
	//int n = 5000;
	for(int n = 1; n <500 ;n++)
	std::cout << concatenatedBinary(n) << std::endl; 
	
	return 0;
}

