#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// class Solution {
// public:
//     void reorderList(ListNode* head) {
//         stack<ListNode *> stk;

//         ListNode *ptr = head;
//         while (ptr) {
//             stk.push(ptr);
//             ptr = ptr->next;
//         }

//         int len = stk.size();
//         len = len / 2;
//         ptr = head;

//         while (len--) {
//             ListNode *next = ptr->next;
//             ptr->next = stk.top();
//             stk.top()->next = next;
            

//             stk.pop();
//             ptr = next;
//         }
        

//         ptr->next = nullptr;
//     }
// };

class Solution {
    ListNode *reverse(ListNode *node) {
        ListNode *prev, *curr, *next;

        prev = nullptr, curr = node, next = node;
        while(curr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
    
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head, *prev;

        while (fast && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        prev->next = nullptr;

        slow = reverse(slow);

        ListNode *ptr = head;
        while(ptr && slow) {
            ListNode *next = ptr->next;
            ListNode *temp = slow->next;
            ptr->next = slow;
            slow->next = next;

            ptr = next, slow = temp;
        }

        return;
    }
};