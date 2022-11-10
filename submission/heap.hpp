/*
 * Heap<E >.hpp
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
 * | | - https://www.fluentcpp.com/2018/03/13/Heap<E
 * >s-priority-queues-stl-part-1/
 * | | - https://www.geeksforgeeks.org/Heap-data-structure/
 * https://www.cc.gatech.edu/classes/cs3158_98_fall/heapsort.html
 * http://faculty.cs.niu.edu/~freedman/340/340notes/340heap.htm
 *
 */

#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>

template <typename E>
class Heap {
   public:
    Heap(E* h, int num, int max);  // Constructor
    int size();
    bool isLeaf(int pos);
    int left_child(int pos);
    int right_child(int pos);
    int parent(int pos);
    void buildHeap();
    void insert(const E& it);
    E removeFirst();
    E removeAt(int pos);
    bool empty();
    void display_heap();

   private:
    E* heap;  // Pointer to the Heap<E > array
    int maxsize;  // Maximum size of the Heap<E>
    int n;  // number of elements
    void shiftdown(int pos);
    bool prior(int a, int b);
};
class MinHeap {
    MinHeap(std::vector<int> h);

   private:
    std::vector<int> heap;
    int n;  // number elements
}

template <typename E>
Heap<E>::Heap(E* h, int num, int max) {
    heap = h;
    n = num;
    maxsize = max;
    buildHeap();
}
template <typename E>
bool Heap<E>::prior(int a, int b) {
    return a < b;
}
template <typename E>
void Heap<E>::shiftdown(int pos) {
    while (!isLeaf(pos)) {
        int j = left_child(pos);
        int rc = right_child(pos);
        if ((rc < n) && prior(heap[rc], heap[j])) {
            j = rc;  // Set j to greater child's value
        }
        if (prior(heap[pos], heap[j])) return;
        std::swap(heap[pos], heap[j]);
        pos = j;  // Move down
    }
}
template <typename E>
int Heap<E>::parent(int pos) {
    return (pos - 1) / 2;
}
template <typename E>
int Heap<E>::left_child(int pos) {
    return (2 * pos + 1);
}
template <typename E>
int Heap<E>::right_child(int pos) {
    return (2 * pos + 2);
}
template <typename E>
int Heap<E>::size() {
    return n;
}
template <typename E>
bool Heap<E>::empty() {
    return n == 0;
}
template <typename E>
bool Heap<E>::isLeaf(int pos) {
    return (pos >= n / 2) && pos < n;
}
template <typename E>
void Heap<E>::buildHeap() {
    for (int i = n / 2 - 1; i >= 0; --i) {
        shiftdown(i);
    }
}
template <typename E>
void Heap<E>::insert(const E& it) {
    assert((n < maxsize) && "Heap is full");
    int curr = n++;
    heap[curr] = it;

    while ((curr != 0) && (prior(heap[curr], heap[parent(curr)]))) {
        std::swap(heap[curr], heap[parent(curr)]);
        curr = parent(curr);
    }
}

template <typename E>
E Heap<E>::removeFirst() {
    assert((n > 0) && "Heap is empty");
    std::swap(heap[0], heap[--n]);
    if (n != 0) shiftdown(0);
    return heap[n];
}
template <typename E>
E Heap<E>::removeAt(int pos) {
    assert((pos >= 0) && (pos < n) && "Heap is empty");
    if (pos == (n - 1))
        n--;
    else {
        swap(heap, pos, --n);
        while ((pos != 0) && (prior(heap[pos], heap[parent(pos)]))) {
            swap(heap, pos, parent(pos));
            pos = parent(pos);
        }
        if (n != 0) shiftdown(pos);
    }
    return heap[n];
}
template <typename E>
void Heap<E>::display_heap() {
    for (int i = 0; i < 10; ++i) {
        std::cout << heap[i] << " ";
    }
    std::cout << std::endl;
}

#endif  // Heap
