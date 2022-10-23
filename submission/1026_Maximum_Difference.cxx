/*
 * 1026_Maximum_Difference.cxx
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
#include <vector>
#include <algorithm>

#include "treenode.hpp"

int maxAncestorDiff(TreeNode* root, int minNode = 100001, int maxNode = -1){    
    if(root!=nullptr){		
        return std::max(
            maxAncestorDiff(root->left , std::min(minNode, root->val), std::max(maxNode, root->val)),
            maxAncestorDiff(root->right, std::min(minNode, root->val), std::max(maxNode, root->val))
        );
	}	
	return  maxNode - minNode;
}

int main(int argc, char **argv)
{
	std::vector<int> array = {1,2,3,4,5};
	TreeNode* root = createTreeNodeFromArray(array);
	std::cout<< maxAncestorDiff(root)<<std::endl;
	return 0;
}

