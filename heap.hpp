/*
 * heap.hpp
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
 * TODP :
 * | | - https://www.fluentcpp.com/2018/03/13/heaps-priority-queues-stl-part-1/
 * | | - https://www.geeksforgeeks.org/heap-data-structure/
 */

#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <algorithm>
#include <iostream>
class MinHeap {
	public:
	int size(); // return the size of the heap
	bool empty(); // check if the heap is empty
	void push(int element); //insert an element into the heap
	void push_array(std::vector<int> &array);
	void pop(); //remove element with the lower priority
	int top(); //return element with the lower priority
	
	private:
	std::vector<int> heap; // Pvector to store the heap
	int parent(int index); // return the parent index
	int left_child(int index); // return the left child index
	int right_child(int index); // return the right child index
	void heapify_down(int index); //heapify down
	void heapify_up(int index); // heapify up
};

int MinHeap::parent(int index){
	return (index-1)/2;
}
int MinHeap::left_child(int index){
	return (2*index+1);
}
int MinHeap::right_child(int index){
	return (2*index+2);
}
void MinHeap::heapify_down(int index){
	int left = left_child(index);
	int right = right_child(index);
	
	int smallest = index;
	if(left < size() && heap[left]<heap[index]){
		smallest = left;
	}
	if(right < size() && heap[left]<heap[smallest]){
		smallest = right;
	}	
	if (smallest != index){
		std::swap(heap[index],heap[smallest]);
		heapify_down(smallest);
	}
	
}
void MinHeap::heapify_up(int index){
	if(index && heap[parent(index)] > heap[index]){
		std::swap(heap[index],heap[parent(index)]);
		heapify_up(parent(index));
	}
}

int MinHeap::size(){
	return static_cast<int>(heap.size());
}

bool MinHeap::empty(){
	return size() == 0 ;
}
void MinHeap::push(int element){
	return heap.push_back(element);
	int index = size() - 1;
	heapify_up(index);
}

void MinHeap::pop(){
	try{
		if(size() == 0)
			throw std::out_of_range("Heap<X>::at() : index is out of range");
			
		heap[0] = heap.back();
		heap.pop_back();
		heapify_down(0);
	}
	 catch (const std::out_of_range& oor) {
            std::cout << "\n" << oor.what();
        }
}

int MinHeap::top(){
	try {
		if(size() == 0)
			throw std::out_of_range("Heap<X>::at() : index is out of range");
			
		return heap.at(0);
	}
	catch (const std::out_of_range& oor) {
            std::cout << "\n" << oor.what();
     }
     return -1;
}

void MinHeap::push_array(std::vector<int> &array){
	for(int e : array){
		push(e);
	}
}

#endif // HEAP
