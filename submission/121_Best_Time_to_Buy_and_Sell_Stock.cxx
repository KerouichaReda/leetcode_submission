/*
 * 121_Best_Time_to_Buy_and_Sell_Stock.cxx
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
#include <vector>
#include <algorithm>


int maxProfit(std::vector<int>& prices) 
    {
        if(prices.empty())
            return 0;
        
        int minPrice,maxPro;
        minPrice=prices[0];
        maxPro=0;
       
        
        for(int i=1;i<(int)prices.size();i++)
        {            
            minPrice = std::min(minPrice,prices[i]);            
            maxPro 	 = std::max(maxPro,prices[i]-minPrice);
        }        
        
        return maxPro;
    }

int main(int argc, char **argv)
{
	std::vector<int> prices= {7,1,5,3,6,4};
	std::cout<<maxProfit(prices)<<std::endl;
	return 0;
}

