/*
 * 1094_Car_Pooling.cxx
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

bool carPooling(std::vector<std::vector<int>>& trips, int capacity) 
    {
        int nb_trip=trips.size();
        int total=0;
        bool deposed[nb_trip];
        for(int i=0;i<nb_trip;i++)
            deposed[i]=false;
        
        for(int i=0;i<nb_trip-1;i++)
        {
            for(int j=i+1;j<nb_trip;j++)
            {
                if(trips[j][1]<trips[i][1])
                {
                    std::swap(trips[j],trips[i]);
                }
            }
        }
        
        
        for(int i=0;i<nb_trip;i++)
        {
            total+=trips[i][0];
            for(int j=0;j<i;j++)
            {
                if(trips[i][1]>=trips[j][2] && !deposed[j])
                {
                    deposed[j]=true;
                    total-=trips[j][0];
                }                
            }
            
            if(capacity<total)
                    return false;
        }
        return capacity>=total;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> m;
        for (auto &t : trips)
            m[t[1]] += t[0], m[t[2]] -= t[0];
        for (auto &v : m)
            if ((capacity -= v.second) < 0)
                return false;
        return true;
    }

int main(int argc, char **argv)
{
	
	return 0;
}

