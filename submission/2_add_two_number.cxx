/*
 * 2_add_two_number.cxx
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
 * https://leetcode.com/problems/add-two-numbers/
 */


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {    
	ListNode* result = new ListNode(0);
	ListNode* l3=result;
	int n1,n2,sum = 0;
	int rest = 0;
	while(l1!= nullptr || l2!= nullptr || rest >0)
	{   
		n1 = (l1!= nullptr)?l1->val:0;
		n2 = (l2!= nullptr)?l2->val:0;
		sum = (n1 + n2 +rest) % 10;
		rest = (n1 + n2 +rest) / 10;
		l3->next = new ListNode(sum);            
		l1 = (l1!= nullptr)?l1->next:nullptr;
		l2 = (l2!= nullptr)?l2->next:nullptr;
		l3= l3->next;       
	}
	return result->next;
}

#include <iostream>

int main(int argc, char **argv)
{

	return 0;
}

