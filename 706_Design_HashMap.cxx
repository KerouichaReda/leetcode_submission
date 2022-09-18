/*
 * 706_Design_HashMap.cxx
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
class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        size = 0;
        bucket_size = 16;
        threshold = 0.8;
        buckets = new list<pair<int,int>>[bucket_size];
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        p = find(key);
        if(p.first){
            (*(p.second)).second = value;
        }else{
            int index = key & (bucket_size-1); 
            buckets[index].push_back(make_pair(key,value));
            ++size;
            load_factor = (double) size / bucket_size;
            if(load_factor > threshold){
                resize();
            }
        }
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        p = find(key);
        if(p.first){
            return (*(p.second)).second;
        }
        return -1;
    }
    
    pair<bool,list<pair<int,int>>::iterator> find(int key){
        index = key & (bucket_size-1);
        for(list<pair<int,int>>::iterator itr = buckets[index].begin() ; itr != buckets[index].end() ; ++itr){
            if((*itr).first == key){
                return make_pair(true,itr);
            }
        }
        return make_pair(false,list<pair<int,int>>::iterator{});
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        p = find(key);
        if(p.first){
            index = key & (bucket_size-1);
            buckets[index].erase(p.second);
            --size;
        }        
    }
    
    void resize(){
        unsigned new_bucket_size = bucket_size * 2;
        list<pair<int,int>> * new_buckets = new list<pair<int,int>>[new_bucket_size];        
        for(int i = 0 ; i < bucket_size ; ++i){            
            for (pair<int,int> key_value : buckets[i]){
                index = key_value.first & (new_bucket_size-1);
                new_buckets[index].push_back(key_value);
            }
        }        
        delete[] buckets;
        buckets = new_buckets;
        bucket_size = new_bucket_size;        
    }
private:
    unsigned bucket_size;
    double load_factor;
    double threshold;
    list<pair<int,int>> *buckets;
    unsigned size;
    pair<bool,list<pair<int,int>>::iterator>  p;
    unsigned index;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
int main(int argc, char **argv)
{
	
	return 0;
}

