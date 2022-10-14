#include "listnode.hpp"

ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* temp = nullptr;
    while (fast != nullptr) {
        if (fast->next == nullptr) break;
        fast = fast->next->next;
        temp = slow;
        slow = slow->next;
    }
    temp->next = temp->next->next;
    return head;
}