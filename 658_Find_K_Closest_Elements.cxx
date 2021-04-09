/*
 * 658_Find_K_Closest_Elements.cxx
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
bool compare(auto a, auto b){
            return a.first == b.first ? a.second > b.second : a.first > b.first ;
        }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>> heap;        
        for(int i = 0 ; i < arr.size() ; ++i){
            heap.push_back({abs(arr[i]-x),arr[i]});
        }
        vector<int> solution;
        make_heap(heap.begin(),heap.end(), compare );
        for(int i = 0 ; i < k ; i++){
            pop_heap(heap.begin(),heap.end(), compare);
            solution.push_back(heap.back().second);
            heap.pop_back();
        }
        sort(solution.begin(),solution.end());
        return solution;        
    }
int main(int argc, char **argv)
{
	
	return 0;
}

