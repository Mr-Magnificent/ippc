#include "../lib/createList.hpp"
using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode **ptr1 = &head;
        ListNode *ptr = head;
        ListNode **ptr2 = &head;

        for(int i = 1; i < k; ++i) {
            ptr1 = &(*ptr1)->next;
            ptr = ptr->next;
        }

        ptr = ptr->next;

        for(; ptr != nullptr; ptr = ptr->next) {
            ptr2 = &(*ptr2)->next;
        }

        int t = (*ptr1)->val;
        (*ptr1)->val = (*ptr2)->val;
        (*ptr2)->val = t;

        return head;
    }
};