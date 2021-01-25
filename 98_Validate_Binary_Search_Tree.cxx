/*
 * 98_Validate_Binary_Search_Treecxx
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
#include  <vector>
#include "treenode.hpp"


    int minNode(TreeNode* root){
        return root->left == nullptr?root->val: minNode(root->left);
    }
    int maxNode(TreeNode* root){
        return root->right == nullptr?root->val: maxNode(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return true;
        
        return (root->left ==nullptr?true: root->val > maxNode(root->left))
            && (root->right==nullptr?true: root->val < minNode(root->right))
            && (root->left ==nullptr?true: isValidBST( root->left))
            && (root->right==nullptr?true: isValidBST( root->right));        
    }


int main(int argc, char **argv)
{
	std::vector<int> array;//={1,2,3,4,5};
	for(int i=0;i<7;++i){
		array.push_back(i);
	}
	//array[2] = 4;
	TreeNode * root = createTreeNodeFromSortedArray(array);
	
	preOrderDisplayIter(root);
	std::cout<<'\n'<<isValidBST(root)<<std::endl;
	
	return 0;
}

