/*
 * 146_LRU_Cache.cxx
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
#include <list>
#include <unordered_map>
#include <utility>
#include <string>

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    int get(int key) {
	    if(cache_map.count(key)){
            std::list<std::pair<int,int>>::iterator itr = cache_map[key];
            int value = (*itr).second;
            cache_list.erase(itr);
            cache_list.push_front(std::make_pair(key,value));
            cache_map[key] = cache_list.begin();
            return value;
        }
        return -1;
    }    
    void put(int key, int value) {
    	if(!cache_map.count(key)){
            if((int)cache_map.size() >= capacity_){
                evict();
            }
            cache_list.push_front(std::make_pair(key,value));
            cache_map[key] = cache_list.begin();
        }else{
            std::list<std::pair<int,int>>::iterator itr = cache_map[key];
            cache_list.erase(itr);
            cache_list.push_front(std::make_pair(key,value));
            cache_map[key] = cache_list.begin();
        }
    }
private:
    std::unordered_map<int,std::list<std::pair<int,int>>::iterator> cache_map;
    std::list<std::pair<int,int>> cache_list;
    int capacity_;
    void evict(){
        int key = (cache_list.back()).first;
        cache_map.erase(key);
        cache_list.pop_back();
    }
};


int main(int argc, char **argv)
{
	
	return 0;
}

