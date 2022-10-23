/*
 * 142_Linked_List_Cycle_II.cxx
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

ListNode *detectCycle(ListNode *head) {
	if(head==nullptr){
		return nullptr;
	}
	std::unordered_map<ListNode *,int> my_list;
	ListNode *p=head;
	while(p->next !=nullptr){
		if(my_list.find(p->next)!=my_list.end()){
			return p->next;
		}
		else{
			my_list.insert({p,0});
			p=p->next;
		}
	}        
	return nullptr;        
}

int main(int argc, char **argv)
{
	
	return 0;
}

