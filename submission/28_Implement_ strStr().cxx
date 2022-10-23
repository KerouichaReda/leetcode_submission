/*
 * 28_Implement_ strStr().cxx
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
#include <string>

int strStr(std::string haystack, std::string needle) {
	if(needle.empty())
		return 0;
	if( needle.size() > haystack.size())
		return -1;
	bool flag = true;
	for(int i = 0 ; i < haystack.size()-needle.size()+1;i++)
		if(haystack[i] == needle[0]){
			flag = true;
			for(int j = 1 ;j < needle.size();j++){
				if(haystack[i+j] != needle[j] ){
					flag = false;
					break;
				}
			}
			if(flag)
				return i;
			}
	return -1;        
}

int main(int argc, char **argv)
{
	
	return 0;
}

