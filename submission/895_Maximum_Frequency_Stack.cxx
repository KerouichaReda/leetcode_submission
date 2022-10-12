/*
 * 895_Maximum_Frequency_Stack.cxx
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
#include <stack>
#include <unordered_map>
#include <algorithm>

class FreqStack {
public:
    FreqStack() {
        
    }  

    void push(int x) {
        maxfreq = std::max(maxfreq, ++freq[x]);
        m[freq[x]].push(x);
    }

    int pop() {
        int x = m[maxfreq].top();
        m[maxfreq].pop();
        if (!m[freq[x]--].size()){
			maxfreq--;
		}
        return x;
    }
private:
    int maxfreq = 0; 
    std::unordered_map<int, int> freq;
    std::unordered_map<int, stack<int>> m;
};

int main(int argc, char **argv)
{
	
	return 0;
}

