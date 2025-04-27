/*
 * 147_Insertion_Sort_List.cxx
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

#include "utility.hpp"

ListNode* insertionSortList(ListNode* head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode* newList = new ListNode(head->val);
    ListNode* newNode;
    ListNode* ptrNode;
    head = head->next;
    while (head != nullptr) {
        // std::cout<<head->val<<" ";
        if (head->val <= newList->val) {
            newNode = new ListNode(head->val, newList);
            newList = newNode;
        } else {
            ptrNode = newList;
            while (ptrNode->next != nullptr) {
                if (ptrNode->next->val >= head->val) break;
                ptrNode = ptrNode->next;
            }
            newNode = new ListNode(head->val, ptrNode->next);
            ptrNode->next = newNode;
        }
        head = head->next;
    }
    return newList;
}

int main(int argc, char** argv) {
    std::vector<int> array = {-1, 5, 3, 4, 0};

    ListNode* root = createListFromArray(array);
    ListNode* sorted = insertionSortList(root);

    displayList(root);
    displayList(sorted);
    return 0;
}
