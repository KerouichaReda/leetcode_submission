
#include "listnode.hpp"
#include <vector>
void reorderList(ListNode* head) {
    std::vector<ListNode*> s;
    ListNode* curr = head;
    while (curr != nullptr) {
        s.push_back(curr);
        curr = curr->next;
    };
    if (s.size() < 3) return;
    std::size_t size = s.size() / 2;
    for (int i = 0; i < size; i++) {
        s[i]->next = s.back();
        s.back()->next = s[i + 1];
        s.pop_back();
    }
    s[size % 2 == 0 ? size : s.size() - 1]->next = nullptr;
    return;
}

int main(int argc, char const* argv[]) {
    ListNode* head = createListFromArray(std::vector<int>{1, 2, 3, 4});
    reorderList(head);
    return 0;
}
