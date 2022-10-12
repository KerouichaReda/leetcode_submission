
#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    ListNode(std::vector<int> vec) {
        val = vec[0];
        ListNode* current = this;
        for (size_t i = 1, end = vec.size(); i < end; ++i) {
            current->next = new ListNode(vec[i]);
            current = current->next;
        }
    }
};

ListNode* partition(ListNode* current, int x) {
    ListNode bucket[2] = {};  // array initialization
    ListNode* temp[2] = {bucket, bucket + 1};
    while (current != nullptr) {
        int index = current->val >= x;  //{0,1}
        temp[index]->next = current;
        temp[index] = temp[index]->next;
        current = current->next;
    }
    if (bucket[0].next == nullptr || bucket[1].next == nullptr) {
        return bucket[0].next == nullptr ? bucket[1].next : bucket[0].next;
    }
    temp[1]->next = nullptr;
    temp[0]->next = bucket[1].next;
    return bucket[0].next;
}
void disp(ListNode* current) {
    while (current != nullptr) {
        std::cout << current->val << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char const* argv[]) {
    ListNode* head = new ListNode({1, 2, 3, 6, 7, 5, 6, 9});
    int x = 3;
    ListNode* partionned = partition(head, x);
    disp(partionned);
    return 0;
}
