#include "../lib/createList.hpp"
using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode h1(0), h2(0);
        ListNode *ptr1 = &h1;
        ListNode *ptr2 = &h2;

        while (head != nullptr) {
            if (head->val < x) {
                ptr1->next = head;
                ptr1 = head;
            } else {
                ptr2->next = head;
                ptr2 = head;
            }
            head = head->next;
        }

        ptr2->next = nullptr;
        ptr1->next = h2.next;
        return h1.next;
    }
};
