
/*

560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


*/

#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(vector<int>& nums, int k) {
	int solution{};
	
	for(int i = nums.size() -1 ; i >= 0 ;i++){
		solution += nums[i] == k;
		int temp = nums[i];
		int sub = 0;
		while (m.count(k-temp) && temp>0)
			temp = k- temp;
			sub += m[temp];
		}
		solution += (temp ==0)? sub : 0;
	}
	
	return solution;
}

int main() {


	return 0;

}