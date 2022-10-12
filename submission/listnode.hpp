/*
 * utility.hpp
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
 
 #ifndef LISTNODE_HPP
 #define LISTNODE_HPP


#include <iostream>
#include <vector>
#include <unordered_map>


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode * createListFromArray(std::vector<int> array){
	ListNode *rootNode 	= nullptr;
	ListNode *ptrNode	= nullptr;
	ListNode *lastNode	= nullptr;
	
	int length=(int)array.size();
	for(int i=0;i<length;++i){
		if(ptrNode==nullptr){
			ptrNode = new ListNode(array[i]);
			if(rootNode==nullptr){
				rootNode=ptrNode;
			}
			if(lastNode!=nullptr){
				lastNode->next=ptrNode;
			}			
		}
		lastNode =	ptrNode;
		ptrNode  = 	nullptr;
	}
		 
    return rootNode;	
}

void displayList(ListNode* root){
	while(root!=nullptr){
		std::cout<<root->val<<" ";
		root=root->next;
	}
	std::cout<<std::endl;
}
//21. Merge Two Sorted Lists
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if(l1==nullptr && l2==nullptr)	return nullptr;
	if(l1==nullptr)	return l2;
	if(l2==nullptr)	return l1;
	
	ListNode *rootListNode=nullptr;
	ListNode *ptrListNode;
	
	while(l1!=nullptr or l2!=nullptr){
		if(rootListNode==nullptr){
			if(l1->val<l2->val){
				rootListNode = new ListNode(l1->val);
				l1=l1->next;
			}
			else{
				rootListNode = new ListNode(l2->val);
				l2=l2->next;
			}
			ptrListNode=rootListNode;
		}
		else{
			if(	l2==nullptr){
				ptrListNode->next = new ListNode (l1->val);
				l1=l1->next;
				ptrListNode=ptrListNode->next;
			}
			else if (l1==nullptr) {
				ptrListNode->next = new ListNode (l2->val);
				l2=l2->next;
				ptrListNode=ptrListNode->next;
			}
			else if (l1->val<l2->val){
				ptrListNode->next = new ListNode (l1->val);
				l1=l1->next;
				ptrListNode=ptrListNode->next;
			}
			else if (l1->val>=l2->val){
				ptrListNode->next = new ListNode (l2->val);
				l2=l2->next;
				ptrListNode=ptrListNode->next;
			}			
		}
	}
	return rootListNode;        
}

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

#endif //LISTNODE
