/*
 * 641_design_circular_deque.cxx
 *
 * Copyright 2024 - present RedaKerouicha <reda_kerouicha@outlook.com>
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
#include <set>
#include <string>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

class MyCircularDeque {
   public:
    MyCircularDeque(int capacity) : capacity_(capacity), deque_(new int[capacity]), front_(capacity - 1) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        deque_[front_] = value;
        front_ = (front_ - 1 + capacity_) % capacity_;
        size_++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        deque_[back_] = value;
        back_ = (back_ + 1 + capacity_) % capacity_;
        size_++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front_ = (front_ + 1 + capacity_) % capacity_;
        size_--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        back_ = (back_ - 1 + capacity_) % capacity_;
        size_--;
        return true;
    }

    int getFront() { return isEmpty() ? -1 : deque_[(front_ + 1 + capacity_) % capacity_]; }

    int getRear() { return isEmpty() ? -1 : deque_[(back_ - 1 + capacity_) % capacity_]; }

    bool isEmpty() { return size_ == 0; }

    bool isFull() { return size_ == capacity_; }

   private:
    int capacity_;
    int* deque_{nullptr};
    int front_;
    int back_{};
    int size_{};
};

int main(int argc, char** argv) { return 0; }
