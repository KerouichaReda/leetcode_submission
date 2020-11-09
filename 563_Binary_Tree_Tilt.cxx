/*
 * 563_Binary_Tree_Tilt.cxx
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

#include  "treenode.hpp"


int findTiltUtil(TreeNode* root,int &solution){
	if(root!=nullptr){       
           int left = findTiltUtil(root->left,solution);
           int right = findTiltUtil(root->right,solution);
           solution += std::abs(left-right);
           return left+right+ root->val;        
    }
    return 0;
}

int findTilt(TreeNode* root) {
		int solution=0;
		findTiltUtil(root,solution);
        return solution;
    }

int main(int argc, char **argv)
{
	std::vector<int> array={21,7,14,1,1,2,2,3,3};
	TreeNode *root = createTreeNodeFromArray(array);
	std::cout<<findTilt(root)<<std::endl;
	return 0;
}

