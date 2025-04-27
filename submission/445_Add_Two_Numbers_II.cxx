/*
 * 445_Add_Two_Numbers_II.cxx
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

#include "listnode.hpp"

ListNode* reverse(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* pre = nullptr;
    ListNode* next;
    while (head != nullptr) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr || l2 == nullptr) return l1 == nullptr ? l1 : l2;
    ListNode solution(0);
    ListNode* curr = &solution;
    l1 = reverse(l1);
    l2 = reverse(l2);
    int rem = 0, n1, n2;
    while (l1 != nullptr || l2 != nullptr || rem) {
        if (l1 != nullptr) {
            n1 = l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            n2 = l2->val;
            l2 = l2->next;
        }
        curr->next = new ListNode((rem + n1 + n2) % 10);
        curr = curr->next;
        rem = (rem + n1 + n2) / 10;
        n1 = 0;
        n2 = 0;
    }
    return reverse(solution.next);
}
int main(int argc, char** argv) { return 0; }
