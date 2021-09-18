#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *newHead = new ListNode();
        ListNode *ptr = newHead;

        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr) {
            while (fast && fast->val == slow->val) {
                fast = fast->next;
            }
            if (slow->next == fast) {
                ptr->next = slow;
                ptr = ptr->next;
            }
            slow = fast;
        }
        return newHead->next;
    }
};