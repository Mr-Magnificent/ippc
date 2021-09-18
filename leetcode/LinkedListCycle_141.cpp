#include "../lib/createList.hpp"
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) break;
        }

        if (fast == nullptr || fast->next == nullptr) return false;
        return true;
    }
};
