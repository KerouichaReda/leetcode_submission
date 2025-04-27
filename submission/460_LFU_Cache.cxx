/*
 * 460_LFU_Cache.cxx
 *
 * Copyright 2022 RedaKerouicha <redakerouicha@localhost>
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
 * https://leetcode.com/problems/lfu-cache/discuss/937737/C%2B%2B%3A-O(1)-time-complexity-with-algorithm
 */

#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

using list_itr = std::list<int>::iterator;
using count_t = int;

struct Node {
    Node(int _value, list_itr _itr) : value_(_value), itr_(_itr) {}
    int value_;
    list_itr itr_;
};

class LFUCache {
   public:
    LFUCache(int _capacity) : capacity_(_capacity) {}
    int get(int _key) {
        if (cache_.count(_key) == 0) return -1;
        int temp_value = cache_.at(_key).value_;
        int counter = ++frequency_[_key];
        list_itr temp_itr = cache_.at(_key).itr_;
        frequency_list_[counter - 1].erase(temp_itr);
        frequency_list_[counter].push_front(_key);
        cache_.at(_key).itr_ = frequency_list_[counter].begin();
        return temp_value;
    }

    void put(int _key, int _value) {
        int counter = ++frequency_[_key];
        frequency_list_[counter].push_front(_key);
        cache_.insert(std::make_pair(_key, Node(_value, frequency_list_[counter].begin())));
    }
    void evict() {}
    void erase(int _key) {}

   private:
    int capacity_{};
    int lowest_frequency_{0};
    std::unordered_map<int, Node> cache_;
    std::unordered_map<int, int> frequency_;
    std::unordered_map<count_t, std::list<int>> frequency_list_;
};

int main(int argc, char** argv) {
    LFUCache lfu(5);
    return 0;
}
