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
 
 #ifndef UTILITY_HPP
 #define UTILITY_HPP


#include <iostream>
#include <vector>


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

#endif
