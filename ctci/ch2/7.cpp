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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        
        if (!headA || !headB) return nullptr;
        int count = 0;
        while (ptr1 != ptr2 || count != 3) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;

            if (!ptr1) {
                ptr1 = headB;
                count++;
            } else if (!ptr2) {
                ptr2 = headA;
                count++;
            }
        }

        if (count == 3) {
            return nullptr;
        }
        return ptr1;
    }
};