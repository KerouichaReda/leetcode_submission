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
 // To Do :
 // |x| - https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
 // |x| - https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/
 // | | - https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : 
			val(x), left(left), right(right) {}
 };
 
 //Declaration
 void preOrderDisplay (TreeNode* root);
 void preOrderDisplayIter (TreeNode* root);
 void inOrderDisplay (TreeNode* root);
 void inOrderDisplayIter (TreeNode* root);
 void postOrderDisplay (TreeNode* root);
 void levelOrderDisplay(TreeNode* root);
 void givenLevelDisplay(TreeNode* root,int level);
 void breadthFirstDisplay(TreeNode* root);
 TreeNode* createTreeNodeFromSortedArrayUtil(std::vector<int> &array,int start, int end);
 TreeNode* createTreeNodeFromSortedArray(std::vector<int> &array);
 int countNodes(TreeNode* root);
 int getHeight(TreeNode *root);
 TreeNode* createTreeNodeFromArrayUtil(std::vector<int> &array,int index,const int end);
 TreeNode* createTreeNodeFromArray(std::vector<int> &array);
 TreeNode* createTreeNodeFromArrayUtil(std::queue<int> &nodesLeft,const int vnull);
 bool isBalanced(TreeNode* root); 
 bool getAncestor(TreeNode* root , TreeNode* target);
 bool getAncestor(TreeNode* root , int target);
 void getLevelNodes(TreeNode* root,int level,std::vector<int> &vec);
 
 int getNodeLevel(TreeNode* root,TreeNode* target,int level);
 int getNodeLevel(TreeNode* root,int target,int level);
 
void preOrderDisplay (TreeNode* root){
	if(root!=nullptr){
		std::cout<<root->val<<" " ;
		preOrderDisplay(root->left);
		preOrderDisplay(root->right);;
	}
}

void inOrderDisplay (TreeNode* root){
	if(root!=nullptr){		
		inOrderDisplay(root->left);
		std::cout<<root->val<<" " ;
		inOrderDisplay(root->right);;
	}
}

void postOrderDisplay (TreeNode* root){
	if(root!=nullptr){		
		postOrderDisplay(root->left);		
		postOrderDisplay(root->right);
		std::cout<<root->val<<" " ;
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
	return createTreeNodeFromArrayUtil(array,index,static_cast<int>(array.size()));
}

TreeNode* createTreeNodeFromArrayUtil(std::queue<int> &nodesLeft,const int vnull){
	
		if(!nodesLeft.empty()){
			
		if(nodesLeft.front()==vnull){
			nodesLeft.pop();
			return nullptr;
		}
		TreeNode* tempTreeNode = new TreeNode(nodesLeft.front()) ;
		nodesLeft.pop();
		
		tempTreeNode->left = createTreeNodeFromArrayUtil(nodesLeft,vnull);		
		tempTreeNode->right = createTreeNodeFromArrayUtil(nodesLeft,vnull);
		return tempTreeNode;
	}
	return nullptr;
}

TreeNode* createTreeNodeFromArray(std::vector<int> &array,const int vnull){
	
	std::queue<int> nodesLeft;
	for(int n: array){
		nodesLeft.push(n);
	}
		
	return createTreeNodeFromArrayUtil(nodesLeft,vnull);
}

bool isBalanced(TreeNode* root) {
	if(root!=nullptr){     
		return isBalanced(root->left) and isBalanced(root->right) and 
		std::abs(getHeight(root->left)-getHeight(root->right))<=1;
	}
	return true;
}

 void levelOrderDisplay(TreeNode* root){
	 int height = getHeight(root);
	 for(int i=1; i<=height;++i){
		givenLevelDisplay(root,i);
	 }
	 
 }
 
 void givenLevelDisplay(TreeNode* root,int level){
	 if(root !=nullptr){
		if(level == 1){
			std::cout<<root->val<<" ";
		}else {
			givenLevelDisplay(root->left,level-1);
			givenLevelDisplay(root->right,level-1);
		}
	 }	
 }
 
 void breadthFirstDisplay(TreeNode* root) {
	 if(root!=nullptr){	
		std::queue<TreeNode*> q;
		TreeNode* temp;
		q.push(root);
		while(!q.empty()){
			temp = q.front();
			q.pop();
			std::cout<<temp->val<<" ";
			if(temp->left != nullptr){
				q.push(temp->left);
			}
			if(temp->right != nullptr){
				q.push(temp->right);
			}
		}
		std::cout<<std::endl;
	}
}

bool getAncestor(TreeNode* root , TreeNode* target){
	if(root==nullptr){
		return false;
	}else if (root == target){
		return true;
	}
	
	if (getAncestor(root->left,target) || getAncestor(root->right,target)){
		std::cout<<root->val<<" ";
		return true;
	}
	return false;
}
bool getAncestor(TreeNode* root , int target){
	if(root==nullptr){
		return false;
	}else if (root->val == target){
		return true;
	}
	
	if (getAncestor(root->left,target) || getAncestor(root->right,target)){
		std::cout<<root->val<<" ";
		return true;
	}
	return false;
}
void getLevelNodes(TreeNode* root,int level,std::vector<int> &vec){
	if(root!=nullptr){
		if(level==1){
			vec.push_back(root->val);
		}
		else {
			getLevelNodes(root->left,level-1,vec);
			getLevelNodes(root->right,level-1,vec);
		}
	}
}

int getNodeLevel(TreeNode* root,TreeNode* target,int level=1){
	if(root !=nullptr){
		if(root==target){
			return level;
		}
		else{
			return getNodeLevel(root->left,target, level+1)+
			getNodeLevel(root->right,target, level+1);
		}		
	}
	return 0;
}

int getNodeLevel(TreeNode* root,int target,int level=1){
	if(root != nullptr){
		if(root->val==target){
			return level;
		}
		else{
			return getNodeLevel(root->left,target, level+1)+
			getNodeLevel(root->right,target, level+1);
		}		
	}
	return 0;
}

void inOrderDisplayIter (TreeNode* root){
	std::stack<TreeNode*> q;
	TreeNode* temp = root;
	
	while (temp!=nullptr || !q.empty()){		
		while(temp!=nullptr){
			q.push(temp);
			temp=temp->left;
		}
		temp = q.top();
		q.pop();
		std::cout << temp->val << " ";
		temp= temp->right;
		
	}
 }
 
void preOrderDisplayIter (TreeNode* root){
	std::stack<TreeNode*> q ;
	TreeNode* temp = root ;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.top();
		q.pop();
		std::cout << temp->val << " ";		
		if(temp->right != nullptr) q.push(temp->right);
		if(temp->left != nullptr) q.push(temp->left);
	}
}
#endif // TREENODE
