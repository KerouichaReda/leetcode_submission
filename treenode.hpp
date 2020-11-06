/*
 * treenode.hpp
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
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>
#include <vector>
#include <algorithm>




 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
 
void preOrderDisplayRecursive (TreeNode* root){
	if(root!=nullptr){
		std::cout<<root->val<<" " ;
		preOrderDisplayRecursive(root->left);
		preOrderDisplayRecursive(root->right);;
	}
}
TreeNode* createTreeNodeFromSortedArrayUtil(std::vector<int> &array,int start, int end){
		if(end<=start){
			return nullptr;
		}
		int mid = (start+end)/2;
		TreeNode* tempTreeNode = new TreeNode (array[mid]);
		tempTreeNode->left = createTreeNodeFromSortedArrayUtil(array,start,mid);
		tempTreeNode->right = createTreeNodeFromSortedArrayUtil(array,mid+1,end);
		return tempTreeNode;
}

TreeNode* createTreeNodeFromSortedArray(std::vector<int> &array){
	return createTreeNodeFromSortedArrayUtil(array,0,(int)array.size());
}

int countNodes(TreeNode* root){
	
	if(root!=nullptr){
		return 1+countNodes(root->left)+countNodes(root->right);
	}
	return 0;
}

int getHeight(TreeNode *root){	
	if(root!=nullptr){		
		return 1+ std::max(getHeight(root->left),getHeight(root->right));	
	}
	return 0;
}
TreeNode* createTreeNodeFromArrayUtil(std::vector<int> &array,int index,const int end){
	if(index>=end){
		return nullptr;
	}
	TreeNode* tempTreeNode = new TreeNode (array[index]);
	
	tempTreeNode->left = createTreeNodeFromArrayUtil(array,2*index+1,end);	
	tempTreeNode->right = createTreeNodeFromArrayUtil(array,2*index+2,end);
	return tempTreeNode;
}

TreeNode* createTreeNodeFromArray(std::vector<int> &array){
	int index = 0;
	return createTreeNodeFromArrayUtil(array,index,(int)array.size());
}


bool isBalanced(TreeNode* root) {
if(root!=nullptr){     
		return isBalanced(root->left) and isBalanced(root->right) and std::abs(getHeight(root->left)-getHeight(root->right))<=1;
	}
	return true;
}


#endif // TREENODE
