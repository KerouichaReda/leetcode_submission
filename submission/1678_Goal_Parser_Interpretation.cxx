/*
 * 1678_Goal_Parser_Interpretation.cxx
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

std::string interpret(std::string &command,unsigned index = 0) {
	if(index <  command.size()){
		if(command[index] == 'G')
			return command[index] + interpret(command,index + 1);
		else if (command[index+1] == ')')
			return 'o' + interpret(command,index+2);
		else {                
			return "al"+interpret(command,index+4);
		}
   } 
	return "";
}

int main(int argc, char **argv)
{
	std::string command{"G()()()()()()()()()()(al)"};	
	std::cout << interpret(command) << std::endl;
	
	return 0;
}

