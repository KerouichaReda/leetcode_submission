/*
 * 13_Roman_to_Integer.cxx
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
int romanToInt(std::string s) {
	struct romandata_t { 
		unsigned int value; 
		char const* numeral;
		int len; 
	};
	const struct romandata_t romandata[] =
	{
		{1000, "M",1}, {900, "CM",2},
		{ 500, "D",1}, {400, "CD",2},
		{ 100, "C",1}, { 90, "XC",2},
		{  50, "L",1}, { 40, "XL",2},
		{  10, "X",1}, {  9, "IX",2},
		{   5, "V",1}, {  4, "IV",2},
		{   1, "I",1}, {  0, nullptr,0}             
	};
	unsigned index = 0,value = 0;
	while(index < s.length()){
		for(int i = 0; i < 14; i++){
			if(s.substr(index,romandata[i].len) == romandata[i].numeral){
				value += romandata[i].value;
				index += romandata[i].len;
				break;
			}
		}
	}
	return value;
}



int main(int argc, char **argv)
{
	std::string str = "MIII";
	std::cout << romanToInt(str) << std::endl; 
	return 0;
}

