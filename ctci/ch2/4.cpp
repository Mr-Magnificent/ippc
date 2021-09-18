#include <bits/stdc++.h>
using namespace std;


// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* sHead = nullptr;
        ListNode* sTail = nullptr;
        ListNode* lHead = nullptr;
        ListNode* lTail = nullptr;

        for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
            if (ptr->val < x) {
                if (sHead == nullptr) {
                    sHead = sTail = ptr;
                } else {
                    sTail->next = ptr;
                    sTail = sTail->next;
                }
            } else {
                if (lHead == nullptr) {
                    lHead = lTail = ptr;
                } else {
                    lTail->next = ptr;
                    lTail = lTail->next;
                }
            }
        }
        
        if (lHead != nullptr) {
            lTail->next = nullptr;
        }
        
        if (sHead != nullptr) {
            sTail->next = lHead;
            return sHead;
        }
        return lHead;
    }
};