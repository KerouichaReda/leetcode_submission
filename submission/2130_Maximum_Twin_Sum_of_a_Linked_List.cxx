#include "listnode.hpp"
#include <iostream>
int pairSum(ListNode* head) {
    int solution{0};
    ListNode* current = head;
    ListNode* fast = head;
    ListNode* next = head;
    ListNode* pre = nullptr;
    while (fast != nullptr) {
        fast = fast->next->next;
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    while (current != nullptr) {
        solution = std::max(solution, current->val + pre->val);
        current = current->next;
        pre = pre->next;
    }

    return solution;
}

int main(int argc, char const* argv[]) {
    std::cout << pairSum(new ListNode(1, new ListNode(2))) << std::endl;
    return 0;
}
