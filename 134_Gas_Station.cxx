/*
 * 134_Gas_Station.cxx
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

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int tank=0;
        int sz=(int)gas.size();
        
        for (int i=0;i<sz;i++)
        {
            std::cout<<"i= "<<i<<std::endl;
            tank=gas[i];
            for (int j=1;j<sz;j++)
            {
                tank+=gas[(i+j)%sz]-cost[(i+j-1)%sz];
                std::cout<<tank<<std::endl;
                if(tank<=0)
                    break;
            }
            if(tank>gas[i])
                return i;
            
        }
        
        return -1;
    }

int main(int argc, char **argv)
{
	
	return 0;
}

