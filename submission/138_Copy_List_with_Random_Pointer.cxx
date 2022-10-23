/*
 * 138_Copy_List_with_Random_Pointer.cxx
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
#include <unordored_map>
struct Node {

    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {
	if(head == nullptr)
		return nullptr;
	std::unordered_map<Node*,Node*> m;
	Node* p = head;
	Node* newHead = new Node(0);
	Node* t = newHead;
	while(p != nullptr){
		t->next = new Node(p->val);
		m[p] = t->next;
		t= t->next;
		p=p->next;            
	}
	t=newHead->next;
	p=head;
	while(p!=nullptr){
		t->random = m[p->random];
		t = t->next;
		p = p->next;
	}
	return newHead->next;
}

int main(int argc, char **argv)
{
	
	return 0;
}

