/*
 * 572_Subtree_of_Another_Tree.cxx
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

bool isSubtree(TreeNode* s, TreeNode* t) {
	if(s == nullptr){
		return false;
	}
	if(s->val == t->val){
		return verify(s,t) || isSubtree( s->left, t) ||  isSubtree( s->right, t);
	}
	return isSubtree( s->left, t) ||  isSubtree( s->right, t) ;
}

bool verify(TreeNode* s, TreeNode* t){
	if(s == nullptr &&  t == nullptr){
		return true;
	}
	if(s == nullptr ||  t == nullptr || s->val != t->val){
		return false;
	}
   return verify(s->left,t->left) && verify(s->right,t->right);
}

int main(int argc, char **argv)
{
	
	return 0;
}

