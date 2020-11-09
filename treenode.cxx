/*
 * treenode.cxx
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
#include "treenode.hpp"

#include <iostream>



int main(int argc, char **argv)
{
	//TreeNode * left =  new TreeNode(1);
	//TreeNode * right = new TreeNode(3);
	//TreeNode * root = new TreeNode(2,left,right);
	std::vector<int> sortedArray={1,2,3,4,5};
	//int vnull=-1;
	//std::vector<int> array={0,1,vnull,vnull,2,3,vnull,vnull,4};
	
	//TreeNode *root2 = createTreeNodeFromSortedArray(sortedArray);
	TreeNode *root2 = createTreeNodeFromArray(sortedArray);
	/*std::cout<<std::endl;
	preOrderDisplay(root);
	std::cout<<std::endl;
	preOrderDisplay(root2);
	std::cout<<std::endl;*/
	inOrderDisplay(root2);
	std::cout<<std::endl;
	preOrderDisplay(root2);
	std::cout<<std::endl;
	postOrderDisplay(root2);
	std::cout<<std::endl;
	levelOrderDisplay(root2);
	std::cout<<std::endl;
	breadthFirstDisplay(root2);
	//std::cout<<countNodes(root3)<<std::endl;
	std::cout<<getHeight(root2)<<std::endl;
	return 0;
}

