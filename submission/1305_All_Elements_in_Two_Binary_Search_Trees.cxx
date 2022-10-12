/*
 * 1305_All_Elements_in_Two_Binary_Search_Trees.cxx
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
 * https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
 */


#include <iostream>
#include <vector>
#include <algorithm>
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/*
 * void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
    while (n != nullptr) 
        s.push(exchange(n, n->left));
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> res;
    stack<TreeNode*> s1, s2;
    pushLeft(s1, root1);
    pushLeft(s2, root2);
    while (!s1.empty() || !s2.empty()) {
        stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : 
							s1.top()->val < s2.top()->val ? s1 : s2;
        auto n = s.top(); s.pop();
        res.push_back(n->val);
        pushLeft(s, n->right);
    }
    return res;
}
*/

void dispTree(TreeNode *p)
{
	std::cout<<(*p).val<<" ";
	if((*p).left!=nullptr)
	dispTree((*p).left);
	if((*p).right!=nullptr)
	dispTree((*p).right);
}

void Tree2Vec(TreeNode *p,std::vector<int> &vec)
{
	vec.push_back((*p).val);
	if((*p).left!=nullptr)
	Tree2Vec((*p).left,vec);
	if((*p).right!=nullptr)
	Tree2Vec((*p).right,vec);
}

std::vector<int> MergeSortedVectors(std::vector<int>& v1, std::vector<int>& v2) {

	// v3 is the output vector
	// it will store the merged vector obtained by merging v1 and v2
	std::vector<int> v3;

	int i, j, n, m;
	i = j = 0;
	n = v1.size();
	m = v2.size();


	// traverse each elemenst of v1 and v2
	while (i < n && j < m) {

		// comparing v1[i] and v2[j]
		// if v1[i] is smaller than v2[j]
		// push v1[i] to v3 and increment i
		// if v[i] is less than v2[j]
		// push v2[j] to v3 and increment j
		if (v1[i] <= v2[j]) {
			v3.push_back(v1[i]);
			++i;
		}
		else {
			v3.push_back(v2[j]);
			++j;
		}

	}

	// push the elements left in v1 to v3
	while (i < n) {
		v3.push_back(v1[i]);
		++i;
	}

	// push the elements left in v2 to v3
	while (j < m) {
		v3.push_back(v2[j]);
		++j;
	}

	return v3;

}

int main(int argc, char **argv)
{
	TreeNode *leftnode1 = new TreeNode(1,nullptr,nullptr);
	TreeNode *rightnode1 = new TreeNode(4,nullptr,nullptr);
	TreeNode *rootnode1 = new TreeNode(2,leftnode1,rightnode1);
	
	TreeNode *leftnode2 = new TreeNode(3,nullptr,nullptr);
	TreeNode *rightnode2 = new TreeNode(0,nullptr,nullptr);
	TreeNode *rootnode2 = new TreeNode(1,leftnode2,rightnode2);
	
	std::vector<int> vec1,vec2,vec3;
	Tree2Vec(rootnode1,vec1);
	Tree2Vec(rootnode2,vec2);
	std::sort(vec1.begin(), vec1.end());
	std::sort(vec2.begin(), vec2.end());
	vec3=MergeSortedVectors(vec1,vec2);
	dispTree(rootnode1);
	std::cout<<std::endl;
	dispTree(rootnode2);
	std::cout<<std::endl;
	
	for (int i = 0; i < (int)vec1.size(); i++)
	{
		std::cout<<vec1[i]<<" ";
	}
	std::cout<<std::endl;
	
	for (int i = 0; i < (int)vec2.size(); i++)
	{
		std::cout<<vec2[i]<<" ";
	}
	std::cout<<std::endl;
	
	for (int i = 0; i < (int)vec3.size(); i++)
	{
		std::cout<<vec3[i]<<" ";
	}
	std::cout<<std::endl;
	
	
	
	
	return 0;
}

