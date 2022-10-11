/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/

532. K-diff Pairs in an Array
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
    0 <= i < j < nums.length
    |nums[i] - nums[j]| == k
Notice that |val| denotes the absolute value of val.
*/
#include <iostream>
#include <vector>
#include <unordered_map>


int findPairs(std::vector<int>& nums, int k) {
	// 
	int solution{};
	std::unordered_map<int,int> m;
	
	for(int i = nums.size() -1 ; i >= 0 ; i--){
		solution += m[k-nums[i]] + m[k+nums[i]] ;
		m[nums[i]]++;
		
	}		
	return solution;
}	
	
	
int main(){
	std::vector<int> nums = {1,2,3,4,5};
	int k = 1;
	
	std::cout << findPairs(nums, k ) << std::endl;
	
	return 0;
}
