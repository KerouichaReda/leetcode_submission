#include <iostream>
#include <vector>
#include <queue>

class KthLargest{
public:
    KthLargest(int k, std::vector<int>& nums) : pq(nums.begin(), nums.end()), kth(k) {
        while(pq.size() > kth){
            pq.pop();
        }
    }
    int add(int val){
        pq.push(val);
        if(pq.size() > kth){
            pq.pop();
        }
        return pq.top();
    }
private:
    std::priority_queue<int,std::vector<int>, std::greater<int>> pq;
    int kth; // kth biggest value
};


int main(){
    std::vector<int> nums{4, 5, 8, 2};
    std::vector<int> push{3, 5, 10, 9, 4};
    int k{3};
    KthLargest kl(k,nums);
    for(int& e : push){
        std::cout << kl.add(e) << std::endl;
    }

    return EXIT_SUCCESS;
}
