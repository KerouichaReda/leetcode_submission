/*
 * 19_Remove_Nth_Node_From_End_of_List.cxx
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *p1(head), *p2(head),*p3( head) ;
	int size = 0 ,count = n;
	while(p2 != nullptr){
		if(count > 0){
			count--;
		}else{
			p3 = p1;
			p1 = p1->next; 
		}
		p2 = p2->next;
		size++;
	}
	if(size == n)
		return head->next;  

	if(p1->next != nullptr)
		*p1 =  *p1->next;
	else
		p3->next = nullptr;         
	return head;        
}

int main(int argc, char **argv)
{
	
	return 0;
}

