#include <iostream>
#include <vector>

void merge_sort(std::vector<int>& nums , std::vector<int>& temp , int left , int right){
    if(left >= right) return;
    int mid = (left + right)/2;
    merge_sort(nums,temp,left, mid);
    merge_sort(nums,temp,mid+1, right);

    for(int i = left; i <= right; i++){
        temp[i] = nums[i];
    }
    int i1 = left;
    int i2 = mid + 1;

    for(int curr = left; curr <= right; curr++){
        if( i1 >= mid + 1){
            nums[curr] = temp[i2++];
        }else if (i2 > right){
            nums[curr] = temp[i1++];
        }else if(temp[i1] < temp[i2]){
            nums[curr] = temp[i1++];
        }else{
            nums[curr] = temp[i2++];
        }
    }

    
}
std::vector<int> sortArray(std::vector<int>& nums) {
    std::vector<int> array(nums.begin(), nums.end());
    std::vector<int> temp(nums.size());
    merge_sort(array,temp,0, nums.size()-1);
    return array;
}

void display_vector(std::vector<int>& array){
    for (int e : array){
        std::cout << e << " ";
    }
    std::cout << std::endl;    
}
    
int main(){
    std::vector<int> nums = {2,0,1,0};
    std::vector<int> sorted = sortArray(nums);
    display_vector(sorted);
    return EXIT_SUCCESS;
}