/*
 * 61_Rotate_List.cxx
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode* rotateRight(ListNode* head, int k) {
    if (head == nullptr) return head;
    std::vector<ListNode*> list;
    ListNode* p = head;
    int size = 0;
    int rot;
    while (p != nullptr) {
        list.push_back(p);
        p = p->next;
        size++;
    }
    rot = k % size;
    if (rot != 0) {
        list[size - 1]->next = list[0];
        list[(size - rot - 1) % size]->next = nullptr;
    }
    return list[(size - rot) % size];
}

int main(int argc, char** argv) { return 0; }
